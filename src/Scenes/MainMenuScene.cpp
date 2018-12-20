#include <GomokuC/Scenes/MainMenuScene.hpp>

#include <string_view>
#include <Windows.h>

void MainMenuScene::first_draw()
{
	static constexpr std::string_view menu[] =
	{
		"┌─────────────────┐\n",
		"│   1. 새로운 방  │\n",
		"│   2.  기존 방   │\n",
		"│   3. 혼자 하기  │\n",
		"│   4. 기보 보기  │\n",
		"│   5. 게임 종료  │\n",
		"└─────────────────┘"
	};

	cursor(false);
	gotoxy(0, 4);

	constexpr int left_padding_size = (80 - 20) / 2;
	const std::string left_padding(left_padding_size, ' ');

	for (std::string_view line : menu)
	{
		printf("%s%s", left_padding.data(), line.data());
	}
}
void MainMenuScene::run()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_UP) & 0x1 && selected_ != 1) --selected_;
		else if (GetAsyncKeyState(VK_DOWN) & 0x1 && selected_ != 5) ++selected_;
		else if (GetAsyncKeyState(VK_RETURN) & 0x1)
		{
			// TODO
		}

		gotoxy(34, 4 + selected_);
		printf("→");

		if (selected_ != 1)
		{
			gotoxy(34, 3 + selected_);
			printf("%d.", selected_ - 1);
		}
		if (selected_ != 5)
		{
			gotoxy(34, 5 + selected_);
			printf("%d.", selected_ + 1);
		}
	}	
}