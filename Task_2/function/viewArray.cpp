#include "../Task_2.h"

void viewArray()
{
    if (n == 0)
    {
        std::wcout << L"Массив структур пуст\n";
    }
    for (int i = 0; i < n; i++)
    {
        std::wcout << L"Структура № " << i + 1 << L'\n';
        std::wcout << L"Название: " << arr[i].name << L'\n';

        std::wcout << L"Автор: " << arr[i].author << L'\n';

        std::wcout << L"Регистрационный номер: " << arr[i].registerNumber << L'\n';

        std::wcout << L"Дата издания: " << arr[i].date << L'\n';

        std::wcout << L"Количество страниц: ";
        if (arr[i].isInt)
        {
            std::wcout << arr[i].numberOfPages.numberPage_int << L'\n';
        }
        else
        {
            std::wcout << arr[i].numberOfPages.numberPage_short << L'\n';
        }
        std::wcout << L'\n';
    }
}

void viewOneStruct(int k)
{
    std::wcout << L"Структура № " << k + 1 << L'\n';
    std::wcout << L"Название: " << arr[k].name << L'\n';

    std::wcout << L"Автор: " << arr[k].author << L'\n';

    std::wcout << L"Регистрационный номер: " << arr[k].registerNumber << L'\n';

    std::wcout << L"Дата издания: " << arr[k].date << L'\n';

    std::wcout << L"Количество страниц: ";
    if (arr[k].isInt)
    {
        std::wcout << arr[k].numberOfPages.numberPage_int;
    }
    else
    {
        std::wcout << arr[k].numberOfPages.numberPage_short;
    }
    std::wcout << L'\n';
}