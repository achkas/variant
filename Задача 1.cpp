// Задача 1.

#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>

// Класс получателя определяет действие, которое должно быть выполнено.
class Receiver 
{
public:

	void output_console(const std::string& message) const
	{
		std::cout << "Вывод в консоль: "<< message<< std::endl;
	}

	void output_file(const std::string& message) const
	{
		//std::cout << "Вывод в файл: " << message << std::endl;
		std::ofstream rf;
		rf.open("Текст.txt");
		if (!rf.is_open()) { std::cout << "not"; }
		rf << message << std::endl;
		rf.close();
	}
};

class LogCommand 
{
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;	
};

class Command_consol : public LogCommand// печать в консоль
{ 
public:
	explicit Command_consol(Receiver& rec) : receiver(rec) {}

	void print(const std::string& message_) 
	{
		receiver.output_console(message_);		
	}

private:	
	Receiver& receiver;
};

class Command_file : public LogCommand // печать в фаил
{ 
public:
	explicit Command_file(Receiver& rec) : receiver(rec) {}

	void print(const std::string& message_) 
	{
		receiver.output_file(message_);
	}	

private:	
	Receiver& receiver;	
};



class Invoker 
{
private:
	LogCommand* command;

public:
	// Метод setCommand позволяет задать команду, которая будет выполнена.
	void setLogCommand(LogCommand* cmd) { command = cmd; }

	// Метод executeCommand запускает выполнение команды.	
	void executeCommand(const std::string& message) { command->print(message); }
};

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	std::string mes = "Test message";
	Invoker invoker{};
	Receiver rec;

	Command_consol command_consol(rec);	
	invoker.setLogCommand(&command_consol);
	invoker.executeCommand(mes);

	Command_file command_file(rec);
	invoker.setLogCommand(&command_file);
	invoker.executeCommand(mes);
	
	return 0;
}