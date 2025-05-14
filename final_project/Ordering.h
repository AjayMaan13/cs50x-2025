#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H

#include <iostream>
#include "Food.h"
#include "Drink.h"
#include "Billable.h"
#include "constants.h"

namespace seneca
{

   class Ordering
   {
      Food *foods{};
      Drink *drinks{};
      Billable *billItems[MaximumNumberOfBillItems]{};
      size_t foodCount{};
      size_t drinkCount{};
      size_t billItemCount{};
      size_t billNumber{1};
      void printBillTitle(std::ostream &os) const;
      void printTotals(std::ostream &os, double total) const;
      size_t countRecords(const char *file) const;

   public:
      Ordering(const char *drinkFile, const char *foodFile);
      ~Ordering();
      operator bool() const;
      size_t noOfBillItems() const;
      bool hasUnsavedBill() const;

      void listFoods() const;
      void listDrinks() const;

      void orderFood();
      void orderDrink();
      void printBill(std::ostream &os) const;
      void resetBill();
   };

}
#endif // !SENECA_ORDERING_H
