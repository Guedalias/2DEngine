#include "../D2Engine/Renderer.h"
#include "../D2Engine/RenderComponent.h"
#include "../D2Engine/IOEvent.h"

#include "GameObject.h"
#include "InputManager.h"
#include "Level.h"

#include "PingPongBall.h"
#include "FlyController.h"

#include <vector>
#include <chrono>
//https://stackoverflow.com/questions/2808398/easily-measure-elapsed-time

#include <iostream>

using s = std::chrono::duration<float>;
using ms = std::chrono::duration<float, std::milli>;

int main()
{
	Engine::Renderer rdr;

	bool running = true;
	float dt = 0.0f;

	rdr.Init(800, 600);

	GameEngine::GameObject go = GameEngine::GameObject();
	GameEngine::GameObject controller = GameEngine::GameObject();

	//UGLY AS FUCK
	go.AddRenderComponent(rdr.AddRenderComponent());
	go.AddScript(new Test::PingPongBall{});

	controller.AddRenderComponent(rdr.AddRenderComponent());
	controller.AddScript(new Test::FlyController{});

	GameEngine::InputManager* inputManager = GameEngine::InputManager::GetInstance();

	auto start = std::chrono::steady_clock::now(), end = std::chrono::steady_clock::now();

	while (running)
	{
		end = start;
		start = std::chrono::steady_clock::now();
		dt = std::chrono::duration_cast<s>(start- end).count();

		if (inputManager->Update(&rdr) == false)
			running = false;

		go.Update(dt);
		controller.Update(dt);

		rdr.Render();
	}

	{ // Test Save
		GameEngine::Level lvl;
		lvl.Init(&rdr);
		lvl.Save("./TestLvl.lvl");
	}
	{ // Test Load
		GameEngine::Level lvl;
		lvl.Init(&rdr);
		lvl.Load("./TestLvl.lvl");
	}
	
	return 0;
}