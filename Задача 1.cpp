// Задача 1.

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
//#include <algorithm>

template <typename T>
T my_dub(T a)
{
    auto S=a*a;    
        return S;     
}

template <class T>
 auto my_dub(std::vector<T> v)
{
    for (auto& number : v)
            {
                number = number * number;                
            } 
    return v;   
}

 template <class T>
 std::ostream& operator << (std::ostream& number, const std::vector<T>& v)
 {   
     
 
     for (auto& number : v) {
         std::cout << number << ' ';
     }
    
     return number ;
 }


int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a = 6;
    std::vector<int> v5 {4, 7, 9, 14, 12};

            std::cout << "[IN]: " << a << std::endl;
            std::cout << "[OUT]: " << my_dub(a) << std::endl;
            std::cout << "[IN]: " << v5 << std::endl;
            std::cout << "[OUT]: " << my_dub(v5) << std::endl;
    
    return 0;
}