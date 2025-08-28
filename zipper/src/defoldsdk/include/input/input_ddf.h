
// Copyright 2020-2024 The Defold Foundation
// Copyright 2014-2020 King
// Copyright 2009-2014 Ragnar Svensson, Christian Murray
// Licensed under the Defold License version 1.0 (the "License"); you may not use
// this file except in compliance with the License.
//
// You may obtain a copy of the License, together with FAQs at
// https://www.defold.com/license
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.


// GENERATED FILE! DO NOT EDIT!

#ifndef INPUT_DDF_H
#define INPUT_DDF_H

#include <stdint.h>
#include <assert.h>
#include <ddf/ddf.h>
#include "ddf/ddf_math.h"
#include <dmsdk/dlib/align.h>

namespace dmInputDDF
{
    enum Key
    {
        KEY_SPACE       = 0,
        KEY_EXCLAIM     = 1,
        KEY_QUOTEDBL    = 2,
        KEY_HASH        = 3,
        KEY_DOLLAR      = 4,
        KEY_AMPERSAND   = 5,
        KEY_QUOTE       = 6,
        KEY_LPAREN      = 7,
        KEY_RPAREN      = 8,
        KEY_ASTERISK    = 9,
        KEY_PLUS        = 10,
        KEY_COMMA       = 11,
        KEY_MINUS       = 12,
        KEY_PERIOD      = 13,
        KEY_SLASH       = 14,
        KEY_0           = 15,
        KEY_1           = 16,
        KEY_2           = 17,
        KEY_3           = 18,
        KEY_4           = 19,
        KEY_5           = 20,
        KEY_6           = 21,
        KEY_7           = 22,
        KEY_8           = 23,
        KEY_9           = 24,
        KEY_COLON       = 25,
        KEY_SEMICOLON   = 26,
        KEY_LESS        = 27,
        KEY_EQUALS      = 28,
        KEY_GREATER     = 29,
        KEY_QUESTION    = 30,
        KEY_AT          = 31,
        KEY_A           = 32,
        KEY_B           = 33,
        KEY_C           = 34,
        KEY_D           = 35,
        KEY_E           = 36,
        KEY_F           = 37,
        KEY_G           = 38,
        KEY_H           = 39,
        KEY_I           = 40,
        KEY_J           = 41,
        KEY_K           = 42,
        KEY_L           = 43,
        KEY_M           = 44,
        KEY_N           = 45,
        KEY_O           = 46,
        KEY_P           = 47,
        KEY_Q           = 48,
        KEY_R           = 49,
        KEY_S           = 50,
        KEY_T           = 51,
        KEY_U           = 52,
        KEY_V           = 53,
        KEY_W           = 54,
        KEY_X           = 55,
        KEY_Y           = 56,
        KEY_Z           = 57,
        KEY_LBRACKET    = 58,
        KEY_BACKSLASH   = 59,
        KEY_RBRACKET    = 60,
        KEY_CARET       = 61,
        KEY_UNDERSCORE  = 62,
        KEY_BACKQUOTE   = 63,
        KEY_LBRACE      = 64,
        KEY_PIPE        = 65,
        KEY_RBRACE      = 66,
        KEY_TILDE       = 67,
        KEY_ESC         = 68,
        KEY_F1          = 69,
        KEY_F2          = 70,
        KEY_F3          = 71,
        KEY_F4          = 72,
        KEY_F5          = 73,
        KEY_F6          = 74,
        KEY_F7          = 75,
        KEY_F8          = 76,
        KEY_F9          = 77,
        KEY_F10         = 78,
        KEY_F11         = 79,
        KEY_F12         = 80,
        KEY_UP          = 81,
        KEY_DOWN        = 82,
        KEY_LEFT        = 83,
        KEY_RIGHT       = 84,
        KEY_LSHIFT      = 85,
        KEY_RSHIFT      = 86,
        KEY_LCTRL       = 87,
        KEY_RCTRL       = 88,
        KEY_LALT        = 89,
        KEY_RALT        = 90,
        KEY_TAB         = 91,
        KEY_ENTER       = 92,
        KEY_BACKSPACE   = 93,
        KEY_INSERT      = 94,
        KEY_DEL         = 95,
        KEY_PAGEUP      = 96,
        KEY_PAGEDOWN    = 97,
        KEY_HOME        = 98,
        KEY_END         = 99,
        KEY_KP_0        = 100,
        KEY_KP_1        = 101,
        KEY_KP_2        = 102,
        KEY_KP_3        = 103,
        KEY_KP_4        = 104,
        KEY_KP_5        = 105,
        KEY_KP_6        = 106,
        KEY_KP_7        = 107,
        KEY_KP_8        = 108,
        KEY_KP_9        = 109,
        KEY_KP_DIVIDE   = 110,
        KEY_KP_MULTIPLY = 111,
        KEY_KP_SUBTRACT = 112,
        KEY_KP_ADD      = 113,
        KEY_KP_DECIMAL  = 114,
        KEY_KP_EQUAL    = 115,
        KEY_KP_ENTER    = 116,
        KEY_KP_NUM_LOCK = 117,
        KEY_CAPS_LOCK   = 118,
        KEY_SCROLL_LOCK = 119,
        KEY_PAUSE       = 120,
        KEY_LSUPER      = 121,
        KEY_RSUPER      = 122,
        KEY_MENU        = 123,
        KEY_BACK        = 124,
        MAX_KEY_COUNT   = 125,
    };

