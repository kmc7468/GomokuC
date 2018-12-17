#pragma once

#define GOMOKUC_MAJOR (1)
#define GOMOKUC_MINOR (0)
#define GOMOKUC_PATCH (0)

class Application final
{
public:
	Application() = delete;
	~Application() = delete;

public:
	Application& operator=(const Application& app) = delete;
	bool operator==(const Application& app) = delete;
	bool operator!=(const Application& app) = delete;

public:
	static bool run();
	static void exit();
};