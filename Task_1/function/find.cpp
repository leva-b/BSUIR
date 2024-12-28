#include "../Task_1.h"
void findStruct()
{
    bool isexit = true;
    do
    {
        std::cout << "Введите номер признака для поиска информации: ";
        std::cout << "1. Наименование\n";
        std::cout << "2. Номер цеха\n";
        std::cout << "3. Количество\n";
        std::cout << "4. Дата произведения\n";
        std::cout << "5. Вес(кг) или объем(мл)\n";
        std::cout << "6. Партия\n\n";
        int choice;
        std::cin >> choice;
        isexit = true;
        int count = 0;
        switch (choice)
        {
        case 1:
            char name[50];
            std::cout << "Введите наименования: ";
            std::cin >> name;
            std::cout << "Результат поиска: ";
            for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].name, name) == 0)
                {
                    count++;
                    viewOneStruct(i);
                }
            }
            if (count = 0)
            {
                std::cout << "продукция с заданным значением не найдена\n\n";
            }
            break;
        case 2:
            int number;
            std::cout << "Введите номер цеха: ";
            std::cin >> number;
            std::cout << "Результат поиска: ";
            for (int i = 0; i < n; i++)
            {
                if (arr[i].number == number)
                {
                    count++;
                    viewOneStruct(i);
                }
            }
            if (count = 0)
            {
                std::cout << "продукция с заданным значением не найдена\n\n";
            }
            break;
        case 3:
            int quantity;
            std::cout << "Введите количество: ";
            std::cin >> quantity;
            std::cout << "Результат поиска: ";
            for (int i = 0; i < n; i++)
            {
                if (arr[i].quantity == quantity)
                {
                    count++;
                    viewOneStruct(i);
                }
            }
            if (count = 0)
            {
                std::cout << "продукция с заданным значением не найдена\n\n";
            }
            break;
        case 4:
            char date[11];
            std::cout << "Введите дату: ";
            std::cin >> date;
            std::cout << "Результат поиска: ";
            for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].date, date) == 0)
                {
                    count++;
                    viewOneStruct(i);
                }
            }
            if (count = 0)
            {
                std::cout << "продукция с заданным значением не найдена\n\n";
            }
            break;
        case 5:
            bool isWeight;
            std::cout << "Введите 0, если указываете вес продукции, или любое другое значение если указываете объем: ";
            std::cin >> isWeight;
            if (!isWeight)
            {
                float weight;
                std::cout << "Введите вес(кг): ";
                std::cin >> weight;
                for (int i = 0; i < n; i++)
                {
                    if (!arr[i].isWeight && arr[i].Measurement.weight == weight)
                    {
                        count++;
                        viewOneStruct(i);
                    }
                }
            }
            else
            {
                int volume;
                std::cout << "Введите объем(мл): ";
                std::cin >> volume;
                for (int i = 0; i < n; i++)
                {
                    if (arr[i].isWeight && arr[i].Measurement.volume == volume)
                    {
                        count++;
                        viewOneStruct(i);
                    }
                }
            }
            if (count = 0)
            {
                std::cout << "продукция с заданным значением не найдена\n\n";
            }
            break;
        case 6:
            char party_str[9];
            std::cout << "Введите размер партии(большая или маленькая): ";
            std::cin >> party_str;
            bool party;
            if (party_str == "большая" || party_str == "большая")
                party = true;
            else if (party_str == "маленькая" || party_str == "Маленькая")
                party = false;
            std::cout << "Результат поиска: ";
            for (int i = 0; i < n; i++)
            {
                if (arr[i].party == party)
                {
                    count++;
                    viewOneStruct(i);
                }
            }
            if (count = 0)
            {
                std::cout << "продукция с заданным значением не найдена\n\n";
            }
        default:
            isexit = false;
            std::cout << "Неправильный ввод ";
            break;
        }
    } while(!isexit);
}