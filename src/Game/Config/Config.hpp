/*
    Auteur: Killian Cottrelle
    Email: killian.cottrelle@epitech.eu
    Nom: Cottrelle
    Prénom: Killian
    Étudiant 2ᵉ année à Epitech,
    Eurpean Institute of Technology
*/
#pragma once

#include <SDL2/SDL.h>
#include "Key.hpp"


class Config {
    public:
        ~Config() = default;

        Key getKey(SDL_Event event);

    private:
        Key _Key;
};
