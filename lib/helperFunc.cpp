#include <iostream>
#include <string>
#include "../include/helperFunc.h"
using namespace std;

int getStrSize(string str)
{
        int i=0;
        while(str[i]!='\0')
                i++;

        return i;
}

