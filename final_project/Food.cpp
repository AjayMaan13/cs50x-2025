#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Food.h"
#include "Utils.h"

using namespace std;

namespace seneca
{
    Food::Food() : m_ordered(false), m_child(false), m_customize(nullptr) {}

    Food::~Food()
    {
        delete[] m_customize;
        m_customize = nullptr;
    }

    Food::Food(const Food &food) : Billable(food), m_ordered(food.m_ordered), m_child(food.m_child)
    {
        if (food.m_customize)
        {
            m_customize = new char[strlen(food.m_customize) + 1];
            strcpy(m_customize, food.m_customize);
        }
        else
        {
            m_customize = nullptr;
        }
    }

    Food &Food::operator=(const Food &food)
    {
        if (this != &food)
        {
            Billable::operator=(food);

            m_ordered = food.m_ordered;
            m_child = food.m_child;

            delete[] m_customize;

            if (food.m_customize)
            {
                m_customize = new char[strlen(food.m_customize) + 1];
                strcpy(m_customize, food.m_customize);
            }
            else
            {
                m_customize = nullptr;
            }
        }
        return *this;
    }

    std::ostream &Food::print(std::ostream &ostr) const
    {
        ostr << std::left << std::setw(28) << std::setfill('.') << (const char *)(*this);

        if (ordered())
        {
            ostr << (m_child ? "Child" : "Adult");
        }

        else
        {
            ostr << ".....";
        }

        ostr << right << setw(7) << setfill(' ') << fixed << setprecision(2) << price();

        if (&ostr == &std::cout && m_customize)
        {
            ostr << " >> ";

            ostr.write(m_customize, min((size_t)30, strlen(m_customize)));
        }
        ostr << endl;

        return ostr;
    }

    bool Food::order()
    {
        int selection = -1;

        cout << "         Food Size Selection\n"
             << "          1- Adult\n"
             << "          2- Child\n"
             << "          0- Back\n"
             << "         > ";

        cin >> selection;

        cin.ignore(1000, '\n');

        switch (selection)
        {
        case 1:
            m_child = false;
            m_ordered = true;
            break;

        case 2:
            m_child = true;
            m_ordered = true;
            break;

        case 0:
            m_ordered = false;
            delete[] m_customize;

            m_customize = nullptr;
            return false;

        default:
            cout << "Invalid selection. Please try again.\n";
            return false;
        }

        cout << "Special instructions\n> ";
        char temp[1000];

        cin.getline(temp, 1000);

        if (strlen(temp) == 0)
        {
            delete[] m_customize;
            m_customize = nullptr;
        }
        else
        {
            ut.alocpy(m_customize, temp);
        }

        return true;
    }

    bool Food::ordered() const

    {
        return m_ordered;
    }

    std::ifstream &Food::read(std::ifstream &file)
    {
        char name[100];
        double price;

        file.getline(name, 100, ',');

        file >> price;

        file.ignore(1000, '\n');

        if (file)
        {
            Billable::name(name);

            Billable::price(price);

            m_child = false;

            m_ordered = false;
            delete[] m_customize;

            m_customize = nullptr;
        }

        return file;
    }

    double Food::price() const
    {
        if (m_ordered && m_child)
        {
            return Billable::price() * 0.5;
        }

        return Billable::price();
    }
}
