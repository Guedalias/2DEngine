#include "../D2Engine/Renderer.h"

int main()
{
	Engine::Renderer rdr;

	bool running = true;

	rdr.Init();
	rdr.AddRenderComponent();
	while (running)
	{
		if (rdr.PollEvent() == false)
			running = false;
		rdr.Render();
	}

	return 0;
}