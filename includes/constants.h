/*
 * SDLX, a SDL graphics library for CS students.
 * Copyright (C) 2017, Seth Kasmann, Yihsiang Liow
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "sdllib.h"

/*****************************************************************************
Event Types

Use these constants to check for various event types.

if (event.type() == ?)
*****************************************************************************/
static const int QUIT             = SDL_QUIT;
static const int KEYDOWN          = SDL_KEYDOWN;
static const int KEYUP            = SDL_KEYUP;
static const int MOUSEMOTION      = SDL_MOUSEMOTION;
static const int MOUSEBUTTONUP    = SDL_MOUSEBUTTONUP;
static const int MOUSEBUTTONDOWN  = SDL_MOUSEBUTTONDOWN;
static const int MOUSEWHEEL       = SDL_MOUSEWHEEL;
static const int WINDOW           = SDL_WINDOWEVENT;
static const int TEXTINPUT        = SDL_TEXTINPUT;  
static const int FINGERMOTION     = SDL_FINGERMOTION;
static const int FINGERUP         = SDL_FINGERUP;
static const int FINGERDOWN       = SDL_FINGERDOWN;
static const int GESTURE          = SDL_MULTIGESTURE;
static const int CONTROLLERMOTION = SDL_CONTROLLERAXISMOTION;
static const int CONTROLLERUP     = SDL_CONTROLLERBUTTONUP;
static const int CONTROLLERDOWN   = SDL_CONTROLLERBUTTONDOWN;

/*****************************************************************************
Mouse Buttons

Use these constants to check for mouse buttons after the MOUSEBUTTONDOWN or
MOUSEBUTTONUP events.
*****************************************************************************/
static const uint8_t BUTTON_LEFT   = SDL_BUTTON_LEFT;
static const uint8_t BUTTON_MIDDLE = SDL_BUTTON_MIDDLE;
static const uint8_t BUTTON_RIGHT  = SDL_BUTTON_RIGHT;
static const uint8_t BUTTON_X1     = SDL_BUTTON_X1;
static const uint8_t BUTTON_X2     = SDL_BUTTON_X2;

/*****************************************************************************
Keyboard Keys

Use these constants after a KEYDOWN or KEYUP event.
*****************************************************************************/
static const int KEY_LEFT      = SDL_SCANCODE_LEFT;
static const int KEY_RIGHT     = SDL_SCANCODE_RIGHT;
static const int KEY_UP        = SDL_SCANCODE_UP;
static const int KEY_DOWN      = SDL_SCANCODE_DOWN;
static const int KEY_SPACE     = SDL_SCANCODE_SPACE;
static const int KEY_RETURN    = SDL_SCANCODE_RETURN;
static const int KEY_ESCAPE    = SDL_SCANCODE_ESCAPE;
static const int KEY_TAB       = SDL_SCANCODE_TAB;
static const int KEY_BACKSPACE = SDL_SCANCODE_BACKSPACE;
static const int KEY_A         = SDL_SCANCODE_A;
static const int KEY_B         = SDL_SCANCODE_B;
static const int KEY_C         = SDL_SCANCODE_C;
static const int KEY_D         = SDL_SCANCODE_D;
static const int KEY_E         = SDL_SCANCODE_E;
static const int KEY_F         = SDL_SCANCODE_F;
static const int KEY_G         = SDL_SCANCODE_G;
static const int KEY_H         = SDL_SCANCODE_H;
static const int KEY_I         = SDL_SCANCODE_I;
static const int KEY_J         = SDL_SCANCODE_J;
static const int KEY_K         = SDL_SCANCODE_K;
static const int KEY_L         = SDL_SCANCODE_L;
static const int KEY_M         = SDL_SCANCODE_M;
static const int KEY_N         = SDL_SCANCODE_N;
static const int KEY_O         = SDL_SCANCODE_O;
static const int KEY_P         = SDL_SCANCODE_P;
static const int KEY_Q         = SDL_SCANCODE_Q;
static const int KEY_R         = SDL_SCANCODE_R;
static const int KEY_S         = SDL_SCANCODE_S;
static const int KEY_T         = SDL_SCANCODE_T;
static const int KEY_U         = SDL_SCANCODE_U;
static const int KEY_V         = SDL_SCANCODE_V;
static const int KEY_W         = SDL_SCANCODE_W;
static const int KEY_X         = SDL_SCANCODE_X;
static const int KEY_Y         = SDL_SCANCODE_Y;
static const int KEY_Z         = SDL_SCANCODE_Z;
static const int KEY_0         = SDL_SCANCODE_0;
static const int KEY_1         = SDL_SCANCODE_1;
static const int KEY_2         = SDL_SCANCODE_2;
static const int KEY_3         = SDL_SCANCODE_3;
static const int KEY_4         = SDL_SCANCODE_4;
static const int KEY_5         = SDL_SCANCODE_5;
static const int KEY_6         = SDL_SCANCODE_6;
static const int KEY_7         = SDL_SCANCODE_7;
static const int KEY_8         = SDL_SCANCODE_8;
static const int KEY_9         = SDL_SCANCODE_9;

