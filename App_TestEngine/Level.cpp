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

	std::ifstream file(filename, std::ios::binary | std::ios::ate);
	if (file.is_open())
	{
		file.seekg(0, std::ios::beg);
		
		
		static const size_t HEADER_SIZE = sizeof(char) * 2;
		
		int readCount = 0;

		char		header[2];
		file.read(header, HEADER_SIZE);
		
		if (!strcmp(header, "LV"))
			return false;
		readCount += HEADER_SIZE;

		int entitiesCount = 0;
		file.read((char*)&entitiesCount, sizeof(int));
		readCount += sizeof(int);

		for (int i = 0; i < entitiesCount; ++i)
		{
			GameEngine::GameObject* go = new GameEngine::GameObject();
			go->ReadConstruct(file/*, rdr*/);
			
			_entities.push_back(go);
		}

		file.close();
		//https://stackoverflow.com/questions/19036462/c-generic-object-factory-by-string-name
	}
	return false;
}

bool GameEngine::Level::Save(const std::string & filename)
{
	std::ofstream file(filename, std::ios::binary);
	
	if (file.is_open())
	{
		file.write("LV", 2 * sizeof(char));
		size_t size = _entities.size();
		file.write((char*)&size, sizeof(size_t));
		for (size_t i = 0; i < _entities.size(); ++i)
		{
			_entities[i]->Write(file);
		}

		size = _tiles.size();
		file.write((char*)&size, sizeof(size_t));
		for (size_t i = 0; i < _tiles.size(); ++i)
		{
			_tiles[i]->Write(file);
		}
		file.close();
	}
	return false;
}
