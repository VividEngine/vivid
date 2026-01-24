#include "vivid.h"

void VE_Init(void) {
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
}

TTF_Font VE_Font(const char* font_name, int font_size) {
  if(!font_name || !font_size) return;
  return TTF_OpenFont(font_name, font_size);
}

void VE_SetIcon(const char* icon_path, SDL_Window* window) {
  if(!icon_path || !window) return;
  SDL_Surface* icon = IMG_Load(icon_path);
  SDL_SetWindowIcon(window, icon);
  SDL_DestroySurface(icon);
}

void VE_Quit(void) {
  SDL_Quit();
  TTF_Quit();
}