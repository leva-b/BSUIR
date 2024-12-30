#include "Task_2.h"
using namespace std;

book *arr = nullptr;
int n = 0, siz = 100;
int structSize = sizeof(((book *)0)->name) +
                 sizeof(((book *)0)->author) +
                 sizeof(((book *)0)->registerNumber) +
                 sizeof(((book *)0)->date) +
                 sizeof(((book *)0)->numberOfPages) +
                 sizeof(((book *)0)->isInt);

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::wcout << L"Структура имеет следующий вид:\n";
    std::wcout << L"1. Название книиги\n";
    std::wcout << L"2. Автор\n";
    std::wcout << L"3. Регистрационный номер\n";
    std::wcout << L"4. Дата издания\n";
    std::wcout << L"5. Количество страниц\n\n";

    menu();
    while (true)
    {
        std::wcout << L"Введите номер функции или 7 для вывода меню, при любом другом вводе программа завершится: ";
        int p;
        std::wcin >> p;
        std::cout << '\n';
        wcin.ignore();
        bool exit = false;
        switch (p)
        {
        case 1:
            input();
            break;
        case 2:
            viewArray();
            break;
        case 3:
            additionalInput();
            break;
        case 4:
            deleteStruct();
            writeToFile();
            break;
        case 5:
            whatChange();
            writeToFile();
            break;
        case 6:
            mySort();
            writeToFile();
            break;
        case 7:
            menu();
            break;
        default:
            exit = true;
            break;
        }
        if (exit)
            break;
    }
    free(arr);
}
