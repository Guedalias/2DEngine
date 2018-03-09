#include "../D2Engine/Renderer.h"
#include "../D2Engine/RenderComponent.h"
#include "../D2Engine/IOEvent.h"

#include <vector>

int main()
{
	Engine::Renderer rdr;

	bool running = true;

	float x = 0.0f, y = 0.0f;
	float xvel = 0.8f, yvel = 0.8f;
	float deltaTime;

	rdr.Init(800, 600);
	Engine::RenderComponent* rc = rdr.AddRenderComponent();

	std::vector<Engine::IOEvent> events;

	//EventManager.subcribe(gameObject, MOUSE_CLICK);

	while (running)
	{
		//EventManager.update(rdr);
		if (rdr.PollEvent(events) == false)
			running = false;

		int eventCount = events.size();
		for (int i = 0; i < eventCount; ++i)
		{
			//consume dat events
		}
		events.clear();



		rc->SetPosition(Engine::Vector2D<float>{ x, y });
		x += xvel;//* dt;
		y += yvel;//* dt;
		if (x > 800)
			xvel = -0.8f;
		else if (x < 0)
			xvel = 0.8f;

		if (y > 600)
			yvel = -0.8f;
		else if (y < 0)
			yvel = 0.8f;
		rdr.Render();
	}

	return 0;
}