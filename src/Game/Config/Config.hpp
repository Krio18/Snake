/*
** EPITECH PROJECT, 2024
** Snake
** File description:
** Config
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>


class Config {
    public:
        ~Config() = default;

        enum Key {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            OTHER
        };

        Config::Key getKey(SDL_Event event);
        SDL_Texture *displayMessage(Config::Key, SDL_Window *_window, SDL_Renderer *_renderer);

    private:
        Config::Key _Key;
};
