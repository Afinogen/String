/*
 * string.cpp
 *
 *  Created on: 10.04.2013
 *      Author: Afinogen
 */

#include "string.h"

String::String()
{
    data_ = new char[1];
    data_[0] = '\0';
}

String::String(const char *str)
{
    data_ = new char[1];
    data_[0] = '\0';
    strcpy(str);
}

String::String(const char s)
{
    data_ = new char[2];
    data_[0] = s;
    data_[1] = '\0';
}

String::String(const String &str)
{
    data_ = new char[1];
    data_[0] = '\0';
    strcpy(str.Data());
}

String::~String()
{
    delete[] data_;
}

int String::Add(const char *str)
{
    int str_len_data = Len();
    int str_len = Len(str);
    char *tmp_data = new char[str_len_data + str_len + 1];
    for (int i = 0; i < str_len_data; i++)
    {
        tmp_data[i] = data_[i];
        tmp_data[i + 1] = '\0';
    }
    for (int i = str_len_data; i < str_len_data + str_len; i++)
    {
        tmp_data[i] = str[i - str_len_data];
        tmp_data[i + 1] = '\0';
    }
    delete[] data_;
    data_ = tmp_data;
    return str_len_data + str_len + 1;
}

int String::strcpy(const char *str)
{
    int str_len = Len(str);
    if (str_len == 0) return 0;
    char *tmp_data = new char[str_len + 1];
    for (int i = 0; i < str_len; i++)
    {
        tmp_data[i] = str[i];
        tmp_data[i + 1] = '\0';
    }
    delete[] data_;
    data_ = tmp_data;
    return str_len;
}

int String::Len(const char *str) const
{
    int count = 0;
    while (*(str + count))
    {
        count++;
        if (str[count] == '\0') break;
    }
    return count;
}

int String::Len() const
{
    return Len(data_);
}

char *String::Data() const
{
    return data_;
}

int String::ToInt() const
{
    int res = 0;
    int j = Len() - 1;
    for (int i = 0; i < Len(); i++)
    {
        res = ((data_[i] - '0') * pow(10, j--)) + res;

    }
    return res / 10;
}

int String::pow(int num, int pow) const
{
    int res = num;
    while (pow != 0)
    {
        res *= 10;
        --pow;
    }
    return res;
}

void String::Revers()
{
    int str_len = Len() - 1;
    char *tmp_data = new char[str_len + 1];
    for (int i = 0; i <= str_len; i++)
    {
        tmp_data[i] = data_[str_len - i];
        tmp_data[i + 1] = '\0';
    }
    delete[] data_;
    data_ = tmp_data;
}

char *String::ToOEM()
{
    char *buffer = new char[Len() + 1];
    CharToOemA(data_, buffer);
    return buffer;
}

void String::Clear()
{
    delete[] data_;
    data_ = new char[1];
    data_[0] = '\0';
}

String String::operator +(const String &str)
{
    Add(str.Data());
    return data_;
}

bool String::operator ==(const String &str) const
{
    int len = Len();
    if (Len() != Len(str.Data())) return false;
    for (int i = 0; i < len; i++)
        if (data_[i] != str[i]) return false;
    return true;
}

char String::operator [](int idx) const
{
    if (idx < 0 || idx > Len()) return -1;
    return data_[idx];
}

bool String::operator !=(const String &str) const
{
    int len = Len();
    if (Len() != Len(str.Data())) return true;
    for (int i = 0; i < len; i++)
        if (data_[i] != str[i]) return true;
    return false;
}

bool String::operator >(const String &str) const
{
    if (Len() > Len(str.Data())) return true;
    else return false;
}
bool String::operator <(const String &str) const
{
    if (Len() < Len(str.Data())) return true;
    else return false;
}

String &String::operator =(const String &str)
{
    if (this == &str)
    {
        return *this;
    }
    strcpy(str.Data());
    return *this;
}
