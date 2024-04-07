/*
    Auteur: Killian Cottrelle
    Email: killian.cottrelle@epitech.eu
    Nom: Cottrelle
    Prénom: Killian
    Étudiant 2ᵉ année à Epitech,
    Eurpean Institute of Technology
*/

#pragma once

#include "Config/Config.hpp"
#include "Config/Key.hpp"
#include "Items/Apple.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Window {
    public:
        Window();
        ~Window();

        void update();
        void render();
        void run();

    private:
        const int _WINDOW_WIDTH = 800;
        const int _WINDOW_HEIGHT = 600;
        const int _CELL_SIZE = 20;
        bool _RUNNING;

        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Texture *_squareTexture;

        Config _config;
        Key _Key;
        Apple _Apple;

        std::vector<Position> _snake;
        Position _food;
        SDL_Event _event;
};
