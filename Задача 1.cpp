// Задача 1.

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <unordered_map>





int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

           

    std::cout << "[IN]: " << "Hello world!!" << std::endl;
    std::cout << std::endl;


    typedef std::pair<std::string, int> pair;
    std::vector<pair> vec;
    std::map< std::string, int>letter_key;
    std::multimap< std::string, int>letter2_key
    {
        {"H", 1}, { "e",1 }, { "l",1 }, { "l",1 }, { "o",1 }, { " ",1 },
        { "w",1 }, { "o",1 }, { "r",1 }, { "l",1 }, { "d",1 }, { "!",1 }, { "!",1 }
    };



    for (auto iter{ letter2_key.begin() }; iter != letter2_key.end(); iter++)
    {        
        letter_key[iter->first] = letter2_key.count(iter->first);        
    }

    /*for (const auto& elem : letter_key)
        std::cout << elem.first << ": " << elem.second << std::endl;
        std::cout << std::endl;*/

    std::copy(letter_key.begin(), letter_key.end(), std::back_inserter<std::vector<pair>>(vec));

    std::sort(vec.begin(), vec.end(), [](const pair& l, const pair& v)
        {
            if (l.second != v.second)
            {
                return l.second > v.second;
            }
            return l.first > v.first;
        }
    );

    /*for (auto const& pair : vec)
    {
     std::cout << '{' << pair.first << "," << pair.second << '}' << std::endl;
    }*/

    std::cout << "[OUT]: " << std::endl;

    for (const auto& elem : vec)
        std::cout << elem.first << ": " << elem.second << std::endl;
    
    return 0;
}