#pragma once

#include <GomokuC/Scene.hpp>

class MainMenuScene final : public Scene
{
public:
	MainMenuScene() = default;
	MainMenuScene(const MainMenuScene& scene) = delete;
	virtual ~MainMenuScene() override = default;

public:
	MainMenuScene& operator=(const MainMenuScene& scene) = delete;
	bool operator==(const MainMenuScene& scene) = delete;
	bool operator!=(const MainMenuScene& scene) = delete;

protected:
	virtual void first_draw() override;
	virtual void run() override;

private:
	int selected_ = 1;
};