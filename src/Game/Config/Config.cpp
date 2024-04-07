/*
    Auteur: Killian Cottrelle
    Email: killian.cottrelle@epitech.eu
    Nom: Cottrelle
    Prénom: Killian
    Étudiant 2ᵉ année à Epitech,
    Eurpean Institute of Technology
*/

#include "Config.hpp"

/**
 * @brief
 * @param event
 * @return Key
 */
Key Config::getKey(SDL_Event event)
{
    switch (event.key.keysym.sym)
    {
        case SDLK_UP:
            _Key = UP;
            break;
        case SDLK_DOWN:
            _Key = DOWN;
            break;
        case SDLK_LEFT:
            _Key = LEFT;
            break;
        case SDLK_RIGHT:
            _Key = RIGHT;
            break;
    }
    return _Key;
}
