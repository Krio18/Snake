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
#include <stdlib.h>
#include "../Snake/Snake.hpp"

class Apple {
    public:
        ~Apple() = default;

        Position spawnFood(const int WIDTH, const int HEIGHT, const int CELL_SIZE);
};
