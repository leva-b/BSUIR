#include "../Task_2.h"

void deleteStruct()
{
    bool isDeleteByValue;
    std::cout << "Введите 0 если хотите удалять продукцию по номеру\n"
              << "или любое другое значение для удаления по заданному значению элементов: ";
    std::cin >> isDeleteByValue;
    cin.ignore();
    bool isExit;
    if (isDeleteByValue)
    {
        do
        {
            std::cout << "1. Название книиги\n";
            std::cout << "2. Автор\n";
            std::cout << "3. Регистрационный номер\n";
            std::cout << "4. Дата издания\n";
            std::cout << "5. Количество страниц\n";
            std::cout << "Введите номера признака для удаления по значению: ";
            int importance;
            std::cin >> importance;
            cin.ignore();
            isExit = false;
            switch (importance)
            {
            case 1:
                char name[50];
                std::cout << "Введите название для удаления книг: ";
                std::cin.getline(name, sizeof(name));
                for (int i = 0; i < n; i++)
                {
                    if (strcmp(arr[i].name, name) == 0)
                    {
                        deleteByValue(i);
                        // deleteStructFromFile(i);
                        i--;
                    }
                }
                break;
            case 2:
                char author[30];
                std::cout << "Введите фамилию автора для удаления книг: ";
                std::cin.getline(author, sizeof(author));
                for (int i = 0; i < n; i++)
                {
                    if (strcmp(arr[i].author, author) == 0)
                    {
                        deleteByValue(i);
                        // deleteStructFromFile(i);
                        i--;
                    }
                }
                break;
            case 3:
                char reg[20];
                std::cout << "Введите регистрационный номер для удаления книг: ";
                std::cin.getline(reg, sizeof(reg));
                for (int i = 0; i < n; i++)
                {
                    if (strcmp(arr[i].registerNumber, reg) == 0)
                    {
                        deleteByValue(i);
                        // deleteStructFromFile(i);
                        i--;
                    }
                }
                break;
            case 4:
                int date;
                std::cout << "Введите дату для удаления книг: ";
                std::cin >> date;
                cin.ignore();
                for (int i = 0; i < n; i++)
                {
                    if (arr[i].date == date)
                    {
                        deleteByValue(i);
                        // deleteStructFromFile(i);
                        i--;
                    }
                }
                break;
            case 5:
                int pages;
                std::cout << "Введите количество страниц для удаления книг: ";
                std::cin >> pages;
                cin.ignore();
                for (int i = 0; i < n; i++)
                {
                    if ((arr[i].isInt && arr[i].numberOfPages.numberPage_int == pages) || (!arr[i].isInt && arr[i].numberOfPages.numberPage_short == pages))
                    {
                        deleteByValue(i);
                        // deleteStructFromFile(i);
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
            numbers.push_back(number); 
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
            // deleteStructFromFile(num - 1 - count);
            count++;
        }
    }
}

void deleteByValue(int k)
{
    for (int i = k; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    if (n == 0)
    {
        free(arr);
        arr = nullptr;
    }
    else
    {
        book *new_array = (book *)realloc(arr, n * sizeof(book));
        if (new_array == nullptr)
        {
            std::cout << "Ошибка изменения размера памяти!" << std::endl;
            return;
        }
        arr = new_array;
    }
}
