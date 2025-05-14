#include <iostream>
#include "Ordering.h"
#include "Utils.h"
#include "Billable.h"
#include "Drink.h"
#include "Food.h"
#include "Menu.h"
#include "constants.h"

using namespace std;
using namespace seneca;

int main()
{
    Ordering ord("drinks.csv", "foods.csv");

    if (!ord)
    {
        cout << "Error loading menu data files!" << endl;
        return 1;
    }

    bool done = false;
    int selection;

    while (!done)
    {
        cout << "Seneca Restaurant " << endl;
        cout << " 1- Order" << endl;
        cout << " 2- Print Bill" << endl;
        cout << " 3- Start a New Bill" << endl;
        cout << " 4- List Foods" << endl;
        cout << " 5- List Drinks" << endl;
        cout << " 0- End Program" << endl;
        cout << "> ";
        cin >> selection;
        switch (selection)
        {
        case 1:
        {
            bool backToMain = false;
            while (!backToMain)
            {
                cout << "   Order Menu" << endl;
                cout << "    1- Food" << endl;
                cout << "    2- Drink" << endl;
                cout << "    0- Back to main menu" << endl;
                cout << "   > ";
                int orderOption;
                cin.clear();
                cin >> orderOption;

                switch (orderOption)
                {
                case 1:
                    cin.clear();
                    ord.orderFood();
                    break;
                case 2:
                    cin.clear();
                    ord.orderDrink();
                    break;
                case 0:
                    backToMain = true;
                    break;
                default:
                    cout << "   Invalid selection, try again." << endl;
                }
            }
            break;
        }
        case 2:
            ord.printBill(cout);
            break;
        case 3:
            ord.resetBill();
            break;
        case 4:
            ord.listFoods();
            break;
        case 5:
            ord.listDrinks();
            break;
        case 0:
            // case 0 to exit
            if (ord.hasUnsavedBill())
            {
                cout << "You have bills that are not saved, are you sure you want to exit?" << endl;
                cout << " 1- Yes" << endl;
                cout << " 0- No" << endl;
                cout << "> ";
                int confirm;
                cin >> confirm;
                if (confirm == 1)
                {
                    done = true;
                }
            }
            else
            {
                done = true;
            }
            break;
        default:
            cout << "Invalid selection, try again." << endl; // error
        }
    }

    return 0;
}