#include "../D2Engine/Renderer.h"
#include "../D2Engine/RenderComponent.h"

int main()
{
	Engine::Renderer rdr;

	bool running = true;

	float x = 0.0f, y = 0.0f;
	float xvel = 0.8f, yvel = 0.8f;

	rdr.Init(800, 600);
	Engine::RenderComponent* rc = rdr.AddRenderComponent();
	while (running)
	{
		if (rdr.PollEvent() == false)
			running = false;
		rc->SetPosition(Engine::Vector2D{ x, y });
		x += xvel;
		y += yvel;
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