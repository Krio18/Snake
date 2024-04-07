/*
    Auteur: Killian Cottrelle
    Email: killian.cottrelle@epitech.eu
    Nom: Cottrelle
    Prénom: Killian
    Étudiant 2ᵉ année à Epitech,
    Eurpean Institute of Technology
*/
#include "Apple.hpp"

/**
 * @brief
 * @param WIDTH
 * @param HEIGHT
 * @param CELL_SIZE
 * @return Position
 */
Position Apple::spawnFood(const int WIDTH, const int HEIGHT, const int CELL_SIZE)
{
    int foodX = rand() % (WIDTH / CELL_SIZE) * CELL_SIZE;
    int foodY = rand() % (HEIGHT / CELL_SIZE) * CELL_SIZE;
    return Position(foodX, foodY);
}