// Задача 1.

#include <iostream>
#include <string>
#include <windows.h>
#include <exception>

class Unwanted_index : public std::exception
{
public:
    const char* what() const override { return "Выход за пределы массива! Добавить элемент невозможно!"; }
};


class arr
{

private:

    int* element;
    int index = 0;
    int size;

public:

    arr(int size) {

        element = new int[size]();    
        this->size = size;
    }    
    

    auto add_element(int num) {
        
       if (index > size-1) throw Unwanted_index();
        
          element[index] = num;
          index++;     
          return element[index];
        
        
    }

    auto get_element(int index) {
        if ((index > size - 1) || (index < 0)) throw("...");
        return element[index];
    }
    

    void print_arr(arr*) {

        for (int i = 0; i < size; ++i)
        std::cout << element[i]<<" " ;
        std::cout <<std::endl;
    }

    arr(const arr&) = delete;
    arr& operator=(const arr&) = delete;
   

~arr()
{    
    delete[] element;
}

};

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    try {
        arr smart_array(6);
        smart_array.add_element(99);
        smart_array.add_element(77);
        smart_array.add_element(88);
        smart_array.add_element(66);
        smart_array.add_element(33);
        smart_array.add_element(22);
        /*smart_array.add_element(55);*/

        std::cout << smart_array.get_element(4) << std::endl;

        smart_array.print_arr(&smart_array);       

         /*arr smart_array1(6);
         smart_array1 = smart_array;
        arr smart_array2(smart_array);*/

    }

    catch (const std::exception& ex) 
    {
        std::cout << ex.what() << std::endl;
    }

    catch (...)
    {
        std::cout << "Элемента с таким индексом не существует!" << std::endl;
    }

    return 0;
}