#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <iomanip>

using namespace std;

namespace andrestaffa {

	class Screen {
	public:
		const static int SCREEN_WIDTH = 2560;
		const static int SCREEN_HEIGHT = 1440;
	private:
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
		SDL_Texture *m_texture;
		Uint32 *m_buffer1;
		Uint32 *m_buffer2;
	public:
		Screen();
		~Screen();
		bool Init();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		void update();
		void BoxBlur();
		bool ProccessEvent();
		void close();
	};
}


