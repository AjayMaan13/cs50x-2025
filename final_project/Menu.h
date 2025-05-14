#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>

#include "constants.h"

namespace seneca
{

	class Menu;

	class MenuItem
	{
		friend class Menu;
		friend size_t operator<<(std::ostream &ostr, const Menu &m);

	private:
		char *menuContent;
		unsigned int menuIndentCount;
		unsigned int menuIndentCharSize;
		int menuObjectCount;

		void setSafeEmpty();

		MenuItem(const char *content, unsigned indentCount, unsigned indentSize, int objectCount);

		~MenuItem();

		MenuItem(const MenuItem &other) = delete;
		MenuItem &operator=(const MenuItem &other) = delete;

		operator bool() const;

		std::ostream &display(std::ostream &ostr = std::cout) const;
	};

	class Menu
	{
	private:
		unsigned menuIndent;

		unsigned menuIndentSize;

		unsigned menuItemCount;

		MenuItem menuTitle;

		MenuItem menuExitOption;

		MenuItem menuEntryPrompt;

		MenuItem *menuItems[MaximumNumberOfMenuItems];

	public:
		Menu(const char *title, const char *exitOption = "Exit", unsigned indent = 0, unsigned indentSize = 3);

		Menu &operator<<(const char *content);

		~Menu();

		Menu(const Menu &) = delete;

		Menu &operator=(const Menu &) = delete;

		Menu(Menu &&) = delete;

		Menu &operator=(Menu &&) = delete;

		size_t select() const;

		friend size_t operator<<(std::ostream &ostr, const Menu &m);
	};
}
#endif // !SENECA_MENU_H