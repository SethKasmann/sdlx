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

#include <iostream>
#include "sound.h"
#include "sdllib.h"

namespace sdlx {

    /*************************************************************************
        Class Sound
    *************************************************************************/

    Sound::Sound(const char* filename)
    {
        _on = true;

        Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,
                      MIX_DEFAULT_FORMAT,
                      MIX_DEFAULT_CHANNELS, 512);
        sample = Mix_LoadWAV(filename);
        if (sample == nullptr)
        {
            std::cout << "Error in Sound: Mix_LoadWAV returs NULL.\n"
                      << Mix_GetError() << std::endl;
        }
    }

    Sound::~Sound()
    {
        Mix_HaltChannel(-1);
        Mix_CloseAudio();
        Mix_FreeChunk(sample);
        sample = nullptr;
    }

    void Sound::on()
    {
        _on = true;
    }

    void Sound::off()
    {
        _on = false;
    }

    void Sound::play()
    {
        if (_on)
            Mix_PlayChannel(-1, sample, 0);
    }

    /*************************************************************************
        Class Music
    *************************************************************************/

    Music::Music(const char* filename)
    {
        _on = true;
        Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,
                      MIX_DEFAULT_FORMAT,
                      MIX_DEFAULT_CHANNELS, 512);
        sample = Mix_LoadMUS(filename);
        if (sample == nullptr) 
        {
            std::cout << "Error in Sound: Mix_LoadMUS returns NULL.\n"
                      << Mix_GetError() << std::endl;
        }
    }

    Music::~Music()
    {
        Mix_HaltChannel(-1);
        Mix_CloseAudio();
        free();
        sample = nullptr;
    }

    void Music::load(const char* filename)
    {
        if (filename != nullptr)
        {
            free();
            sample = Mix_LoadMUS(filename);
        }
    }

    void Music::free()
    {
        if (sample != nullptr)
        {
            Mix_HaltMusic();
            Mix_FreeMusic(sample);
            sample = nullptr;
        }
    }

    void Music::on()
    {
        _on = true;
        play();
    }

    void Music::off()
    {
        Mix_HaltMusic();
        _on = false;
    }

    void Music::play()
    {
        if (_on)
            Mix_PlayMusic(sample, -1);
    }

    void Music::stop()
    {
        Mix_HaltMusic();
    }

}