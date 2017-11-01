#pragma once
#include <stdlib.h>
#include <SDL.h>
#include <math.h>

using namespace std;

namespace andrestaffa {
	struct Particle {

		double m_x;
		double m_y;

		double m_speed;
		double m_direction;

	public:
		Particle();
		void Init();
		void Update(int interval);
		~Particle();
	};

}