    enum Mouse
    {
        MOUSE_WHEEL_UP      = 0,
        MOUSE_WHEEL_DOWN    = 1,
        MOUSE_BUTTON_LEFT   = 2,
        MOUSE_BUTTON_MIDDLE = 3,
        MOUSE_BUTTON_RIGHT  = 4,
        MOUSE_BUTTON_1      = 5,
        MOUSE_BUTTON_2      = 6,
        MOUSE_BUTTON_3      = 7,
        MOUSE_BUTTON_4      = 8,
        MOUSE_BUTTON_5      = 9,
        MOUSE_BUTTON_6      = 10,
        MOUSE_BUTTON_7      = 11,
        MOUSE_BUTTON_8      = 12,
        MAX_MOUSE_COUNT     = 13,
    };

    enum Gamepad
    {
        GAMEPAD_LSTICK_LEFT  = 0,
        GAMEPAD_LSTICK_RIGHT = 1,
        GAMEPAD_LSTICK_DOWN  = 2,
        GAMEPAD_LSTICK_UP    = 3,
        GAMEPAD_LSTICK_CLICK = 4,
        GAMEPAD_LTRIGGER     = 5,
        GAMEPAD_LSHOULDER    = 6,
        GAMEPAD_LPAD_LEFT    = 7,
        GAMEPAD_LPAD_RIGHT   = 8,
        GAMEPAD_LPAD_DOWN    = 9,
        GAMEPAD_LPAD_UP      = 10,
        GAMEPAD_RSTICK_LEFT  = 11,
        GAMEPAD_RSTICK_RIGHT = 12,
        GAMEPAD_RSTICK_DOWN  = 13,
        GAMEPAD_RSTICK_UP    = 14,
        GAMEPAD_RSTICK_CLICK = 15,
        GAMEPAD_RTRIGGER     = 16,
        GAMEPAD_RSHOULDER    = 17,
        GAMEPAD_RPAD_LEFT    = 18,
        GAMEPAD_RPAD_RIGHT   = 19,
        GAMEPAD_RPAD_DOWN    = 20,
        GAMEPAD_RPAD_UP      = 21,
        GAMEPAD_START        = 22,
        GAMEPAD_BACK         = 23,
        GAMEPAD_GUIDE        = 24,
        GAMEPAD_CONNECTED    = 25,
        GAMEPAD_DISCONNECTED = 26,
        GAMEPAD_RAW          = 27,
        MAX_GAMEPAD_COUNT    = 28,
    };

