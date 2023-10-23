// Задача 1.

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>

class simple_functor {

    int sum;
    int count;

public:

    simple_functor() : sum{ 0 }, count{ 0 } {};

    int operator()(int number)
    {
        std::cout << number << ' ';

        if (number % 3 == 0)
        {
            sum = sum + number;
            count++;

            return sum;
        }
    }

    int get_count() { return count; }

    int get_sum() { return sum; }

    void PrintIntRES()

    {
        std::cout << "[OUT] : get_sum() = " << sum << std::endl << "[OUT] : get_count() = " << count;
    }
};



int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

           

        simple_functor sf;

        std::vector<int> vec{ 4, 1, 3, 6, 25, 54 };
      
        std::cout << "[IN] : ";
        sf = std::for_each(vec.begin(), vec.end(), simple_functor());
       
        std::cout << std::endl;      
        
        std::cout << "[OUT] : get_sum() = " << sf.get_sum() << std::endl 
            << "[OUT] : get_count() = " << sf.get_count();
       
        
      
    
    
    return 0;
}