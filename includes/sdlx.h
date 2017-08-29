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

#ifndef SDLX_H
#define SDLX_H

#include "constants.h"
#include "event.h"
#include "image.h"
#include "sound.h"
#include "window.h"
#include "device.h"

namespace sdlx
{
    struct Initializer
    {
        Initializer()
        {
            const int IMG_FLAGS = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;

            const int MIX_FLAGS = MIX_INIT_FLAC | MIX_INIT_OGG;

            if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
                std::cout << "SDL_Init: " << SDL_GetError() << std::endl;
            if (TTF_Init() == -1)
                std::cout << "TTF_Init: " << TTF_GetError() << std::endl;
            if ((IMG_Init(IMG_FLAGS) & IMG_FLAGS) != IMG_FLAGS)
                std::cout << "Failed to initialize JPG, PNG, & TIF support." 
                          << std::endl << "IMG_Init: " << IMG_GetError()
                          << std::endl;
            if ((Mix_Init(MIX_FLAGS) & MIX_FLAGS) != MIX_FLAGS)
                std::cout << "Failed to initialize FLAG, MOD, MP3, & OGG support." 
                          << std::endl <<"MIX_Init: " << Mix_GetError() 
                          << std::endl;
        }
        ~Initializer()
        {
            while (Mix_Init(0)) Mix_Quit();
            TTF_Quit();
            IMG_Quit();
            SDL_Quit();     
        }
    }; 

    inline int get_ticks()
    {
        return SDL_GetTicks();
    }

    inline void delay(uint32_t t)
    {
        SDL_Delay(t);
    }

    static Initializer sdlx_init;
}

#endif