    enum GamepadType
    {
        GAMEPAD_TYPE_AXIS   = 0,
        GAMEPAD_TYPE_BUTTON = 1,
        GAMEPAD_TYPE_HAT    = 2,
    };

    enum GamepadModifier
    {
        GAMEPAD_MODIFIER_NEGATE    = 0,
        GAMEPAD_MODIFIER_SCALE     = 1,
        GAMEPAD_MODIFIER_CLAMP     = 2,
        MAX_GAMEPAD_MODIFIER_COUNT = 3,
    };

    enum Touch
    {
        TOUCH_MULTI     = 0,
        MAX_TOUCH_COUNT = 1,
    };

    enum Text
    {
        TEXT           = 0,
        MARKED_TEXT    = 1,
        MAX_TEXT_COUNT = 2,
    };

    struct GamepadModifier_t
    {
        dmInputDDF::GamepadModifier m_Mod;
        
        static dmDDF::Descriptor* m_DDFDescriptor;
        static const uint64_t m_DDFHash;
    };

    struct GamepadMapEntry
    {
        dmInputDDF::Gamepad     m_Input;
        dmInputDDF::GamepadType m_Type;
        uint32_t                m_Index;
        struct
        {
            dmInputDDF::GamepadModifier_t* m_Data;
            const dmInputDDF::GamepadModifier_t& operator[](uint32_t i) const { assert(i < m_Count); return m_Data[i]; }
            dmInputDDF::GamepadModifier_t& operator[](uint32_t i) { assert(i < m_Count); return m_Data[i]; }
            uint32_t m_Count;
        } m_Mod;

        uint32_t                m_HatMask;
        
        static dmDDF::Descriptor* m_DDFDescriptor;
        static const uint64_t m_DDFHash;
    };

    struct GamepadMap
    {
        const char* m_Device;
        const char* m_Platform;
        float       m_DeadZone;
        struct
        {
            dmInputDDF::GamepadMapEntry* m_Data;
            const dmInputDDF::GamepadMapEntry& operator[](uint32_t i) const { assert(i < m_Count); return m_Data[i]; }
            dmInputDDF::GamepadMapEntry& operator[](uint32_t i) { assert(i < m_Count); return m_Data[i]; }
            uint32_t m_Count;
        } m_Map;

        
        static dmDDF::Descriptor* m_DDFDescriptor;
        static const uint64_t m_DDFHash;
    };

    struct GamepadMaps
    {
        struct
        {
            dmInputDDF::GamepadMap* m_Data;
            const dmInputDDF::GamepadMap& operator[](uint32_t i) const { assert(i < m_Count); return m_Data[i]; }
            dmInputDDF::GamepadMap& operator[](uint32_t i) { assert(i < m_Count); return m_Data[i]; }
            uint32_t m_Count;
        } m_Driver;

        
        static dmDDF::Descriptor* m_DDFDescriptor;
        static const uint64_t m_DDFHash;
    };

    struct KeyTrigger
    {
        dmInputDDF::Key m_Input;
        const char*     m_Action;
        
        static dmDDF::Descriptor* m_DDFDescriptor;
        static const uint64_t m_DDFHash;
    };

    struct MouseTrigger
    {
        dmInputDDF::Mouse m_Input;
        const char*       m_Action;
        
        static dmDDF::Descriptor* m_DDFDescriptor;
        static const uint64_t m_DDFHash;
    };

    struct GamepadTrigger
    {
        dmInputDDF::Gamepad m_Input;
        const char*         m_Action;
        
        static dmDDF::Descriptor* m_DDFDescriptor;
        static const uint64_t m_DDFHash;
    };

    struct TouchTrigger
    {
        dmInputDDF::Touch m_Input;
        const char*       m_Action;
        
        static dmDDF::Descriptor* m_DDFDescriptor;
        static const uint64_t m_DDFHash;
    };

    struct TextTrigger
    {
        dmInputDDF::Text m_Input;
        const char*      m_Action;
        
        static dmDDF::Descriptor* m_DDFDescriptor;
        static const uint64_t m_DDFHash;
    };

