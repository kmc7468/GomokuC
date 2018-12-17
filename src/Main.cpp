#include <GomokuC/Application.hpp>

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
	
	return EXIT_SUCCESS;
}