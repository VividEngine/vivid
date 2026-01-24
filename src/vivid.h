// function inits

#ifndef VIVID_INCLUDE

#define VIVID_INCLUDE

#define VIVID_VERSION_STRING "0.0.0"
#define VIVID_VERSION_MAJOR 0
#define VIVID_VERSION_MINOR 0
#define VIVID_VERSION_PATCH 0

#include <string.h>
#include <stdbool.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

#ifdef __cplusplus
extern "C" {
#endif

void VE_Init(void);
TTF_Font* VE_Font(const char* font_name, int font_size);
SDL_Window* VE_Window(const char* window_title, int window_x, int window_y, bool window_resizable);
void VE_SetIcon(const char* icon, SDL_Window* window);
void VE_Quit(void);

#ifdef __cplusplus
}
#endif

#endif