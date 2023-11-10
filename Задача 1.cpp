// Задача 1.

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <map>

void print_vec(const std::vector<int> &v)
{
    for (const auto& elem : v)
        std::cout << elem << " ";
    std::cout << std::endl;
}

auto D_vec(std::vector<int> v) {
    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());
    return v;
}




    int main()
    {
        setlocale(LC_ALL, "ru");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        

        std::vector<int> vec {1, 1, 2, 5, 6, 1, 2, 4};
        std::cout << "[IN] : " << std::endl;
        print_vec(vec);

        vec = D_vec(vec);
        std::cout << "[OUT] : " << std::endl;
        print_vec(vec);
       

        return 0;
    }