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
    std::cout << "Структура имеет следующий вид:\n";
    std::cout << "1. Название книиги\n";
    std::cout << "2. Автор\n";
    std::cout << "3. Регистрационный номер\n";
    std::cout << "4. Дата издания\n";
    std::cout << "5. Количество страниц\n\n";

    menu();
    while (true)
    {
        std::cout << "Введите номер функции или 7 для вывода меню, при любом другом вводе программа завершится: ";
        int p;
        std::cin >> p;
        std::cout << '\n';
        cin.ignore();
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
            break;
        case 5:
            whatChange();
            break;
        case 6:
            mySort();
            break;
        case 7:
            menu();
            break;
        default:
            exit = true;
            break;
        }
        if(exit)break;
    }
    free(arr);
}
