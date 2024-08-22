#include "Chat.h"
#include <iostream>

int main() 
{
    setlocale(LC_ALL, "");
    system("chcp 1251");                    // строки для корректного отображения кириллических символов

    Chat chat;                              // Создать объект класса Chat

    chat.reg("Alice", "password123");       // Демонстрация регистрации пользователей
    chat.reg("Bob", "qwerty");
    chat.reg("Larry", "space");

    chat.reg("Dazy", "password123");        // Регистрация пользователя с тем же именем для демонстрации квадратичного пробирования
    chat.reg("John", "12345");

    std::cout << "----- Login Attempts -----" << std::endl;

    if (chat.login("Alice", "password123")) // Демонстрация успешного входа
    {
        std::cout << "Alice logged in successfully!" << std::endl;
    }
    else {
        std::cout << "Alice failed to log in." << std::endl;
    }

    if (chat.login("Alice", "wrongpass"))    // Демонстрация неудачного входа с неправильным паролем
    {
        std::cout << "Alice logged in successfully!" << std::endl;
    }
    else 
    {
        std::cout << "Alice failed to log in (wrong password)." << std::endl;
    }

    chat.del("John");                       // Удалить пользователя

    if (chat.login("John", "12345"))        // Попытка логина после удаления пользователя
    {
        std::cout << "John logged in successfully!" << std::endl;
    }
    else {
        std::cout << "John failed to log in (user may have been deleted)." << std::endl;
    }

    if (chat.login("Dazy", "password123"))   // Демонстрация коллизии и успешного пробирования
    {
        std::cout << "Dazy logged in successfully!" << std::endl;
    }
    else 
    {
        std::cout << "Dazy failed to log in." << std::endl;
    }

    if (chat.login("Alice", "password123"))
    {
        std::cout << "Alice logged in successfully!" << std::endl;
    }
    else 
    {
        std::cout << "Alice failed to log in." << std::endl;
    }

    return 0;
}