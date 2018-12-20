#include <GomokuC/Application.hpp>
#include <GomokuC/Scene.hpp>
#include <GomokuC/Scenes/MainMenuScene.hpp>

#include <cstdio>
#include <cstdlib>

int main()
{
	if (!Application::run())
	{
		std::fprintf(stderr, "Failed to initialize this application.");
		return EXIT_FAILURE;
	}
	struct ApplicationRAII
	{
		~ApplicationRAII()
		{
			Application::exit();
		}
	} application_raii;

	SceneManager mgr;
	mgr.scene(std::make_shared<MainMenuScene>());
	mgr.run();

	return EXIT_SUCCESS;
}