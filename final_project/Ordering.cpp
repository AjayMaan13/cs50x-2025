#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "constants.h"
#include "Food.h"
#include "Drink.h"
#include "Billable.h"
#include "Menu.h"
#include "Utils.h"
#include "Ordering.h"

using namespace std;
using namespace seneca;

int flag = 0;
namespace seneca
{

   Ordering::Ordering(const char *drinkFile, const char *foodFile)
   {
      drinkCount = countRecords(drinkFile);
      foodCount = countRecords(foodFile);
      ifstream din(drinkFile), fin(foodFile);
      if (din && fin)
      {
         drinks = new Drink[drinkCount];
         foods = new Food[foodCount];
         for (size_t i = 0; i < drinkCount && din; ++i)
            drinks[i].read(din);
         for (size_t i = 0; i < foodCount && fin; ++i)
            foods[i].read(fin);
         if (din.fail() || fin.fail())
         {
            delete[] drinks;
            delete[] foods;
            drinks = nullptr;
            foods = nullptr;
         }
      }
   }

   Ordering::~Ordering()
   {
      delete[] drinks;
      delete[] foods;
      for (size_t i = 0; i < billItemCount; ++i)
         delete billItems[i];
   }

   size_t Ordering::countRecords(const char *file) const
   {
      size_t count = 0;
      ifstream fin(file);
      char ch;

      while (fin.get(ch))
      {
         if (ch == '\n')
            ++count;
      }
      return count;
   }

   Ordering::operator bool() const { return drinks && foods; }
   size_t Ordering::noOfBillItems() const { return billItemCount; }
   bool Ordering::hasUnsavedBill() const { return billItemCount > 0; }

   void Ordering::listFoods() const
   {
      cout << "List Of Avaiable Meals\n========================================\n";
      for (size_t i = 0; i < foodCount; ++i)
         foods[i].print();
      cout << "========================================\n";
   }
   void Ordering::listDrinks() const
   {
      cout << "List Of Avaiable Drinks\n========================================\n";
      for (size_t i = 0; i < drinkCount; ++i)
         drinks[i].print();
      cout << "========================================\n";
   }

   void Ordering::orderFood()
   {
      seneca::Menu menu("Food Menu", "Back to Order", 2);
      for (size_t i = 0; i < foodCount; ++i)
         menu << foods[i].getName();
      int sel = menu.select();
      if (sel > 0 && billItemCount < MaximumNumberOfBillItems)
      {
         Billable *ordered = new Food(foods[sel - 1]);
         if (ordered->order())
            billItems[billItemCount++] = ordered;
         else
            delete ordered;
      }
   }

   void Ordering::orderDrink()
   {
      Menu menu("Drink Menu", "Back to Order", 2);
      for (size_t i = 0; i < drinkCount; ++i)
         menu << drinks[i].getName();
      int sel = menu.select();

      if (sel > 0 && billItemCount < MaximumNumberOfBillItems)
      {
         Billable *ordered = new Drink(drinks[sel - 1]);
         if (ordered->order())
            billItems[billItemCount++] = ordered;
         else
            delete ordered;
      }
   }

   void Ordering::printBillTitle(ostream &os) const
   {
      os << "Bill # ";
      if (billNumber < 10)
         os << "00";
      else if (billNumber < 100)
         os << "0";
      os << billNumber << " =============================" << endl;
   }

   void Ordering::printTotals(ostream &os, double total) const
   {
      double tax = total * Tax;
      double grandTotal = total + tax;
      int totalIndent = 6, grandTotalIndent = 10;

      if (total > 9.99)
      {
         totalIndent++;
      }
      if (grandTotal > 9.99)
      {
         grandTotalIndent++;
      }
      os.setf(ios::fixed);
      os.precision(2);
      os << "                     Total:"
         << setw(36 - 21 - totalIndent) << ""
         << total << endl;
      os << "                     Tax:"
         << setw(36 - 21 - 4) << ""
         << tax << endl;
      os << "                     Total+Tax:"
         << setw(36 - 21 - grandTotalIndent) << ""
         << grandTotal << endl;
      os << "========================================" << endl;
   }

   void Ordering::printBill(ostream &os) const
   {
      double total = 0;
      printBillTitle(os);
      for (size_t i = 0; i < billItemCount; i++)
      {
         if (billItems[i] != nullptr)
         {
            billItems[i]->print(os);
         }
         total += billItems[i]->price();
      }
      printTotals(os, total);
   }

   void Ordering::resetBill()
   {
      char filename[64];
      Utils utils;
      utils.makeBillFileName(filename, billNumber);
      ofstream fout(filename);
      printBill(fout);
      fout.close();
      cout << "Saved bill number " << billNumber << endl;
      ++billNumber;
      cout << "Starting bill number " << billNumber << endl;
      for (size_t i = 0; i < billItemCount; ++i)
         delete billItems[i];
      billItemCount = 0;
   }
}