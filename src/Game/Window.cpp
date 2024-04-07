/*
    Auteur: Killian Cottrelle
    Email: killian.cottrelle@epitech.eu
    Nom: Cottrelle
    Prénom: Killian
    Étudiant 2ᵉ année à Epitech,
    Eurpean Institute of Technology
*/

#include "Window.hpp"

/**
 * @brief Construct a new Window:: Window object
 */
Window::Window()
{
    _RUNNING = true;
    srand(time(NULL));

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0) {
        printf("Error initializing SDL : %s\n", SDL_GetError());
        exit(84);
    }

    _window = SDL_CreateWindow("_snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _WINDOW_WIDTH, _WINDOW_HEIGHT, 0);
    if (!_window) {
        std::cerr << "Error creating window : " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(84);
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == NULL) {
        std::cerr << "Error creating render : " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(_window);
        SDL_Quit();
        exit(84);
    }

    _snake.push_back(Position(_WINDOW_WIDTH / 2, _WINDOW_HEIGHT / 2));
    _food = _Apple.spawnFood(_WINDOW_WIDTH, _WINDOW_HEIGHT, _CELL_SIZE);
    _Key = static_cast<Key>(rand() % 4);
}

/**
 * @brief Destroy the Window:: Window object
 */
Window::~Window()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

/**
 * @brief
 */
void Window::update()
{
    for (int i = _snake.size() - 1; i > 0; --i)
        _snake[i] = _snake[i - 1];

    switch (_Key) {
        case UP:
            _snake[0].y -= _CELL_SIZE;
            break;
        case DOWN:
            _snake[0].y += _CELL_SIZE;
            break;
        case LEFT:
            _snake[0].x -= _CELL_SIZE;
            break;
        case RIGHT:
            _snake[0].x += _CELL_SIZE;
            break;
    }

    if (_snake[0].x == _food.x && _snake[0].y == _food.y) {
        _snake.push_back(_snake[_snake.size() - 1]);
        _food = _Apple.spawnFood(_WINDOW_WIDTH, _WINDOW_HEIGHT, _CELL_SIZE);
    } else {
        if (_snake[0].x < 0 || _snake[0].x >= _WINDOW_WIDTH || _snake[0].y < 0 || _snake[0].y >= _WINDOW_HEIGHT) {
            _RUNNING = false;
            return;
        }

        for (size_t i = 1; i < _snake.size(); ++i) {
            if (_snake[0].x == _snake[i].x && _snake[0].y == _snake[i].y) {
                _RUNNING = false;
                return;
            }
        }
    }
}

/**
 * @brief
 */
void Window::render()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);

    SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 255);
    for (const auto& segment : _snake) {
        SDL_Rect rect = {segment.x, segment.y, _CELL_SIZE, _CELL_SIZE};
        SDL_RenderFillRect(_renderer, &rect);
    }

    SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
    SDL_Rect _foodRect = {_food.x, _food.y, _CELL_SIZE, _CELL_SIZE};
    SDL_RenderFillRect(_renderer, &_foodRect);

    SDL_RenderPresent(_renderer);
}

/**
 * @brief
 */
void Window::run()
{
    while (_RUNNING) {
        while (SDL_PollEvent(&_event)) {
            if (_event.type == SDL_QUIT)
                _RUNNING = false;
            if (_event.type == SDL_KEYDOWN)
                _Key = _config.getKey(_event);
        }
        update();
        render();
        SDL_Delay(100);
    }
}
