#pragma once
#include <iostream>
using namespace std;

template<class universalType>
class Array
{
private:
    universalType *array;
    int sizeOfArray = 0;
public:
   Array()
    {
        array = new universalType[1000];
    }


    void add(universalType element)
    {
        array[sizeOfArray++] = element;
    }

    int getSizeOfArray()
    {
        return this->sizeOfArray;
    }

    void Delete(universalType elem)
    {
        int extraSzeOfArray =sizeOfArray;
        for (int i = 0;i < sizeOfArray;i++)
        {
            if (elem == array[i])
            {
                for (int j = i;j < sizeOfArray;j++)
                {
                    array[j] = array[j + 1];
                }
                sizeOfArray--;
               // return;
            }
        }
        if (sizeOfArray == extraSzeOfArray)
        cout << "i can't find this symbol\n";
    }

    void showArray(void)
    {
        if (sizeOfArray == 0)
        {
            cout << "Array is empty\n";return;
        }

        for (int i = 0;i < sizeOfArray;i++)
        {
            cout << array[i]<< " ";
        }
        cout << endl;
    }

    //overloads        +
    void operator + (universalType element)
    {
        this->array[sizeOfArray++] = element;
    }


    void operator+(Array a)
    {
        for (int i(0);i < a.sizeOfArray;i++)
        {
            this->add(a.array[i]);
        }
    }

    void operator+ (universalType *array)
    {
        while (*array)
        {
            this->array[sizeOfArray++] = *array++;
        }
    }
    //////////////   -
    void operator -(universalType elem)
    {
        this->Delete(elem);
    }
    /////////////   <<
    friend __readonly ostream& operator<<(ostream& out, Array& arr)
    {
        if (arr.getSizeOfArray() == 0)
            {
                cout << "array is empty\n"; return out;
            }

        if (sizeof(universalType) == 1) {
            for (int i = 0;i < arr.getSizeOfArray();i++)
            {
                out << *(arr.array + i) << "";
            }
            cout << endl;
            return out;
        }
     
          for (int i = 0;i < arr.getSizeOfArray();i++)
          {
              out << *(arr.array + i) << " ";
          }
      cout << endl;
      return out;
       
    }
    
    /////////////////    >>
    bool operator >(Array a)
    {
        if (a.getSizeOfArray() != this->getSizeOfArray())
        {
            cout << "Arrays not equal Reason: SIZE ";
            if (a.getSizeOfArray() < this->getSizeOfArray())
            {
                cout << "a < this" << endl;
            }
            else cout << "this < a" << endl;
            return false;
        }

        int counter = 0;

        for (size_t i = 0; i < this->getSizeOfArray(); i++)
        {
            if (this->array[i] == a.array[counter]) 
            {
                counter++;

                if (counter == this->getSizeOfArray())
                {
                    cout << "Arrays is equal";
                    return true;
                }
            }
            else counter = 0;
        }
        cout << "Arrays is not equal: Reason_character-by-character equal\n";
        return false;
    }

    bool operator !=(Array a)
    {
        if (a.getSizeOfArray() != this->getSizeOfArray())
        {
            cout << "Arrays is not equal: size\n";
            return true;
        }
        else {
            for (size_t i = 0; i < this->getSizeOfArray(); i++)
            {
                if (this->array[i] != a.array[i])
                {
                    cout << "arrays is not equal\n";
                    return true;
                }

            }
        }
        cout << "Arrays is EQUAL\n";
        return false;
    }
    ///////////// |
    int operator | (universalType someSymbol)
    {
        if (this->getSizeOfArray() == 0) return 0;

        int counter = 0;
        for (size_t i = 0; i < this->getSizeOfArray(); i++)
        {
            if (this->array[i] == someSymbol) counter++;
        }
        return counter;
    }

    template<class universalType> 
 inline  unsigned int __readonly howManySymbols(const universalType symbol) 
    {
        int counter = 0;
        for (size_t i = 0; i < this->getSizeOfArray(); i++)
        {
            if (this->array[i] == symbol) counter++;
        }
        return counter;
    }

    string whatTyeThisArray()
    {
        cout<<"This is array type of "<< typeid(*this->array).name();
       
        return typeid(this->array).name();
    }
};