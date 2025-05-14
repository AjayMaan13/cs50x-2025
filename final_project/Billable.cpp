#define _CRT_SECURE_NO_WARNINGS
#include "Billable.h"
#include "Utils.h"

namespace seneca
{
    Billable::Billable() : m_name(nullptr), m_price(0.0) {}

    Billable::~Billable()
    {
        delete[] m_name;
        m_name = nullptr;
    }

    Billable::Billable(const Billable &bill)
        : m_name(nullptr), m_price(bill.m_price)
    {
        ut.alocpy(m_name, bill.m_name);
    }

    Billable &Billable::operator=(const Billable &bill)
    {
        if (this != &bill)
        {
            ut.alocpy(m_name, bill.m_name);
            m_price = bill.m_price;
        }
        return *this;
    }

    double Billable::price() const
    {
        return m_price;
    }

    seneca::Billable::operator const char *() const
    {
        return m_name;
    }

    void Billable::price(double value)
    {
        if (value >= 0)
        {
            m_price = value;
        }
        else
        {
            m_price = 0.0;
        }
    }
    void Billable::name(const char *name)
    {
        delete[] m_name;

        if (name)
        {
            m_name = new char[std::strlen(name) + 1];
            std::strcpy(m_name, name);
        }
        else
        {
            m_name = nullptr;
        }
    }

    char *Billable::getName() const
    {
        return m_name;
    }

    double operator+(double money, const Billable &bill)
    {
        return money + bill.price();
    }

    double &operator+=(double &money, const Billable &bill)
    {
        money += bill.price();
        return money;
    }
}