/*****************************************************************************
Game Controller Buttons

Use these constants after a CONTROLLERUP or CONTROLLERDOWN event.
*****************************************************************************/
static const uint8_t CBUTTON_A             = SDL_CONTROLLER_BUTTON_A;
static const uint8_t CBUTTON_B             = SDL_CONTROLLER_BUTTON_B;
static const uint8_t CBUTTON_X             = SDL_CONTROLLER_BUTTON_X;
static const uint8_t CBUTTON_Y             = SDL_CONTROLLER_BUTTON_Y;
static const uint8_t CBUTTON_UP            = SDL_CONTROLLER_BUTTON_DPAD_UP;
static const uint8_t CBUTTON_DOWN          = SDL_CONTROLLER_BUTTON_DPAD_DOWN;
static const uint8_t CBUTTON_LEFT          = SDL_CONTROLLER_BUTTON_DPAD_LEFT;
static const uint8_t CBUTTON_RIGHT         = SDL_CONTROLLER_BUTTON_DPAD_RIGHT;
static const uint8_t CBUTTON_BACK          = SDL_CONTROLLER_BUTTON_BACK;
static const uint8_t CBUTTON_GUIDE         = SDL_CONTROLLER_BUTTON_GUIDE;
static const uint8_t CBUTTON_START         = SDL_CONTROLLER_BUTTON_START;
static const uint8_t CBUTTON_LEFTSTICK     = SDL_CONTROLLER_BUTTON_LEFTSTICK;
static const uint8_t CBUTTON_RIGHTSTICK    = SDL_CONTROLLER_BUTTON_RIGHTSTICK;
static const uint8_t CBUTTON_LEFTSHOULDER  = SDL_CONTROLLER_BUTTON_LEFTSHOULDER;
static const uint8_t CBUTTON_RIGHTSHOULDER = SDL_CONTROLLER_BUTTON_RIGHTSHOULDER;
static const uint8_t CBUTTON_MAX           = SDL_CONTROLLER_BUTTON_MAX;


/*****************************************************************************
Game Controller Axis

Use these constants after a CONTROLLERMOTION event to determine the axis
*****************************************************************************/
static const uint8_t AXIS_LEFTX        = SDL_CONTROLLER_AXIS_LEFTX;
static const uint8_t AXIS_LEFTY        = SDL_CONTROLLER_AXIS_LEFTY;
static const uint8_t AXIS_RIGHTX       = SDL_CONTROLLER_AXIS_RIGHTX;
static const uint8_t AXIS_RIGHTY       = SDL_CONTROLLER_AXIS_RIGHTY;
static const uint8_t AXIS_TRIGGERLEFT  = SDL_CONTROLLER_AXIS_TRIGGERLEFT;
static const uint8_t AXIS_TRIGGERRIGHT = SDL_CONTROLLER_AXIS_TRIGGERRIGHT;
static const uint8_t AXIS_MAX          = SDL_CONTROLLER_AXIS_MAX;

/*****************************************************************************
Window Properties

Use these constants after a WINDOW event.
(Only necessary for multi-window projects)
*****************************************************************************/
static const uint8_t SHOWN          = SDL_WINDOWEVENT_SHOWN;
static const uint8_t HIDDEN         = SDL_WINDOWEVENT_HIDDEN;
static const uint8_t MOVED          = SDL_WINDOWEVENT_MOVED;
static const uint8_t RESIZED        = SDL_WINDOWEVENT_RESIZED;
static const uint8_t MINIMIZED      = SDL_WINDOWEVENT_MINIMIZED;
static const uint8_t MAXIMIZED      = SDL_WINDOWEVENT_MAXIMIZED;
static const uint8_t RESTORED       = SDL_WINDOWEVENT_RESTORED;
static const uint8_t MOUSE_ENTER    = SDL_WINDOWEVENT_ENTER;
static const uint8_t MOUSE_LEAVE    = SDL_WINDOWEVENT_LEAVE;
static const uint8_t KEYBOARD_ENTER = SDL_WINDOWEVENT_FOCUS_GAINED;
static const uint8_t KEYBOARD_LEAVE = SDL_WINDOWEVENT_FOCUS_LOST;
static const uint8_t CLOSED         = SDL_WINDOWEVENT_CLOSE;

#endif