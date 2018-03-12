#include "../D2Engine/Renderer.h"
#include "../D2Engine/RenderComponent.h"
#include "../D2Engine/IOEvent.h"

#include "GameObject.h"

#include "PingPongBall.h"

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

	//UGLY AS FUCK
	go.AddRenderComponent(rdr.AddRenderComponent());
	go.AddScript(new Test::PingPongBall{});

	std::vector<Engine::IOEvent> events;

	//EventManager.subcribe(gameObject, MOUSE_CLICK);

	auto start = std::chrono::steady_clock::now(), end = std::chrono::steady_clock::now();

	while (running)
	{
		end = start;
		start = std::chrono::steady_clock::now();
		dt = std::chrono::duration_cast<s>(start- end).count();

		//EventManager.update(rdr);
		if (rdr.PollEvent(events) == false)
			running = false;

		size_t eventCount = events.size();
		for (int i = 0; i < eventCount; ++i)
		{
			//consume dat events
		}
		events.clear();

		go.Update(dt);

		rdr.Render();
	}

	return 0;
}