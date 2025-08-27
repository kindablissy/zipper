// myextension.cpp
// Extension lib defines
#include <cstdint>
#include <sys/stat.h>
#include <cstdio>
#include <cstring>
#define LIB_NAME "zipper"
#define MODULE_NAME "zipper"
#include "zip.h"
#include "lz4.h"
#include "string.h"

// include the Defold SDK
#include <dmsdk/sdk.h>
#include "sys.h"

static int Reverse(lua_State* L)
{
    // The number of expected items to be on the Lua stack
    // once this struct goes out of scope
    DM_LUA_STACK_CHECK(L, 1);

    // Check and get parameter string from stack
    char* str = (char*)luaL_checkstring(L, 1);

    // Reverse the string
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        const char a = str[i];
        const char b = str[len - i - 1];
        str[i] = b;
        str[len - i - 1] = a;
    }

    // Put the reverse string on the stack
    lua_pushstring(L, str);

    // Return 1 item
    return 1;
}

static int loadzip(lua_State* L) {
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
    dmSys::GetApplicationSavePath(application_name, app_save_path, sizeof(app_save_path));
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
    {"reverse", Reverse},
    {"loadzip", loadzip},
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

static dmExtension::Result AppInitializeMyExtension(dmExtension::AppParams* params)
{
    dmLogInfo("AppInitializeMyExtension");
    return dmExtension::RESULT_OK;
}

static dmExtension::Result InitializeMyExtension(dmExtension::Params* params)
{
    // Init Lua
    LuaInit(params->m_L);
    dmLogInfo("Registered %s Extension", MODULE_NAME);
    return dmExtension::RESULT_OK;
}

static dmExtension::Result AppFinalizeMyExtension(dmExtension::AppParams* params)
{
    dmLogInfo("AppFinalizeMyExtension");
    return dmExtension::RESULT_OK;
}

static dmExtension::Result FinalizeMyExtension(dmExtension::Params* params)
{
    dmLogInfo("FinalizeMyExtension");
    return dmExtension::RESULT_OK;
}

static dmExtension::Result OnUpdateMyExtension(dmExtension::Params* params)
{
    dmLogInfo("OnUpdateMyExtension");
    return dmExtension::RESULT_OK;
}

static void OnEventMyExtension(dmExtension::Params* params, const dmExtension::Event* event)
{
    switch(event->m_Event)
    {
        case dmExtension::EVENT_ID_ACTIVATEAPP:
            dmLogInfo("OnEventMyExtension - EVENT_ID_ACTIVATEAPP");
            break;
        case dmExtension::EVENT_ID_DEACTIVATEAPP:
            dmLogInfo("OnEventMyExtension - EVENT_ID_DEACTIVATEAPP");
            break;
        case dmExtension::EVENT_ID_ICONIFYAPP:
            dmLogInfo("OnEventMyExtension - EVENT_ID_ICONIFYAPP");
            break;
        case dmExtension::EVENT_ID_DEICONIFYAPP:
            dmLogInfo("OnEventMyExtension - EVENT_ID_DEICONIFYAPP");
            break;
        default:
            dmLogWarning("OnEventMyExtension - Unknown event id");
            break;
    }
}

// Defold SDK uses a macro for setting up extension entry points:
//
// DM_DECLARE_EXTENSION(symbol, name, app_init, app_final, init, update, on_event, final)

// MyExtension is the C++ symbol that holds all relevant extension data.
// It must match the name field in the `ext.manifest`
DM_DECLARE_EXTENSION(zipper, LIB_NAME, AppInitializeMyExtension, AppFinalizeMyExtension, InitializeMyExtension, OnUpdateMyExtension, OnEventMyExtension, FinalizeMyExtension)
