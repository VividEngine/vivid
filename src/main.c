#include <string.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

int main(void) {
  int window_x = 480;
  int window_y = 360;
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  SDL_Window *window = SDL_CreateWindow(
    "VividEngine",
    window_x,
    window_y,
    SDL_WINDOW_RESIZABLE
  );
  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
  TTF_Font *font_regular = TTF_OpenFont("OpenSauceOne-Regular.ttf", 24);
  int running = 1;
  SDL_Surface* icon = IMG_Load("icon_tr.png");
  SDL_SetWindowIcon(window, icon);
  SDL_DestroySurface(icon);
  SDL_Color color_white = {255, 255, 255, 255};
  SDL_Surface *txt_surface = TTF_RenderText_Blended(font_regular, "Vivid Engine", strlen("Vivid Engine"), color_white);
  SDL_Texture *txt_texture = SDL_CreateTextureFromSurface(renderer, txt_surface);
  SDL_DestroySurface(txt_surface);
  SDL_Event event;
  while(running) {
    while(SDL_PollEvent(&event)) {
      switch(event.type) {
        case SDL_EVENT_QUIT:
          running = 0;
          break;
        case SDL_EVENT_WINDOW_RESIZED:
          window_x = event.window.data1;
          window_y = event.window.data2;
          break;
      }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_FRect txt_rect = {window_x / 2, window_y / 2, 0.0f, 0.0f};
    SDL_GetTextureSize(txt_texture, &txt_rect.w, &txt_rect.h);
    SDL_RenderTexture(renderer, txt_texture, NULL, &txt_rect);
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyTexture(txt_texture);
  TTF_CloseFont(font_regular);
  TTF_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
