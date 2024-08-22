#include "Chat.h"
#include <iostream>

Chat::Chat()    // Инициализировать массив пользователей
{
    for (int i = 0; i < size; i++) 
    {
        usArray[i].name = "";
        usArray[i].hash = veryBigNumber;
    }
}

Chat::~Chat()   // Освобождение памяти
{
    delete[] usArray;
}

void Chat::reg(string name, string password)
{
    user newUser;
    int index = 0;
    int hash = hash_function(password, index);
    for (int i = 0; i < size; i++)
    {
        if (usArray[hash].hash == veryBigNumber)
        {
            newUser.name = name;
            newUser.hash = hash;
            usArray[hash] = newUser;
            return;
        }
        index = i * i;
        hash = hash_function(password, index);
    }
    cout << "В массиве не осталось места. Регистрация не выполнена" << endl;
}

void Chat::del(string name)   // Найти пользователя по имени и удалить его
{
    for (int i = 0; i < size; i++) {
        if (usArray[i].name == name) {
            usArray[i].name = "";
            usArray[i].hash = veryBigNumber;
            return;
        }
    }

    cout << "Пользователь с этим именем не найден" << endl;
}

bool Chat::login(string name, string password)  // Вычислить хэш пароля для сравнения
{
    int index = 0;
    int hash = hash_function(password, index);
    for (int i = 0; i < size; i++)
    {
        if (usArray[hash].hash == hash && usArray[hash].name == name)
            return true;
        index = i * i;
        hash = hash_function(password, index);
    }
    return false;
}

int Chat::hash_function(const string& password, int index) 
{
    int hash = 0;
    for (int i = 0; i < password.length(); i++)
    {
        hash += password[i];
    }
    return  int((arraySize - 1) * ((hash + index) * 0.7 - int((hash + index) * 0.7)));  // Вычислить хэш методом умножения
}
