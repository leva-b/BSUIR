#include "../Task_2.h"

void deleteStruct()
{
    bool isDeleteByValue;
    std::wcout << L"Введите 0 если хотите удалять продукцию по номеру\n"
              << L"или любое другое значение для удаления по заданному значению элементов: ";
    std::wcin >> isDeleteByValue;
    wcin.ignore();
    bool isExit;
    if (isDeleteByValue)
    {
        do
        {
            std::wcout << L"1. Название книиги\n";
            std::wcout << L"2. Автор\n";
            std::wcout << L"3. Регистрационный номер\n";
            std::wcout << L"4. Дата издания\n";
            std::wcout << L"5. Количество страниц\n";
            std::wcout << L"Введите номера признака для удаления по значению: ";
            int importance;
            std::wcin >> importance;
            wcin.ignore();
            isExit = false;
            switch (importance)
            {
            case 1:
                wchar_t name[50];
                std::wcout << L"Введите название для удаления книг: ";
                std::wcin.getline(name, sizeof(name));
                for (int i = 0; i < n; i++)
                {
                    if (wcscmp(arr[0].name, name) == 0)
                    {
                        deleteByValue(i);
                        // deleteStructFromFile(i);
                        i--;
                    }
                }
                break;
            case 2:
                wchar_t author[30];
                std::wcout << L"Введите фамилию автора для удаления книг: ";
                std::wcin.getline(author, sizeof(author)/sizeof(wchar_t));
                for (int i = 0; i < n; i++)
                {
                    if (wcscmp(arr[i].author, author) == 0)
                    {
                        deleteByValue(i);
                        // deleteStructFromFile(i);
                        i--;
                    }
                }
                break;
            case 3:
                wchar_t reg[20];
                std::wcout << L"Введите регистрационный номер для удаления книг: ";
                std::wcin.getline(reg, sizeof(reg));
                for (int i = 0; i < n; i++)
                {
                    if (wcscmp(arr[i].registerNumber, reg) == 0)
                    {
                        deleteByValue(i);
                        // deleteStructFromFile(i);
                        i--;
                    }
                }
                break;
            case 4:
                int date;
                std::wcout << L"Введите дату для удаления книг: ";
                std::wcin >> date;
                wcin.ignore();
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
                std::wcout << L"Введите количество страниц для удаления книг: ";
                std::wcin >> pages;
                wcin.ignore();
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
                std::wcout << L"Неверный ввод\n";
                isExit = true;
                break;
            }
        } while (isExit);
    }
    else
    {
        std::wstring input;
        std::wcout << L"Введите номера для удаления через пробел: ";
        std::getline(std::wcin >> std::ws, input);
        std::wstringstream ss(input);
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
            std::wcout << L"Ошибка изменения размера памяти!" << std::endl;
            return;
        }
        arr = new_array;
    }
}
