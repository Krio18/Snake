#include "Window.hpp"

Window::Window()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0) {
        printf("Error initializing SDL : %s\n", SDL_GetError());
        exit(84);
    }

    _window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480,
    SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALWAYS_ON_TOP);
    if (!_window) {
        std::cerr << "Error creating window : " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(84);
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == NULL) {
        std::cerr << "Error creating render : " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(_window);
        TTF_Quit();
        SDL_Quit();
        exit(84);
    }

    _messageTexture = nullptr;
}

Window::~Window()
{
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    if (_messageTexture != nullptr) {
        SDL_DestroyTexture(_messageTexture);
    }
    SDL_Quit();
}

void Window::loopGame() {
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            if (event.type == SDL_KEYDOWN) {
                Config::Key key = _config.getKey(event);
                _messageTexture = _config.displayMessage(key, _window, _renderer);
            }
        }

        SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
        SDL_RenderClear(_renderer);


        if (_messageTexture != nullptr) {
            SDL_Rect destRect;
            destRect.x = 200;
            destRect.y = 100;
            destRect.w = 200;
            destRect.h = 200;
            SDL_RenderCopy(_renderer, _messageTexture, NULL, &destRect);
        }

        SDL_RenderPresent(_renderer);

        SDL_Delay(16);
    }
}
