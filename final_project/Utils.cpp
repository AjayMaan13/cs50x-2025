#include <iostream>
#include <string>
#include <limits>

using namespace std;

#include "Utils.h"

namespace seneca
{

    Utils ut;
    bool debug = false;
    const size_t AllocationBlockSize = 128;

    int Utils::getInt(int min, int max) const
    {
        int value;
        bool valid = false;
        while (!valid)
        {
            value = getInt();
            if (value < min || value > max)
            {
                cout << "Invalid value: [" << min << " <= value <= " << max << "], try again: ";
                continue;
            }
            valid = true;
        }
        return value;
    }

    int Utils::getint(int defaultValue) const
    {
        string input;
        cin >> ws;
        getline(cin, input);

        if (input.empty())
        {
            return defaultValue;
        }
        else
        {
            return stoi(input);
        }
    }

    int Utils::getInt() const
    {
        int value;
        string input;
        bool valid = false;

        while (!valid)
        {
            getline(cin, input);

            if (input.empty())
            {
                cout << "You must enter a value: ";
                continue;
            }

            try
            {
                size_t idx;
                value = stoi(input, &idx);

                if (idx != input.length())
                {
                    cout << "Only an integer please: ";
                    continue;
                }

                if (value < 0 || value > 3)
                {
                    cout << "Invalid value: [0<= value <=3], try again: ";
                    continue;
                }

                valid = true;
            }
            catch (invalid_argument &)
            {
                cout << "Invalid integer: ";
            }
            catch (out_of_range &)
            {
                cout << "Invalid integer: ";
            }
        }

        return value;
    }

    char *Utils::alocpy(const char *src)
    {
        char *des{};
        return alocpy(des, src);
    }

    char *Utils::alocpy(char *&des, const char *src)
    {
        if (src)
        {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
        return des;
    }

    char *Utils::strcpy(char *des, const char *src) const
    {
        int i;
        for (i = 0; src[i]; i++)
            des[i] = src[i];
        des[i] = char(0);
        return des;
    }

    char *Utils::strcpy(char *des, const char *src, int len) const
    {
        int i;
        for (i = 0; i < len && src[i]; i++)
            des[i] = src[i];
        des[i] = 0;
        return des;
    }

    char *Utils::strncpy(char *des, const char *src, int len) const
    {
        int i = 0;
        while (i < len - 1 && src[i])
        {
            des[i] = src[i];
            i++;
        }
        des[i] = src[i];
        return des;
    }

    int Utils::strlen(const char *str) const
    {
        int len;
        for (len = 0; str[len]; len++)
            ;
        return len;
    }

    char *Utils::read(char *&toRet, istream &istr, char delimiter) const
    {
        bool done = false;

        char *cstr = new char[AllocationBlockSize];
        toRet = cstr;
        int size = AllocationBlockSize;
        int nullindex = 1;

        do
        {
            cin.getline(cstr, AllocationBlockSize, delimiter);
            if (cin.fail())
            {
                char *temp = new char[size + AllocationBlockSize];
                strcpy(temp, toRet);
                delete[] toRet;
                toRet = temp;
                cstr = &toRet[size - nullindex++];
                size += AllocationBlockSize;
                cin.clear();
            }
            else
            {
                done = true;
            }
        } while (!done);

        char *temp = new char[strlen(toRet) + 1];
        strcpy(temp, toRet);
        delete[] toRet;
        toRet = temp;
        return toRet;
    }

    bool Utils::isspace(char ch) const
    {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r'; // r f v n t
    }

    bool Utils::isspace(const char *cstring) const
    {
        while (cstring && isspace(*cstring))
        {
            cstring++;
        }
        return cstring && *cstring == 0;
    }

    char *Utils::makeBillFileName(char *filename, size_t billNo) const
    {
        char billFileName[21] = "bill_";
        size_t temp = billNo;
        int cnt = 5;
        int length;
        do
        {
            cnt++;
            temp /= 10;
        } while (temp > 0);
        length = cnt;
        while (billNo > 0)
        {
            billFileName[--cnt] = (billNo % 10) + '0';
            billNo /= 10;
        }
        if (billFileName[cnt - 1] == '\0')
        {
            billFileName[--cnt] = '0';
        }
        for (int i = 0; ".txt"[i]; i++)
        {
            billFileName[length++] = ".txt"[i];
        }
        billFileName[length] = '\0';
        strcpy(filename, billFileName);
        return filename;
    }

}
