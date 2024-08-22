#include "Chat.h"
#include <iostream>

int main() 
{
    setlocale(LC_ALL, "");
    system("chcp 1251");                    // ������ ��� ����������� ����������� ������������� ��������

    Chat chat;                              // ������� ������ ������ Chat

    chat.reg("Alice", "password123");       // ������������ ����������� �������������
    chat.reg("Bob", "qwerty");
    chat.reg("Larry", "space");

    chat.reg("Dazy", "password123");        // ����������� ������������ � ��� �� ������ ��� ������������ ������������� ������������
    chat.reg("John", "12345");

    std::cout << "----- Login Attempts -----" << std::endl;

    if (chat.login("Alice", "password123")) // ������������ ��������� �����
    {
        std::cout << "Alice logged in successfully!" << std::endl;
    }
    else {
        std::cout << "Alice failed to log in." << std::endl;
    }

    if (chat.login("Alice", "wrongpass"))    // ������������ ���������� ����� � ������������ �������
    {
        std::cout << "Alice logged in successfully!" << std::endl;
    }
    else 
    {
        std::cout << "Alice failed to log in (wrong password)." << std::endl;
    }

    chat.del("John");                       // ������� ������������

    if (chat.login("John", "12345"))        // ������� ������ ����� �������� ������������
    {
        std::cout << "John logged in successfully!" << std::endl;
    }
    else {
        std::cout << "John failed to log in (user may have been deleted)." << std::endl;
    }

    if (chat.login("Dazy", "password123"))   // ������������ �������� � ��������� ������������
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