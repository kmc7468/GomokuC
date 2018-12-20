#include <GomokuC/Scene.hpp>

#include <GomokuC/Application.hpp>

#include <cstdarg>
#include <cstdlib>
#include <sstream>
#include <string_view>

#include <Windows.h>

Scene::Scene(int width, int height)
	: width_(width), height_(height)
{}
Scene::Scene(const std::string& title)
	: title_(title)
{}
Scene::Scene(int width, int height, const std::string& title)
	: width_(width), height_(height), title_(title)
{}

void Scene::printf(const char* format, ...) const noexcept
{
	va_list ap;
	va_start(ap, format);
	std::vprintf(format, ap);
	va_end(ap);
}

int Scene::width() const noexcept
{
	return width_;
}
void Scene::width(int new_width) noexcept
{
	width_ = new_width;
}
int Scene::height() const noexcept
{
	return height_;
}
void Scene::height(int new_height) noexcept
{
	height_ = new_height;
}
std::string Scene::title() const
{
	return title_;
}
void Scene::title(const std::string& new_title)
{
	title_ = new_title;
}

void SceneManager::clear() noexcept
{
	gotoxy(0, 2);

	for (int i = 0; i < current_scene_->height() - 4; ++i)
	{
		for (int j = 0; j < current_scene_->width(); ++j)
		{
			std::putchar(' ');
		}
	}
}
void SceneManager::update() noexcept
{
	clear_all_();

	std::ostringstream ss;
	ss << "mode con: cols=" << current_scene_->width() << " lines=" << current_scene_->height();
	
	const std::string ss_output = ss.str();
	std::system(ss_output.data());

	draw_title_();
}
void SceneManager::scene(const ScenePtr& scene)
{
	current_scene_ = scene;
	update();
	current_scene_->first_draw();
}
void SceneManager::run()
{
	current_scene_->run();
}

void SceneManager::clear_all_() noexcept
{
	for (int i = 0; i < current_scene_->height(); ++i)
	{
		for (int j = 0; j < current_scene_->width(); ++j)
		{
			std::putchar(' ');
		}
	}
}
void SceneManager::draw_title_() noexcept
{
	static const std::string top_bar
		= "[ GomokuC v" + std::to_string(GOMOKUC_MAJOR) + '.' + std::to_string(GOMOKUC_MINOR) + '.' + std::to_string(GOMOKUC_PATCH) + " ]";
	static constexpr std::string_view under_bar = "(C) 2018. kmc7468 All rights reserved.";

	static const int top_bar_left_padding_size =
		(current_scene_->width() - static_cast<int>(top_bar.size())) / 2 +
		(static_cast<int>(top_bar.size()) & !(current_scene_->width() & 1));
	static const std::string top_bar_left_padding(top_bar_left_padding_size, ' ');

	gotoxy(0, 1);
	std::printf("%s%s", top_bar_left_padding.data(), top_bar.data());

	static const int under_bar_left_padding_size =
		(current_scene_->width() - static_cast<int>(under_bar.size())) / 2 +
		(static_cast<int>(under_bar.size()) & !(current_scene_->width() & 1));
	static const std::string under_bar_left_padding(under_bar_left_padding_size, ' ');

	gotoxy(0, current_scene_->height() - 2);
	std::printf("%s%s", under_bar_left_padding.data(), under_bar.data());
}

void gotoxy(int x, int y)
{
	COORD cursor;
	cursor.X = static_cast<SHORT>(x);
	cursor.Y = static_cast<SHORT>(y);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}
void cursor(bool visible)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = visible;
	info.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}