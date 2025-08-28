// myextension.cpp
// Extension lib defines
#include "dmsdk/dlib/sys.h"
#include "dmsdk/script/script.h"
#include <cstdint>
#include <cstdio>
#include <cstring>
#define LIB_NAME "zipper"
#define MODULE_NAME "zipper"
#include "defoldsdk/zip.h"
#include "defoldsdk/lz4.h"
#include "string.h"
#include "dmsdk/sdk.h"

#include "sys.h"

static int StoreZip(lua_State* L) {
    DM_LUA_STACK_CHECK(L, 0);
    char * filename = (char *) luaL_checkstring(L, 1);
    char * application_name = (char *) luaL_checkstring(L, 2);

    dmZip::HZip zip;
    dmZip::Result res = dmZip::Open(filename, &zip);
    uint32_t numentries =  dmZip::GetNumEntries(zip);
    uint32_t largest_entry =  0;
    for (int i=0; i < numentries; i++) {
        dmZip::OpenEntry(zip, i);
        uint32_t size;
        dmZip::GetEntrySize(zip, &size);
        if (largest_entry < size) {
            largest_entry = size;
        }
        dmZip::CloseEntry(zip);
    }

    uint8_t *raw_data = new uint8_t[largest_entry];
    char app_save_path[1024];
    char fullfile[sizeof(app_save_path) * 2];
    if(dmSys::GetApplicationSavePath(application_name, app_save_path, sizeof(app_save_path)) != dmSys::RESULT_OK) {
      DM_LUA_ERROR("could not get application save path");
    }
    printf("save path %s\n", app_save_path);
    for (int i=0; i < numentries; i++) {
        dmZip::OpenEntry(zip, i);
        uint32_t size;
        dmZip::GetEntrySize(zip, &size);
        dmZip::GetEntryData(zip, raw_data, size);
        int decompressed_size;
        dmLZ4::Result r = dmLZ4::DecompressBuffer(raw_data, size, raw_data, size, &decompressed_size);
        if (r != dmLZ4::RESULT_OK) {
            // throw
            DM_LUA_ERROR("could not decompress buffer");
        }
        const char *filename = dmZip::GetEntryName(zip);
        uint32_t hash = dmHashString64(dmZip::GetEntryName(zip));
        snprintf(fullfile, sizeof(fullfile), "%s/%x", app_save_path, hash);
        printf("%s\n", fullfile);
        FILE *file = fopen(fullfile, "wb");
        fwrite(raw_data, 1, size, file);
        fclose(file);
        dmZip::CloseEntry(zip);
        memset(raw_data, 0x0, largest_entry);
    }
    delete[] raw_data;
    dmLogInfo("res: %d %d", res, numentries);
    return 0;
}

// Functions exposed to Lua
static const luaL_reg Module_methods[] =
{
    {"storezip", StoreZip},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);

    // Register lua names
    luaL_register(L, MODULE_NAME, Module_methods);

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

// Defold SDK uses a macro for setting up extension entry points:
//
// DM_DECLARE_EXTENSION(symbol, name, app_init, app_final, init, update, on_event, final)

// MyExtension is the C++ symbol that holds all relevant extension data.
// It must match the name field in the `ext.manifest`
DM_DECLARE_EXTENSION(zipper, LIB_NAME, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0);
