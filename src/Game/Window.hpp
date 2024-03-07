#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include "Config/Config.hpp"

class Window {
    public:
        Window();
        ~Window();

        void loopGame();


    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Texture *_messageTexture;
        Config _config;
};
