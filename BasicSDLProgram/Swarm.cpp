#include "stdafx.h"
#include "Swarm.h"

namespace andrestaffa {
	Swarm::Swarm() {
		m_pParticle = new Particle[NPARTICLES];
		this->m_lastTime = 0;
	}


	void Swarm::Update(int elapsed) {

		int interval = elapsed - m_lastTime;

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			m_pParticle[i].Update(interval);
		}

		m_lastTime = elapsed;

	}

	Swarm::~Swarm() {
		delete[] m_pParticle;
	}

}

