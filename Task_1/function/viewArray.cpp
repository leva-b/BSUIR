#include "../Task_1.h"

void viewArray()
{
    if(n == 0){
        std::cout << "Массив структур пуст\n";
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << "Структура № " << i + 1 << '\n';
        std::cout << "Наименование: ";
        std::cout << arr[i].name << '\n';

        std::cout << "Номер цеха: ";
        std::cout << arr[i].number << '\n';

        std::cout << "Количество: ";
        std::cout << arr[i].quantity << '\n';
        if (arr[i].party)
        {
            std::cout << "Партия: большая\n";
        }
        else
        {
            std::cout << "Партия: маленькая\n";
        }

        std::cout << "Дата производства: ";
        std::cout << arr[i].date << '\n';
        if (!arr[i].isWeight)
        {
            std::cout << "Вес (кг): ";
            std::cout << arr[i].Measurement.weight << '\n';
        }
        else
        {
            std::cout << "Объем (мл): ";
            std::cout << arr[i].Measurement.volume << '\n';
        }
        std::cout << '\n';
    }
}

void viewOneStruct(int n)
{
    std::cout << "Структура № " << n + 1<< '\n';
    std::cout << "Наименование: ";
    std::cout << arr[n].name << '\n';

    std::cout << "Номер цеха: ";
    std::cout << arr[n].number << '\n';

    std::cout << "Количество: ";
    std::cout << arr[n].quantity << '\n';
    if (arr[n].party)
    {
        std::cout << "Партия: большая\n";
    }
    else
    {
        std::cout << "Партия: маленькая\n";
    }

    std::cout << "Дата производства: ";
    std::cout << arr[n].date << '\n';
    if (!arr[n].isWeight)
    {
        std::cout << "Вес (кг): ";
        std::cout << arr[n].Measurement.weight << '\n';
    }
    else
    {
        std::cout << "Объем (мл): ";
        std::cout << arr[n].Measurement.volume << '\n';
    }
    std::cout << '\n';
}