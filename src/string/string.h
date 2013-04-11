/*
 * string.h
 *
 *  Created on: 10.04.2013
 *      Author: Afinogen
 */

#ifndef STRING_H_
#define STRING_H_

#include <windows.h>

class String
{
    public:
        String();
        String(const char *str);
        String(const char s);
        String(const String &str);
        ~String();
        int Len() const;
        int Len(const char *str) const;
        int Add(const char *str);
        char *Data() const;
        int ToInt() const;
        void Revers();
        char *ToOEM();
        void Clear();
        String operator +(const String &str);
        bool operator ==(const String &str) const;
        char operator[](int idx) const;
        bool operator!=(const String &str) const;
        bool operator > (const String &str) const;
        bool operator < (const String &str) const;
        String &operator =(const String &str);
    private:
        int strcpy(const char *str);
        int pow(int num, int pow) const;
        char *data_;
};

#endif /* STRING_H_ */
