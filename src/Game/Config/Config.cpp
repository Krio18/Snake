/*
** EPITECH PROJECT, 2024
** Snake
** File description:
** Config
*/

#include "Config.hpp"

Config::Key Config::getKey(SDL_Event event)
{
    switch (event.key.keysym.sym)
    {
        case SDLK_UP:
            return UP;
        case SDLK_DOWN:
            return DOWN;
        case SDLK_LEFT:
            return LEFT;
        case SDLK_RIGHT:
            return RIGHT;
        default:
            return OTHER;
    }
}

SDL_Texture *Config::displayMessage(Config::Key key, SDL_Window *_window, SDL_Renderer *_renderer)
{
    if (TTF_Init() != 0) {
        std::cerr << "Error initializing SDL_ttf : " << TTF_GetError() << std::endl;
        SDL_Quit();
        return nullptr;
    }

    TTF_Font* font = TTF_OpenFont("font/game_over.ttf", 240);
    SDL_Color color = {255, 255, 255};
    if (!font)
        std::cout << "Error" << std::endl;
    std::string text;

    switch (key)
    {
        case 0:
            text = "UP";
            break;
        case 1:
            text = "DOWN";
            break;
        case 2:
            text = "LEFT";
            break;
        case 3:
            text = "RIGHT";
            break;
        default:
            text = "NONE";
            break;
    }
    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* messageTexture = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);

    TTF_CloseFont(font);
    SDL_FreeSurface(surfaceMessage);

    return messageTexture;
}
