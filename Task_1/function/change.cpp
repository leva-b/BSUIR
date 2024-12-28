#include "../Task_1.h"

void whatChange()
{
    std::cout << "Если хотите изменить конкретную структуру нажмите 1,";
    std::cout << "если хотите изменить все структуры по одному признаку нажмите другую клавишу: ";
    string chang;
    std::cin >> chang;
    chang == "1" ? change() : changeAll();
}
void change()
{
    int k;
    std::cout << "Введите номер структуры для изменения от 1 до " << n << " : ";
    std::cin >> k;
    bool isexit = true;
    do
    {
        std::cout << "Введите номер признака для изменения информации: ";
        std::cout << "1. Наименование\n";
        std::cout << "2. Номер цеха\n";
        std::cout << "3. Количество\n";
        std::cout << "4. Дата произведения\n";
        std::cout << "5. Вес(кг) или объем(мл)\n";
        std::cout << "6. Партия\n\n";
        int choice;
        std::cin >> choice;
        isexit = true;
        switch (choice)
        {
        case 1:
            char new_name[50];
            std::cout << "Введите новое наименование: ";
            std::cin >> new_name;
            strcpy(arr[k].name, new_name);
            break;
        case 2:
            int new_number;
            std::cout << "Введите новый номер цеха";
            std::cin >> new_number;
            arr[k].number = new_number;
            break;
        case 3:
            int new_quantity;
            std::cout << "Введите новое количество";
            std::cin >> new_quantity;
            arr[k].quantity = new_quantity;

            break;
        case 4:
            char new_date[11];
            std::cout << "Введите новую дату: ";
            std::cin >> new_date;
            strcpy(arr[k].date, new_date);

            break;
        case 5:
            bool isWeight;
            std::cout << "Введите 0, если указываете вес продукции, или любое другое значение если указываете объем: ";
            std::cin >> isWeight;
            if (!isWeight)
            {
                float new_weight;
                std::cout << "Введите новый вес: ";
                std::cin >> new_weight;
                arr[k].Measurement.weight = new_weight;
            }
            else
            {
                int new_volume;
                std::cout << "Введите новый объем(мл): ";
                std::cin >> new_volume;
                arr[k].Measurement.volume = new_volume;
            }

            break;
        case 6:
            char new_party_str[9];
            std::cout << "Введите новый размер партии(большая или маленькая): ";
            std::cin >> new_party_str;
            bool new_party;
            if (new_party_str == "большая" || new_party_str == "большая")
                new_party = true;
            else if (new_party_str == "маленькая" || new_party_str == "Маленькая")
                new_party = false;
            arr[k].party = new_party;
            break;
        default:
            isexit = false;
            std::cout << "Неправильный ввод ";
            break;
        }
    } while (!isexit);
}

void changeAll()
{
    bool isexit = true;
    do
    {
        std::cout << "Введите номер признака для изменения информации: ";
        std::cout << "1. Наименование\n";
        std::cout << "2. Номер цеха\n";
        std::cout << "3. Количество\n";
        std::cout << "4. Дата произведения\n";
        std::cout << "5. Вес(кг) или объем(мл)\n";
        std::cout << "6. Партия\n\n";
        int choice;
        std::cin >> choice;
        isexit = true;
        switch (choice)
        {
        case 1:
            char name[50];
            char new_name[50];
            std::cout << "Введите начальное наименования: ";
            std::cin >> name;
            std::cout << "Введите новое наименование: ";
            std::cin >> new_name;
            for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].name, name) == 0)
                {
                    strcpy(arr[i].name, new_name);
                }
            }
            break;
        case 2:
            int new_number;
            int number;
            std::cout << "Введите начальный номер цеха: ";
            std::cin >> number;
            std::cout << "Введите новый номер цеха";
            std::cin >> new_number;
            for (int i = 0; i < n; i++)
            {
                if (arr[i].number == number)
                {
                    arr[i].number = new_number;
                }
            }
            break;
        case 3:
            int quantity;
            int new_quantity;
            std::cout << "Введите количество: ";
            std::cin >> quantity;
            std::cout << "Введите новое количество";
            std::cin >> new_quantity;
            for (int i = 0; i < n; i++)
            {
                if (arr[i].quantity == quantity)
                {
                    arr[i].quantity = new_quantity;
                }
            }
            break;
        case 4:
            char date[11];
            char new_date[11];
            std::cout << "Введите дату: ";
            std::cin >> date;
            std::cout << "Введите новую дату: ";
            std::cin >> new_date;
            for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].date, date) == 0)
                {
                    strcpy(arr[i].date, new_date);
                }
            }
            break;
        case 5:
            bool isWeight;
            std::cout << "Введите 0, если указываете вес продукции, или любое другое значение если указываете объем: ";
            std::cin >> isWeight;
            if (!isWeight)
            {
                float weight;
                float new_weight;
                std::cout << "Введите вес(кг): ";
                std::cin >> weight;
                std::cout << "Введите новый вес: ";
                std::cin >> new_weight;
                for (int i = 0; i < n; i++)
                {
                    if (!arr[i].isWeight && arr[i].Measurement.weight == weight)
                    {
                        arr[i].Measurement.weight = new_weight;
                    }
                }
            }
            else
            {
                int volume;
                int new_volume;
                std::cout << "Введите объем(мл): ";
                std::cin >> volume;
                std::cout << "Введите новый объем(мл): ";
                std::cin >> new_volume;
                for (int i = 0; i < n; i++)
                {
                    if (arr[i].isWeight && arr[i].Measurement.volume == volume)
                    {
                        arr[i].Measurement.volume = new_volume;
                    }
                }
            }
            break;
        case 6:
            char party_str[9];
            char new_party_str[9];
            std::cout << "Введите размер партии(большая или маленькая): ";
            std::cin >> party_str;
            std::cout << "Введите новый размер партии(большая или маленькая): ";
            std::cin >> new_party_str;
            bool party;
            bool new_party;
            if (party_str == "большая" || party_str == "большая")
                party = true;
            else if (party_str == "маленькая" || party_str == "Маленькая")
                party = false;
            if (new_party_str == "большая" || new_party_str == "большая")
                new_party = true;
            else if (party_str == "маленькая" || party_str == "Маленькая")
                new_party = false;
            for (int i = 0; i < n; i++)
            {
                if (arr[i].party == party)
                {
                    arr[i].party = new_party;
                }
            }
            break;
        default:
            isexit = false;
            std::cout << "Неправильный ввод ";
            break;
        }
    } while (!isexit);
}