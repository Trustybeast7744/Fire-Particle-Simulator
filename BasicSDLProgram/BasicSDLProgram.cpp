// BasicSDLProgram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <SDL.h>
#include <stdio.h>
#include "Screen.h"
#include "Swarm.h"
#include <time.h>

using namespace std;
using namespace andrestaffa;

Screen *screen = new Screen();
Swarm *swarm = new Swarm();

int main(int argc, char *argv[]) {

	srand(time(NULL));

	if (screen->Init() == false) {
		cout << "Cannot create Window" << endl;
	}

	// game loop
	while (true) {

		int elapse = SDL_GetTicks();

		
		swarm->Update(elapse);

		unsigned char red = ((1 + sin(elapse * 0.0001)) * 128);
		unsigned char green = ((1 + sin(elapse * 0.0002)) * 128);
		unsigned char blue = ((1 + sin(elapse * 0.0003)) * 128);
		
		const Particle * const pParticles = swarm->getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen->setPixel(x, y, red, green, blue);

		}

		//for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			//for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				//screen->setPixel(x, y, red, green, blue);
			//}
		//}
		

		screen->BoxBlur();

		screen->update();

		if (screen->ProccessEvent() == false) {
			break;
		}
	}


	screen->close();
	delete screen;
	delete swarm;
    return 0;
}

