#include "../Task_2.h"

void viewArray()
{
    if (n == 0)
    {
        std::cout << "Массив структур пуст\n\n";
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << "Структура № " << i + 1 << '\n';
        std::cout << "Название: " << arr[i].name << '\n';

        std::cout << "Автор: " << arr[i].author << '\n';

        std::cout << "Регистрационный номер: " << arr[i].registerNumber << '\n';

        std::cout << "Дата издания: " << arr[i].date << '\n';

        std::cout << "Количество страниц: ";
        if (arr[i].isInt)
        {
            std::cout << arr[i].numberOfPages.numberPage_int << '\n';
        }
        else
        {
            std::cout << arr[i].numberOfPages.numberPage_short << '\n';
        }
        std::cout << '\n';
    }
}

void viewOneStruct(int k)
{
    std::cout << "Структура № " << k + 1 << '\n';
    std::cout << "Название: " << arr[k].name << '\n';

    std::cout << "Автор: " << arr[k].author << '\n';

    std::cout << "Регистрационный номер: " << arr[k].registerNumber << '\n';

    std::cout << "Дата издания: " << arr[k].date << '\n';

    std::cout << "Количество страниц: ";
    if (arr[k].isInt)
    {
        std::cout << arr[k].numberOfPages.numberPage_int;
    }
    else
    {
        std::cout << arr[k].numberOfPages.numberPage_short;
    }
    std::cout << '\n';
}