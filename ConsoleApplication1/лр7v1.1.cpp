// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"
#include <time.h>
#include <string>


int main()
{
    setlocale(0, "");
    Array<char> mas;
    Array<int> mas2;
    
    mas + 's';
    mas + 'w';
    mas + 'r';
    mas + 't';
    mas + 's';
    mas + 's';
   
    mas2 + 1;   mas2 + 5;   mas2 + 10;mas2 + 5; 
   cout<< mas.howManySymbols('s');
   
 
   cout << mas;
   cout << mas2.howManySymbols(5);
   string str  = mas2.whatTyeThisArray();
   //cout << endl<<str;
    
    return 0;
}

