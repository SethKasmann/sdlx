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

#include "event.h"

namespace sdlx {

    //------------------------------------------------------------------------
    // Event Class
    //------------------------------------------------------------------------

    int Event::poll()
    {
    	return SDL_PollEvent(&event);
    }

    int Event::type() const
    {
    	return event.type;
    }

    const Motion Event::motion() const
    {
        return Motion(&event.motion);
    }

    const Button Event::button() const
    {
        return Button(&event.button);
    }

    const Key Event::key() const
    {
        return Key(&event.key);
    }

    const Wheel Event::wheel() const
    {
        return Wheel(&event.wheel);
    }

    const Finger Event::finger() const
    {
        return Finger(&event.tfinger);
    }

    const Gesture Event::gesture() const
    {
        return Gesture(&event.mgesture);
    }

    const WindowEvent Event::window() const
    {
        return WindowEvent(&event.window);
    }

    const TextInput Event::text_input() const
    {
        return TextInput(&event.text);
    }

    const ControllerMotion Event::controller_motion() const
    {
        return ControllerMotion(&event.caxis);
    }

    const ControllerButton Event::controller_button() const
    {
        return ControllerButton(&event.cbutton);
    }

    const SDL_Event* Event::get_event() const
    {
        return &event;
    }

    //------------------------------------------------------------------------
    // Button Class
    //------------------------------------------------------------------------

    Button::Button()
    {
    	_e = nullptr;
    }

    Button::Button(const SDL_MouseButtonEvent* e)
    {
        _e = e;
    }

    bool Button::operator==(uint8_t b) const
    {
        return _e->button == b;
    }

    bool Button::double_click() const
    {
        return _e->clicks == 2;
    }

    int Button::x() const
    {
        return _e->x;
    }

    int Button::y() const
    {
        return _e->y;
    }

    //------------------------------------------------------------------------
    // Motion Class
    //------------------------------------------------------------------------

    Motion::Motion()
    {
    	_e = nullptr;
    }

    Motion::Motion(const SDL_MouseMotionEvent* e)
    {
        _e = e;
    }

    int Motion::x() const
    {
        return _e->x;
    }

    int Motion::y() const
    {
        return _e->y;
    }

    int Motion::dx() const
    {
        return _e->xrel;
    }

    int Motion::dy() const
    {
        return _e->yrel;
    }

    //------------------------------------------------------------------------
    // Wheel Class
    //------------------------------------------------------------------------

    Wheel::Wheel()
    {
    	_e = nullptr;
    }

    Wheel::Wheel(const SDL_MouseWheelEvent* e)
    {
    	_e = e;
    }

    int Wheel::x() const
    {
        return _e->x;
    }

    int Wheel::y() const
    {
        return _e->y;
    }

    //------------------------------------------------------------------------
    // Key Class
    //------------------------------------------------------------------------

    Key::Key()
    {
    	_e = nullptr;
    }

    Key::Key(const SDL_KeyboardEvent* e)
    {
        _e = e;
    }

    bool Key::operator==(int key) const
    {
        return _e->keysym.scancode == key;
    }

    bool Key::repeat() const
    {
        return _e->repeat != 0;
    }

    //------------------------------------------------------------------------
    // Finger Class
    //------------------------------------------------------------------------

    Finger::Finger()
    {
    	_e = nullptr;
    }

    Finger::Finger(const SDL_TouchFingerEvent* e)
    {
        _e = e;
    }

    int64_t Finger::id() const
    {
        return _e->fingerId;
    }

    float Finger::x() const
    {
        return _e->x;
    }

    float Finger::y() const
    {
        return _e->y;
    }

    float Finger::dx() const
    {
        return _e->dx;
    }

    float Finger::dy() const
    {
        return _e->dy;
    }

    float Finger::pressure() const
    {
        return _e->pressure;
    }


    //------------------------------------------------------------------------
    // Gesture Class
    //------------------------------------------------------------------------

    Gesture::Gesture()
    {
    	_e = nullptr;
    }

    Gesture::Gesture(const SDL_MultiGestureEvent* e)
    {
        _e = e;
    }

    float Gesture::x() const
    {
        return _e->x;
    }

    float Gesture::y() const
    {
        return _e->y;
    }

    float Gesture::rotate() const
    {
        return _e->dTheta;
    }

    float Gesture::pinch() const
    {
        return _e->dDist;
    }

    int Gesture::num_fingers() const
    {
        return _e->numFingers;
    }

    //------------------------------------------------------------------------
    // TextInput Class
    //------------------------------------------------------------------------

    TextInput::TextInput()
    {
    	_e = nullptr;
    }

    TextInput::TextInput(const SDL_TextInputEvent* e)
    {
    	_e = e;
    }

    const char* TextInput::character() const
    {
        return _e->text;
    }

    //------------------------------------------------------------------------
    // ControllerButton Class
    //------------------------------------------------------------------------

    ControllerMotion::ControllerMotion()
    {
        _e = nullptr;
    }

    ControllerMotion::ControllerMotion(const SDL_ControllerAxisEvent* e)
    {
        _e = e;
    }

    bool ControllerMotion::operator==(uint8_t a) const
    {
        return _e->axis == a;
    }

    int ControllerMotion::value() const
    {
        return _e->value;
    }

    //------------------------------------------------------------------------
    // ControllerButton Class
    //------------------------------------------------------------------------

    ControllerButton::ControllerButton()
    {
        _e = NULL;
    }

    ControllerButton::ControllerButton(const SDL_ControllerButtonEvent* e)
    {
        _e = e;
    }

    bool ControllerButton::operator==(uint8_t b) const
    {
        return _e->button == b;
    }

    //------------------------------------------------------------------------
    // WindowEvent Class
    //------------------------------------------------------------------------

    WindowEvent::WindowEvent()
    {
        _e = nullptr;
    }

    WindowEvent::WindowEvent(const SDL_WindowEvent* e)
    {
        _e = e;
    }

    bool WindowEvent::operator==(uint8_t id) const
    {
        return _e->event == id;
    }

    int WindowEvent::data1() const
    {
        return _e->data1;
    }

    int WindowEvent::data2() const
    {
        return _e->data2;
    }
}