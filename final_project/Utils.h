#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H

#include <iostream>
using namespace std;

namespace seneca
{

    class Utils
    {

    public:
        // this reads an integer from the user , returning a default value if there is no any input provided
        int getint(int defaultValue) const;

        // this reads an integer from the user without any age restrictions
        int getInt() const;

        // this read an integer from the user , ensuring that it is within a specified range i.e. from min to max
        int getInt(int min, int max) const;

        // this dynamically allocates memory and copies the provided string , retuening the new string
        char *alocpy(const char *src);

        // this allocates memory for destination string and copies the source string into it
        char *alocpy(char *&des, const char *src);

        // this copies a string from 'src' to 'des'
        char *strcpy(char *des, const char *src) const;

        // this copies exactly 'len' characters from 'src' to des'
        char *strncpy(char *des, const char *src, int len) const;

        // this copies up to 'len; characters from 'src' to 'des'
        char *strcpy(char *des, const char *src, int len) const;

        // this returns the length of the given string
        int strlen(const char *str) const;

        // this checks if an entire C-string consists of only whitespace characters
        bool isspace(const char *cstring) const;

        // this checks if any given character is a whitespace character
        bool isspace(char ch) const;

        // This reads input from an input stream i.e. 'istr' until it reaches a given delimite , the default is a newline
        char *read(char *&toRet, std::istream &istr, char delimiter = '\n') const;

        // this prints a string to an output stream ostr'
        std::ostream &print(std::ostream &ostr, const char *cstring, size_t maxlen) const;

        char *makeBillFileName(char *filename, size_t billNo) const;
    };

    // this is teh global utils object for an easy access to helper functions
    extern Utils ut;

    // this is a global flag to turn on or turn off the debugging
    extern bool debug;
}

#endif // !SENECA_UTILS_H
