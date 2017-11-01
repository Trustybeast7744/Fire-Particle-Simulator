#pragma once

#include "Particle.h"

namespace andrestaffa {
	class Swarm {
	public:
		const static int NPARTICLES = 10000;
	private:
		Particle *m_pParticle;
		int m_lastTime;
	public:
		Swarm();
		~Swarm();
		void Update(int elapsed);
		const Particle * const getParticles() { return m_pParticle; };
	};

}


