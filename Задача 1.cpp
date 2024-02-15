// Задача 1.

#include <iostream>
#include<thread>
#include <chrono>
#include <string>
#include <windows.h>
#include<algorithm>
#include <future>
		using namespace std::chrono_literals;

		void printArray(int arr[], int size)
		{
			int i;
			for (i = 0; i < size; i++)
				std::cout << arr[i] << " ";
			std::cout << std::endl;
		}

std::once_flag flag;
void print_once()
{
	std::cout << "id = " << std::this_thread::get_id() << ": ";
}

void srch(int arr[], int size, int i, std::promise<int> prms)
{	
	std::call_once(flag, print_once);
	int min = i;
	for (int j = i + 1; j < size; j++)
	min = (arr[j] < arr[min]) ? j : min;	
	prms.set_value(min);

}	


			int main()
			{
				setlocale(LC_ALL, "ru");
				SetConsoleCP(1251);
				SetConsoleOutputCP(1251);

				std::cout << "id = " << std::this_thread::get_id() << ": ";
				const int size = 10;
				int arr[size] = { 14, 25, 6, 2, 43, 5, 96, 3, 4, 13 };
				printArray(arr, size);

				
				
				int min = 0; 				
				for (int i = 0; i < size; i++)
				{	
					std::promise<int> prms;
				std::future<int> ft  = prms.get_future();
					auto res1 = std::async(srch, arr, size, i, move(prms));					
				std::swap(arr[i], arr[ft.get()]);
						
				}
				printArray(arr, size);
				
		 return 0;
			}
