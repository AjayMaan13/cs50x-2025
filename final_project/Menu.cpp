#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>

#include "Menu.h"
#include "Utils.h"
#include "constants.h"

using namespace std;

namespace seneca
{

	void MenuItem::setSafeEmpty()
	{
		menuContent = nullptr;
		menuIndentCount = 0;
		menuIndentCharSize = 0;
		menuObjectCount = -1;
	}

	MenuItem::MenuItem(const char *content, unsigned indentCount, unsigned indentSize, int objectCount)
	{
		if (content == nullptr || *content == '\0' ||
			indentCount > 4 || indentSize > 4 ||
			(objectCount > (int)MaximumNumberOfMenuItems && objectCount != -1))
		{
			setSafeEmpty();
		}
		else
		{
			const char *ptr = content;
			while (*ptr != '\0' && isspace(*ptr))
			{
				++ptr;
			}

			if (*ptr == '\0')
			{
				setSafeEmpty();
			}
			else
			{
				ut.alocpy(menuContent, content);
				menuIndentCount = indentCount;
				menuIndentCharSize = indentSize;
				menuObjectCount = objectCount;
			}
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] menuContent;
	}

	MenuItem::operator bool() const
	{
		return menuContent != nullptr;
	}

	std::ostream &MenuItem::display(std::ostream &ostr) const
	{
		if (!*this)
		{
			return ostr;
		}

		for (unsigned i = 0; i < menuIndentCount * menuIndentCharSize; i++)
		{
			ostr << ' ';
		}

		if (menuObjectCount >= 0)
		{
			if (menuObjectCount < 10)
				ostr << ' ';
			ostr << menuObjectCount << "- ";
		}

		const char *ptr = menuContent;
		while (std::isspace(*ptr))
			++ptr;
		ostr << ptr;

		return ostr;
	}

	Menu::Menu(const char *title, const char *exitOption, unsigned indent, unsigned indentSize) : menuIndent(indent), menuIndentSize(indentSize),
																								  menuItemCount(0),
																								  menuTitle(title, indent, indentSize, -1),
																								  menuExitOption(exitOption, indent, indentSize, 0),
																								  menuEntryPrompt("> ", indent, indentSize, -1)
	{
		for (unsigned i = 0; i < MaximumNumberOfMenuItems; i++)
		{
			menuItems[i] = nullptr;
		}
	}

	Menu &Menu::operator<<(const char *content)
	{
		if (menuItemCount < MaximumNumberOfMenuItems)
		{
			menuItems[menuItemCount] = new MenuItem(content, menuIndent, menuIndentSize, menuItemCount + 1);
			++menuItemCount;
		}

		return *this;
	}

	Menu::~Menu()
	{
		for (unsigned i = 0; i < menuItemCount; i++)
		{
			delete menuItems[i];
			menuItems[i] = nullptr;
		}
	}

	size_t Menu::select() const
	{

		if (menuTitle)
		{
			menuTitle.display(cout);
			cout << endl;
		}

		for (unsigned i = 0; i < menuItemCount; i++)
		{
			if (menuItems[i])
			{
				menuItems[i]->display(cout);
				cout << endl;
			}
		}

		menuExitOption.display(cout);
		cout << endl;

		menuEntryPrompt.display(std::cout);

		int selection = ut.getInt(0, menuItemCount);
		return selection;
	}

	size_t operator<<(std::ostream &ostr, const Menu &m)
	{

		if (&ostr == &cout)
		{
			return m.select();
		}
		else
		{
			if (m.menuTitle)
			{
				m.menuTitle.display(ostr);
				ostr << endl;
			}

			for (unsigned i = 0; i < m.menuItemCount; i++)
			{
				if (m.menuItems[i])
				{
					m.menuItems[i]->display(ostr);
					ostr << endl;
				}
			}

			if (m.menuExitOption)
			{
				m.menuExitOption.display(ostr);
				ostr << endl;
			}

			return 0;
		}
	}
}
