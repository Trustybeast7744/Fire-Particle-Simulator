#include "stdafx.h"
#include "Particle.h"
#include <stdlib.h>

namespace andrestaffa {
	Particle::Particle() {
		Init();
	}

	void Particle::Init() {
		this->m_x = 0;
		this->m_y = 0;

		this->m_direction = (2.0 * M_PI * rand()) / RAND_MAX;
		this->m_speed = (0.01 * rand()) / RAND_MAX;

		m_speed *= m_speed;
	}


	void Particle::Update(int interval) {

		m_direction += 0.01;

		double xSpeed = m_speed * cos(m_direction);
		double ySpeed = m_speed * sin(m_direction);

		m_x += xSpeed * interval;
		m_y += ySpeed * interval;

		if (m_x < -1 || m_x >= 1 || m_y < -1 || m_y >= 1) {
			Init();
		}

	}

	Particle::~Particle()
	{
	}

}

