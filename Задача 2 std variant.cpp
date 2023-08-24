// Задача 2 std variant.cpp 

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <variant>


std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}

	return result;

}



int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	bool is_int = std::holds_alternative<int>(get_variant());
	//std::cout << is_int << std::endl;
	if (is_int) {
		auto var = std::get<int>(get_variant());
		std::cout << var * 2 << std::endl;
	}

	bool is_string = std::holds_alternative<std::string>(get_variant());
	//std::cout << is_string << std::endl;
	if (is_string) {
		auto var = std::get<std::string>(get_variant());
		std::cout << var << std::endl;
	}

	bool is_vector = std::holds_alternative<std::vector<int>>(get_variant());
	//std::cout << is_vector << std::endl;
	if (is_vector) {
		auto var = std::get<std::vector<int>>(get_variant());
		for (auto number : var)
			std::cout << number << ' ';
	}
	return 0;
}