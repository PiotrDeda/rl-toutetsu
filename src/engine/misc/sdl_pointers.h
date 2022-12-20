#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <memory>

using SurfacePtr = std::shared_ptr<SDL_Surface>;
using TexturePtr = std::shared_ptr<SDL_Texture>;
using RendererPtr = std::shared_ptr<SDL_Renderer>;
using WindowPtr = std::shared_ptr<SDL_Window>;
using FontPtr = std::shared_ptr<TTF_Font>;

inline void surfaceDeleter(SDL_Surface* ptr) { if (ptr) SDL_FreeSurface(ptr); }
inline void textureDeleter(SDL_Texture* ptr) { if (ptr) SDL_DestroyTexture(ptr); }
inline void rendererDeleter(SDL_Renderer* ptr) { if (ptr) SDL_DestroyRenderer(ptr); }
inline void windowDeleter(SDL_Window* ptr) { if (ptr) SDL_DestroyWindow(ptr); }
inline void fontDeleter(TTF_Font* ptr) { if (ptr) TTF_CloseFont(ptr); }

inline SurfacePtr makeSurface(SDL_Surface* surface) { return {surface, surfaceDeleter}; }
inline TexturePtr makeTexture(SDL_Texture* texture) { return {texture, textureDeleter}; }
inline RendererPtr makeRenderer(SDL_Renderer* renderer) { return {renderer, rendererDeleter}; }
inline WindowPtr makeWindow(SDL_Window* window) { return {window, windowDeleter}; }
inline FontPtr makeFont(TTF_Font* font) { return {font, fontDeleter}; }
