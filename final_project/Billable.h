#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H

#include <iostream>
#include <cstring>

namespace seneca
{
    class Billable
    {
    protected:
        char *m_name;
        double m_price;

        void price(double value);
        void name(const char *name);

        void setPrice(double value)
        {
            m_price = value;
        }

    public:
        Billable();

        virtual ~Billable();
        char *getName() const;
        Billable(const Billable &B);
        Billable &operator=(const Billable &bill);
        virtual double price() const;
        virtual std::ostream &print(std::ostream &ostr = std::cout) const = 0;
        virtual bool order() = 0;
        virtual bool ordered() const = 0;
        virtual std::ifstream &read(std::ifstream &file) = 0;

        operator const char *() const;
    };

    double operator+(double money, const Billable &B);
    double &operator+=(double &money, const Billable &B);
}
#endif // !SENECA_BILLABLE_H