    struct InputBinding
    {
        struct
        {
            dmInputDDF::KeyTrigger* m_Data;
            const dmInputDDF::KeyTrigger& operator[](uint32_t i) const { assert(i < m_Count); return m_Data[i]; }
            dmInputDDF::KeyTrigger& operator[](uint32_t i) { assert(i < m_Count); return m_Data[i]; }
            uint32_t m_Count;
        } m_KeyTrigger;

        struct
        {
            dmInputDDF::MouseTrigger* m_Data;
            const dmInputDDF::MouseTrigger& operator[](uint32_t i) const { assert(i < m_Count); return m_Data[i]; }
            dmInputDDF::MouseTrigger& operator[](uint32_t i) { assert(i < m_Count); return m_Data[i]; }
            uint32_t m_Count;
        } m_MouseTrigger;

        struct
        {
            dmInputDDF::GamepadTrigger* m_Data;
            const dmInputDDF::GamepadTrigger& operator[](uint32_t i) const { assert(i < m_Count); return m_Data[i]; }
            dmInputDDF::GamepadTrigger& operator[](uint32_t i) { assert(i < m_Count); return m_Data[i]; }
            uint32_t m_Count;
        } m_GamepadTrigger;

        struct
        {
            dmInputDDF::TouchTrigger* m_Data;
            const dmInputDDF::TouchTrigger& operator[](uint32_t i) const { assert(i < m_Count); return m_Data[i]; }
            dmInputDDF::TouchTrigger& operator[](uint32_t i) { assert(i < m_Count); return m_Data[i]; }
            uint32_t m_Count;
        } m_TouchTrigger;

        struct
        {
            dmInputDDF::TextTrigger* m_Data;
            const dmInputDDF::TextTrigger& operator[](uint32_t i) const { assert(i < m_Count); return m_Data[i]; }
            dmInputDDF::TextTrigger& operator[](uint32_t i) { assert(i < m_Count); return m_Data[i]; }
            uint32_t m_Count;
        } m_TextTrigger;

        
        static dmDDF::Descriptor* m_DDFDescriptor;
        static const uint64_t m_DDFHash;
    };

};

#ifdef DDF_EXPOSE_DESCRIPTORS
extern dmDDF::EnumDescriptor dmInputDDF_Key_DESCRIPTOR;
extern dmDDF::EnumDescriptor dmInputDDF_Mouse_DESCRIPTOR;
extern dmDDF::EnumDescriptor dmInputDDF_Gamepad_DESCRIPTOR;
extern dmDDF::EnumDescriptor dmInputDDF_GamepadType_DESCRIPTOR;
extern dmDDF::EnumDescriptor dmInputDDF_GamepadModifier_DESCRIPTOR;
extern dmDDF::EnumDescriptor dmInputDDF_Touch_DESCRIPTOR;
extern dmDDF::EnumDescriptor dmInputDDF_Text_DESCRIPTOR;
extern dmDDF::Descriptor dmInputDDF_GamepadModifier_t_DESCRIPTOR;
extern dmDDF::Descriptor dmInputDDF_GamepadMapEntry_DESCRIPTOR;
extern dmDDF::Descriptor dmInputDDF_GamepadMap_DESCRIPTOR;
extern dmDDF::Descriptor dmInputDDF_GamepadMaps_DESCRIPTOR;
extern dmDDF::Descriptor dmInputDDF_KeyTrigger_DESCRIPTOR;
extern dmDDF::Descriptor dmInputDDF_MouseTrigger_DESCRIPTOR;
extern dmDDF::Descriptor dmInputDDF_GamepadTrigger_DESCRIPTOR;
extern dmDDF::Descriptor dmInputDDF_TouchTrigger_DESCRIPTOR;
extern dmDDF::Descriptor dmInputDDF_TextTrigger_DESCRIPTOR;
extern dmDDF::Descriptor dmInputDDF_InputBinding_DESCRIPTOR;
#endif
#endif // INPUT_DDF_H 
