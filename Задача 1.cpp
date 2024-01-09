// Задача 1.

#include <iostream>
#include<thread>
#include <chrono>
#include <string>
#include <windows.h>

using namespace std::chrono_literals;

int client(int man, int& count)
{
    for (int i = 0; i < man; i++)
    {
        //std::this_thread::sleep_for(1000ms);
        count++;
        std::this_thread::sleep_for(1000ms);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "client: " << count << std::endl;

    }

    return count;
}

int oprtor(int man, int& count)
{
    for (int i = 0; i < man; i++)
    {
        std::this_thread::sleep_for(2000ms);
        count--;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);//зелёныи
        std::cout << "oprtor: " << count << std::endl;
    }

    return count;
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int count = 0;
    //thread_local int count;
    int man = 10;

    /*std::thread t1([&count]() {count = client(10, count); });
    std::thread t2([&count]() {count = oprtor(10, count); });*/

    std::thread t1([&]() {count = client(man, count); });
    std::thread t2([&]() { count = oprtor(man, count); });

    t1.join();
    t2.join();
    std::cout << "Количество оставшихся клиентов: " << count << std::endl;
    return 0;
}