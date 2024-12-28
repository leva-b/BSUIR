#include "../Task_1.h"

void deleteStruct()
{
    bool isDeleteByValue;
    std::cout << "Введите 0 если хотите удалять продукцию по номеру\n"
              << "или любое другое значение для удаления по заданному значению элементов: ";
    std::cin >> isDeleteByValue;
    bool isExit;
    if (isDeleteByValue)
    {
        do
        {
            std::cout << "1. Наименование\n";
            std::cout << "2. Номер цеха\n";
            std::cout << "3. Количество\n";
            std::cout << "4. Дата произведения\n";
            std::cout << "5. Вес(кг)\n";
            std::cout << "6. объем(мл)\n";
            std::cout << "7. Партия\n";
            std::cout << "Введите номера признака для удаления по значению: ";
            int importance;
            std::cin >> importance;
            isExit = false;
            switch (importance)
            {
            case 1:
                char name[50];
                std::cout << "Введите наименование для удаления продукции: ";
                std::cin >> name;
                for (int i = 0; i < n; i++)
                {
                    if (strcmp(arr[i].name, name) == 0)
                    {
                        deleteByValue(i);
                        deleteStructFromFile(i);
                        i--;
                    }
                }
                break;
            case 2:
                int number;
                std::cout << "Введите номер цеха для удаления продукции: ";
                std::cin >> number;
                for (int i = 0; i < n; i++)
                {
                    if (arr[i].number == number)
                    {
                        deleteByValue(i);
                        deleteStructFromFile(i);
                        i--;
                    }
                }
                break;
            case 3:
                int quantity;
                std::cout << "Введите значение количество для удаления продукции: ";
                std::cin >> quantity;
                for (int i = 0; i < n; i++)
                {
                    if (arr[i].quantity == quantity)
                    {
                        deleteByValue(i);
                        deleteStructFromFile(i);
                        i--;
                    }
                }
                break;
            case 4:
                char date[11];
                std::cout << "Введите дату для удаления продукции: ";
                std::cin >> date;
                for (int i = 0; i < n; i++)
                {
                    if (strcmp(arr[i].date, date) == 0)
                    {
                        deleteByValue(i);
                        deleteStructFromFile(i);
                        i--;
                    }
                }
                break;
            case 5:
                float weight;
                std::cout << "Введите вес для удаления продукции: ";
                std::cin >> weight;
                for (int i = 0; i < n; i++)
                {
                    if (!arr[i].isWeight && arr[i].Measurement.weight == weight)
                    {
                        deleteByValue(i);
                        deleteStructFromFile(i);
                        i--;
                    }
                }
                break;
            case 6:
                int volume;
                std::cout << "Введите объем для удаления продукции: ";
                std::cin >> volume;
                for (int i = 0; i < n; i++)
                {
                    if (arr[i].isWeight && arr[i].Measurement.volume == volume)
                    {
                        deleteByValue(i);
                        deleteStructFromFile(i);
                        i--;
                    }
                }
                break;
            case 7:
                char party_str[9];
                cout << "Введите размер партии(большая или маленькая) для удаления продукции: ";
                cin >> party_str;
                bool party;
                if (party_str == "большая" || party_str == "большая")
                    party = true;
                else if (party_str == "маленькая" || party_str == "Маленькая")
                    party = false;
                for (int i = 0; i < n; i++)
                {
                    if (arr[i].party == party)
                    {
                        deleteByValue(i);
                        deleteStructFromFile(i);
                        i--;
                    }
                }
                break;
            default:
                std::cout << "Неверный ввод\n";
                isExit = true;
                break;
            }
        } while (isExit);
    }
    else
    {
        std::string input;
        std::cout << "Введите номера для удаления через пробел: ";
        std::getline(std::cin >> std::ws, input);
        std::stringstream ss(input);
        std::vector<int> numbers;
        int number;

        while (ss >> number)
        {
            numbers.push_back(number); // Добавляем число в вектор
        }
        int count = 0;
        sort(numbers.begin(), numbers.end());
        for (int num : numbers)
        {
            if (num > n || n < 1)
            {
                continue;
            }
            deleteByValue(num - 1 - count);
            deleteStructFromFile(num - 1 - count);
            count++;
        }
    }
}

void deleteByValue(int k) {
    for (int i = k; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--; 
    if (n == 0) {
        free(arr);
        arr = nullptr;
    } else {
        product *new_array = (product *)realloc(arr, n * sizeof(product));
        if (new_array == nullptr) {
            std::cout << "Ошибка изменения размера памяти!" << std::endl;
            return; 
        }
        arr = new_array;
    }
}
