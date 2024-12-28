#include "Task_1.h"
using namespace std;

product *arr = nullptr;
int n = 0, siz = 100;
int structSize = sizeof(arr[0].name) +
                     sizeof(arr[0].number) +
                     sizeof(arr[0].quantity) +
                     sizeof(arr[0].date) +
                     sizeof(arr[0].isWeight) +
                     sizeof(arr[0].Measurement) +
                     sizeof(arr[0].party);



int main()
{
    std::cout << "Структура имеет следующий вид\n";
    std::cout << "1. Наименование\n";
    std::cout << "2. Номер цеха\n";
    std::cout << "3. Количество\n";
    std::cout << "4. Дата произведения\n";
    std::cout << "5. Вес(кг) или объем(мл)\n";
    std::cout << "6. Партия\n";

    menu();
    while (true)
    {
        std::cout << "Введите номер функции или 8 для вывода меню, при любом другом вводе программа завершится: ";
        int p;
        std::cin >> p;
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
            findStruct();
            break;
        case 5:
            deleteStruct();
            break;
        case 6:
            whatChange();
            break;
        case 7:
            shekerSort();
            break;
        case 8:
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
