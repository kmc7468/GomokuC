#pragma once

#include <memory>
#include <string>

class SceneManager;

class Scene
{
	friend class SceneManager;

public:
	Scene(const Scene& scene) = delete;
	virtual ~Scene() = default;

protected:
	Scene() = default;
	Scene(int width, int height);
	Scene(const std::string& title);
	Scene(int width, int height, const std::string& title);

public:
	Scene& operator=(const Scene& scene) = delete;
	bool operator==(const Scene& scene) = delete;
	bool operator!=(const Scene& scene) = delete;

protected:
	void printf(const char* format, ...) const noexcept;

	virtual void first_draw() = 0;
	virtual void run() = 0;

public:
	int width() const noexcept;
	void width(int new_width) noexcept;
	int height() const noexcept;
	void height(int new_height) noexcept;
	std::string title() const;
	void title(const std::string& new_title);

private:
	int width_ = 80, height_ = 25;
	std::string title_;
};

using ScenePtr = std::shared_ptr<Scene>;

class SceneManager final
{
public:
	SceneManager() = default;
	SceneManager(const SceneManager& mgr) = delete;
	~SceneManager() = default;

private:
	SceneManager& operator=(const SceneManager& mgr) = delete;
	bool operator==(const SceneManager& mgr) = delete;
	bool operator!=(const SceneManager& mgr) = delete;

public:
	void clear() noexcept;
	void update() noexcept;
	void scene(const ScenePtr& scene);
	void run();

private:
	void clear_all_() noexcept;
	void draw_title_() noexcept;

private:
	ScenePtr current_scene_ = nullptr;
};

void gotoxy(int x, int y);
void cursor(bool visible);