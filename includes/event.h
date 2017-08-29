/*
 * SDLX, a SDL graphics library for CS students.
 * Copyright (C) 2017, Yihsiang Liow, Seth Kasmann
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

#ifndef EVENT_H
#define EVENT_H

#include <cstdint>
#include "sdllib.h"

namespace sdlx {

    class Motion;
    class Button;
    class Key;
    class Wheel;
    class Finger;
    class Gesture;
    class TextInput;
    class ControllerButton;
    class ControllerMotion;
    class WindowEvent;

    /*************************************************************************

      An Event object models an event. The useful methods are poll() and 
      type(). The most useful values returned by type() are
      * QUIT
      * KEYDOWN
      * KEYUP

      (See a full list of Event Types in constants.h)

      USAGE: The following is an example involving the Event and Key classes.

        Event event;
        bool quit = false;

        while (!quit)
        {
            while (event.poll())
            {
                if (event.type() == QUIT)
                { 
                    quit = true;
                }
                else if (event.type() == KEYDOWN)
                {
                    Key key = event.key();
                    if (key == SPACE)
                    {
                        // do something ...
                    }
                }
                else if (event.type() == KEYUP)
                {
                    Key key = event.key();
                    if (key == RIGHTARROW)
                    {
                        // do something ...
                    }
                }
            }
        }

    *************************************************************************/

    class Event
    {
    public:
        int poll();
        int type() const;

        const Motion           motion()            const;
        const Button           button()            const;
        const Key              key()               const;
        const Wheel            wheel()             const;
        const Finger           finger()            const;
        const Gesture          gesture()           const;
        const WindowEvent      window()            const;
        const TextInput        text_input()        const;
        const ControllerMotion controller_motion() const;
        const ControllerButton controller_button() const;
        const SDL_Event*       get_event()         const;

    private:
        SDL_Event event;
    };

    /*************************************************************************

        A Button Object models a MOUSEBUTTONDOWN or MOUSEBUTTONUP event. See 
        the Event Class above for how to properly detect an event.

        USAGE:

        if (event.type() == MOUSEBUTTONDOWN)
        {
            Button button = event.button();

            if (button == BUTTON_LEFT)
            {
                // Do something.
            }
        }

        (For a full list of available buttons, see constants.h)

        A Button object also provides you with:
            - x position where the button was pressed/released.
            - y position where the button was pressed/released.
            - check if it was a single click or double click.

    *************************************************************************/

    class Button
    {
    public:
        Button();
        Button(const SDL_MouseButtonEvent* e);
        bool operator==(uint8_t b) const;
        bool double_click() const;
        int x() const;
        int y() const;
    private:
        const SDL_MouseButtonEvent* _e;
    };

    /*************************************************************************

        A Motion object models a MOUSEMOTION event. See the Event Class for 
        how to properly detect an event.

        USAGE:

        if (event.type() == MOUSEMOTION)
        {
            Motion motion = event.motion();
        }

        A Motion object provides you with:
            - x and y position where the mouse was moved to.
            - dx and dy.

    *************************************************************************/

    class Motion
    {
    public:
        Motion();
        Motion(const SDL_MouseMotionEvent* e);
        int x() const;
        int y() const;
        int dx() const;
        int dy() const;
    private:
        const SDL_MouseMotionEvent* _e;
    };

    /*************************************************************************

        A Wheel object models a MOUSEWHEEL event. See the Event Class for how 
        to properly detect an event.

        USAGE:

        if (event.type() == MOUSEWHEEL)
        {
            Wheel wheel = event.wheel();
        }

        A Wheel object provides you with:
            - The x and y value of the mouse wheel. The x and y values can be
            either -1, 0, or 1.

    *************************************************************************/

    class Wheel
    {
    public:
        Wheel();
        Wheel(const SDL_MouseWheelEvent* e);
        int x() const;
        int y() const;
    private:
        const SDL_MouseWheelEvent* _e;
    };

    /*************************************************************************

        A Key object models a KEYUP or KEYDOWN event. See the Event Class for 
        how to properly detect an event.

        USAGE:

        if (event.type() == KEYDOWN)
        {
            Key key = event.key();
            if (key == KEY_SPACE)
            {
                // Do something.
            }
        }

        (For a full list of available keys, see constants.h)

        A Key object also provides you with:
            - ability to check if the press is a repeat (if the keys is held)
            or not.


    *************************************************************************/

    class Key
    {
    public:
        Key();
        Key(const SDL_KeyboardEvent* e);
        bool operator==(int key) const;
        bool repeat() const;
    private:
        const SDL_KeyboardEvent* _e;
    };

    /*************************************************************************

        (Device must have touch screen capability)
        A Finger object models a FINGERUP or FINGERDOWN event. See the Event 
        Class for how to properly detect an event.

        USAGE:

        if (event.type() == FINGERDOWN)
        {
            Finger finger = event.finger();
        }

        A Finger object provides you with:
            - x and y location of the touch event.
            - dx and dy (distance moved) normalized to (-1 ... 1).
            - pressure normalized to (-1 ... ).

    *************************************************************************/

    class Finger
    {
    public:
        Finger();
        Finger(const SDL_TouchFingerEvent* e);
        float x() const;
        float y() const;
        float dx() const;
        float dy() const;
        float pressure() const;
    private:
        const SDL_TouchFingerEvent* _e;
    };

    /*************************************************************************

        (Device must have touch screen capability)
        A Gesture object models a GESTURE event. See the Event Class for how 
        to properly detect an event.

        USAGE:

        if (event.type() == GESTURE)
        {
            Gesture gesture = event.gesture();
        }

        A Gesture object provides you with:
            - x and y, the normalized center of the gesture.
            - rotate, the amount the fingers rotated during this motion.
            - pinch, the amount the fingers pinched during this motion.
            - the number of fingers used.

    *************************************************************************/

    class Gesture
    {
    public:
        Gesture();
        Gesture(const SDL_MultiGestureEvent* e);
        float x() const;
        float y() const;
        float rotate() const;
        float pinch() const;
        int num_fingers() const;
    private:
        const SDL_MultiGestureEvent* _e;
    };

    /*************************************************************************

        A TextInput object models a TEXTINPUT event. See the Event Class for 
        how to properly detect events.

        USAGE:

        if (event.type() == TEXTINPUT)
        {
            TextInput input = event.text_input();
        }

        A TextInput object provides you with:
            - the character inputted by the user.

    *************************************************************************/

    class TextInput
    {
    public:
        TextInput();
        TextInput(const SDL_TextInputEvent* e);
        const char* character() const;
    private:
        const SDL_TextInputEvent* _e;
    };

    /*************************************************************************

        A ControllerMotion object models a CONTROLLERMOTION event. See the 
        Event class for how to properly detect events.

        USAGE:

        if (event.type() == CONTROLLERMOTION)
        {
            ControllerMotion cmotion = event.controller_motion();
            if (cmotion == AXIS_LEFTX)
            {
                // Do something.
            }
        }

        (For a full list of available controller axis see constants.h)

        The ControllerMotion object also provides you with:
            - value of the axis (range: -32768 to 32767).

    *************************************************************************/

    class ControllerMotion
    {
    public:
        ControllerMotion();
        ControllerMotion(const SDL_ControllerAxisEvent* e);
        bool operator==(uint8_t a) const;
        int value() const;
    private:
        const SDL_ControllerAxisEvent* _e;
    };

    /*************************************************************************

        A ControllerButton object models a CONTROLLERUP or CONTROLLERDOWN 
        event. See the Event class for how to properly detect events.

        if (event.type() == CONTROLLERUP)
        {
            ControllerButton cbutton = event.controller_button();
            if (cbutton == CBUTTON_UP)
            {
                // Do something.
            }
        }

        (For a full list of available controller buttons see constants.h)

    *************************************************************************/

    class ControllerButton
    {
    public:
        ControllerButton();
        ControllerButton(const SDL_ControllerButtonEvent* e);
        bool operator==(uint8_t b) const;
    private:
        const SDL_ControllerButtonEvent* _e;    
    };

    /*************************************************************************

        (Only necessary for multi-window projects)
        A WindowEvent object models a WINDOW event. See the Event class for 
        how to properly detect events.

        if (event.type == WINDOW)
        {
            WindowEvent wevent = event.window();
        }

        (For a full list of available window events, see constants.h)

        The WindowEvent object also provides you with:
            - data1 and data2. These are only used for RESIZED (being w, h),
            and MOVED (being x, y).

    *************************************************************************/

    class WindowEvent
    {
    public:
        WindowEvent();
        WindowEvent(const SDL_WindowEvent* e);
        bool operator==(uint8_t id) const;
        int data1() const;
        int data2() const;
    private:
        const SDL_WindowEvent* _e;
    };
}

#endif
