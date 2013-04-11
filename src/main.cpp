/*
 * main.cpp
 *
 *  Created on: 11.04.2013
 *      Author: Afinogen
 */

#include <stdio.h>
#include <windows.h>

#include "string/string.h"

int main()
{

    String str("2");
    String str1("22");
    if (str1 > str) printf("ok\n");
    else printf("no\n");
    str = str1;
    printf("%s %s\n", str1.Data(), str.Data());
    printf("%i\n", str.ToInt());
    printf("%s %i\n", str.Data(), str.Len());
    str.Add(" test");
    str.Revers();
    printf("%s %i\n", str.Data(), str.Len());
    str.Clear();
    str.Add("привет!");
    printf("%s %i\n", str.ToOEM(), str.Len());
    printf("%s", (String("test") + String(" test")).Data());
    String s(str1);
    printf("\n%s", s.Data());
    return 0;
}
