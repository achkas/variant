// Задача 1. Лямбда-функция.cpp 

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <variant>
#include <algorithm>


int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<int> v5 {4, 7, 9, 14, 12};

	auto print_vector = [](int number)
	{
		std::cout << number << ' ';
	};

	std::for_each(v5.begin(), v5.end(), print_vector);

	std::cout << std::endl;

	auto even_number_multiplied_three = [](int number)
	{
		if (number % 2 == 1)
			number = number * 3;
		std::cout << number << ' ';
	};


	std::for_each(v5.begin(), v5.end(), even_number_multiplied_three);
	
	return 0;
}