#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int FPS = 30;

int main()
{
    int pos_y = 0;
    int pos_x = 0;
    int pos_w = 10;
    int pos_h = 30;
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Snake", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    while(1)
    {
        int start = SDL_GetTicks();
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                goto exit;
            }
            else if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_UP)
                {
                    pos_y -= 10;
                    pos_w = 10;
                    pos_h = 30;
                }
                if(event.key.keysym.sym == SDLK_DOWN)
                {
                    pos_y += 10;
                    pos_w = 10;
                    pos_h = 30;
                }
                if(event.key.keysym.sym == SDLK_RIGHT)
                {
                    pos_x += 10;
                    pos_w = 30;
                    pos_h = 10;
                }
                if(event.key.keysym.sym == SDLK_LEFT)
                {
                    pos_x -= 10;
                    pos_w = 30;
                    pos_h = 10;
                }
            }
        }
        SDL_SetRenderDrawColor(renderer, 1, 1, 1, 0xFF);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_Rect rect = {.x = pos_x, .y = pos_y, .w = pos_w, .h = pos_h};
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
        int end = SDL_GetTicks();
        SDL_Delay(1000 / FPS - (end - start));
    }
    exit:
    return 0;
}