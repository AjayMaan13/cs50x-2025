#include <iostream>
#include <fstream>
#include <iomanip>

#include "Drink.h"
#include "Utils.h"

using namespace std;
namespace seneca
{
    Drink::Drink(const char *name, double price, char size) : Billable()
    {
        Billable::name(name);
        Billable::price(price);

        if (size == 'S' || size == 'M' || size == 'L' || size == 'X')
        {
            m_size = size;
        }
        else
        {
            m_size = '\0';
        }
    }

    std::ostream &Drink::print(std::ostream &ostr) const
    {

        ostr << left << setw(28) << setfill('.') << (const char *)(*this);

        if (m_size == 'S')
        {
            ostr << "SML..";
        }
        else if (m_size == 'M')
        {
            ostr << "MID..";
        }
        else if (m_size == 'L')
        {
            ostr << "LRG..";
        }
        else if (m_size == 'X')
        {
            ostr << "XLR..";
        }
        else
        {
            ostr << ".....";
        }

        ostr << right << setw(7) << setfill(' ') << fixed << setprecision(2) << price() << endl;

        return ostr;
    }

    bool Drink::order()
    {
        int selection = -1;
        bool valid = false;

        cout << "         Drink Size Selection\n"
             << "          1- Small\n"
             << "          2- Medium\n"
             << "          3- Larg\n"
             << "          4- Extra Large\n"
             << "          0- Back\n"
             << "         > ";

        cin >> selection;

        switch (selection)
        {
        case 1:
            m_size = 'S';
            valid = true;
            break;
        case 2:
            m_size = 'M';
            valid = true;
            break;
        case 3:
            m_size = 'L';
            valid = true;
            break;
        case 4:
            m_size = 'X';
            valid = true;
            break;
        case 0:
        default:
            m_size = '\0';
            valid = false;
        }

        return valid;
    }

    bool Drink::ordered() const
    {
        return m_size != '\0';
    }

    std::ifstream &Drink::read(std::ifstream &file)
    {
        char name[26];
        double price;

        string baseName = m_name ? string(m_name) : "";
        double basePrice = Billable::price();
        char baseSize = m_size;

        file.getline(name, 26, ',');
        file >> price;
        file.ignore(1000, '\n');

        if (file)
        {
            Billable::name(name);
            Billable::price(price);
            m_size = '\0';
        }

        else
        {
            Billable::name(baseName.c_str());
            Billable::price(basePrice);
            m_size = baseSize;
        }

        return file;
    }

    double Drink::price() const
    {
        if (!ordered() || m_size == 'L')
        {
            return Billable::price();
        }
        switch (m_size)
        {
        case 'S':
            return Billable::price() * 0.5;

        case 'M':
            return Billable::price() * 0.75;

        case 'X':
            return Billable::price() * 1.5;

        default:
            return Billable::price();
        }
    }
}
