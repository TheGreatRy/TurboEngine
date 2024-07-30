#pragma once
#include "Particle.h"
#include <vector>

class ParticleSystem
{
public:
	ParticleSystem(int maxSize = 5000)
	{
		m_particles.resize(maxSize);
	}
	void Update(float dt);
	void Draw(Renderer& renderer);

	void AddParticles(const Particle::Data& data);
private:
	Particle* GetFreeParticle();
private:
	std::vector<Particle> m_particles;

};