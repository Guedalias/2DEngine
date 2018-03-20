#include "Level.h"

#include "../D2Engine/RenderComponent.h"
#include "../D2Engine/Renderer.h"

#include "GameObject.h"

#include <iostream>
#include <fstream>

GameEngine::Level::Level()
{
}


GameEngine::Level::~Level()
{

}

#include "PingPongBall.h"

bool GameEngine::Level::Init(Engine::Renderer * rdr)
{


	GameEngine::GameObject* go = new GameEngine::GameObject();
	//UGLY AS FUCK
	go->AddRenderComponent(rdr->AddRenderComponent());
	go->AddScript(new Test::PingPongBall{});

	_entities.push_back(go);
	return false;
}

bool
GameEngine::Level::Update(float dt)
{
	size_t count = _entities.size();
	for (size_t i = 0; i < count; ++i)
	{
		_entities[i]->Update(dt);
	}
	return true;
}

bool GameEngine::Level::Load(const std::string & filename)
{
	std::streampos size;
	char * memblock;

	std::ifstream file(filename, std::ios::binary | std::ios::ate);
	if (file.is_open())
	{
		size = file.tellg();
		memblock = new char[size];
		file.seekg(0, std::ios::beg);
		file.read(memblock, size);
		file.close();

		std::cout << "the entire file content is in memory" << std::endl;

		delete[] memblock;

		//https://stackoverflow.com/questions/19036462/c-generic-object-factory-by-string-name
	}
	return false;
}

bool GameEngine::Level::Save(const std::string & filename)
{
	std::ofstream file(filename, std::ios::binary);
	
	if (file.is_open())
	{
		file << "LV";
		file << _entities.size();
		for (size_t i = 0; i < _entities.size(); ++i)
		{
			file << _entities[i];
		}
		file << _tiles.size();
		for (size_t i = 0; i < _tiles.size(); ++i)
		{
			file << _tiles[i];
		}
		file.close();
	}
	return false;
}
