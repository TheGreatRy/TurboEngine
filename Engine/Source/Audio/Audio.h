#pragma once
#include <fmod.hpp>
#include <map>
#include <string>
#include <iostream>

class Auydio
{
public:
	Auydio() = default;
	~Auydio() = default;

	bool Initialize();
	void Shutdown();
	void Update();

	bool AddSound(const std::string& name);
	bool PlaySound(const std::string& name);
	void StopSound(const std::string& name);
private:
	FMOD::System* m_audio{ nullptr };
	std::map<std::string, FMOD::Sound*> m_sounds;
};
