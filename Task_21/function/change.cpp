#include "../Task_2.h"
#include <limits>
void whatChange()
{
    std::cout << "Если хотите изменить конкретную структуру нажмите 1,";
    std::cout << "если хотите изменить все структуры по одному признаку нажмите другую клавишу: ";
    string chang;
    std::cin >> chang;
    cin.ignore();
    chang == "1" ? change() : changeAll();
}
void change()
{
    int k;
    std::cout << "Введите номер структуры для изменения от 1 до " << n << " : ";
    std::cin >> k;
    cin.ignore();
    k--;
    bool isexit = true;
    std::ofstream ofs("binary.bin", std::ios::in | std::ios::out | std::ios::binary);
    do
    {
        std::cout << "Структура имеет следующий вид\n";
        std::cout << "1. Название книиги\n";
        std::cout << "2. Автор\n";
        std::cout << "3. Регистрационный номер\n";
        std::cout << "4. Дата издания\n";
        std::cout << "5. Количество страниц\n";

        int choice;
        std::cin >> choice;
        cin.ignore();
        isexit = true;
        switch (choice)
        {
        case 1:
            char new_name[50];
            std::cout << "Введите новое наименование: ";
            std::cin.getline(new_name, sizeof(new_name));
            strcpy(arr[k].name, new_name);
            // writeCurrent(ofs, k, k);
            break;
        case 2:
            char new_author[30];
            std::cout << "Введите нового автора: ";
            std::cin.getline(new_author, sizeof(new_author));
            strcpy(arr[k].author, new_author);
            // writeCurrent(ofs, k, k);
            break;
        case 3:
            char regNumber[20];
            std::cout << "Введите новый регистрационный номер: ";
            std::cin.getline(regNumber, sizeof(regNumber));
            strcpy(arr[k].registerNumber, regNumber);
            // writeCurrent(ofs, k, k);
            break;
        case 4:
            int new_date;
            std::cout << "Введите новый год издания: ";
            std::cin >> new_date;
            cin.ignore();
            arr[k].date = new_date;
            // writeCurrent(ofs, k, k);
            break;
        case 5:
            int pages;
            std::cout << "Введите новое количество страниц: ";
            if (pages > std::numeric_limits<short>::max())
            {
                arr[k].isInt = true;
                arr[k].numberOfPages.numberPage_int = pages;
            }
            else
            {
                arr[k].isInt = false;
                arr[k].numberOfPages.numberPage_short = pages;
            }
            break;
        default:
            isexit = false;
            std::cout << "Неправильный ввод ";
            break;
        }
    } while (!isexit);
    ofs.close();
}

void changeAll()
{
    bool isexit = true;
    do
    {
        std::cout << "Введите номер признака для изменения информации: ";
        std::cout << "1. Название книиги\n";
        std::cout << "2. Автор\n";
        std::cout << "3. Регистрационный номер\n";
        std::cout << "4. Дата издания\n";
        std::cout << "5. Количество страниц\n";
        int choice;
        std::cin >> choice;
        cin.ignore();
        isexit = true;
        std::ofstream ofs("binary.bin", std::ios::in | std::ios::out | std::ios::binary);
        switch (choice)
        {
        case 1:
            char name[50];
            char new_name[50];
            std::cout << "Введите начальное название: ";
            std::cin.getline(name, sizeof(name));
            std::cout << "Введите новое название: ";
            std::cin.getline(new_name, sizeof(new_name));
            for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].name, name) == 0)
                {
                    strcpy(arr[i].name, new_name);
                    // writeCurrent(ofs, i, i);
                }
            }
            break;
        case 2:
            char author[30];
            char new_author[30];
            std::cout << "Введите текущего автора: ";
            std::cin.getline(author, sizeof(author));
            std::cout << "Введите нового автора: ";
            std::cin.getline(new_author, sizeof(new_author));
            for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].author, author) == 0)
                {
                    strcpy(arr[i].author, new_author);
                    // writeCurrent(ofs, i, i);
                }
            }
            break;
        case 3:
            char reg[20];
            char new_reg[20];
            std::cout << "Введите текущий регистрационный номер: ";
            std::cin.getline(reg, sizeof(reg));
            std::cout << "Введите новый регистрационный номер: ";
            std::cin.getline(new_reg, sizeof(new_reg));
            for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].registerNumber, new_reg) == 0)
                {
                    strcpy(arr[i].registerNumber, new_reg);
                    // writeCurrent(ofs, i, i);
                }
            }
            break;
        case 4:
            int date;
            int new_date;
            std::cout << "Введите текущую дату издания: ";
            std::cin >> date;
            std::cout << "Введите новую дату издания: ";
            std::cin >> new_date;
            cin.ignore();
            for (int i = 0; i < n; i++)
            {
                if (arr[i].date == date)
                {
                    arr[i].date = new_date;
                    // writeCurrent(ofs, i, i);
                }
            }
            break;
        case 5:
            int numberOfPages, new_numberOfPages;
            std::cout << "Введите текущее количество страниц: ";
            std::cin >> numberOfPages;
            std::cout << "Введите новое количестов страниц: ";
            std::cin >> new_numberOfPages;
            cin.ignore();
            for (int i = 0; i < n; i++)
            {
                if ((arr[i].isInt && arr[i].numberOfPages.numberPage_int == numberOfPages) || (!arr[i].isInt && arr[i].numberOfPages.numberPage_short == numberOfPages))
                    if (numberOfPages > std::numeric_limits<short>::max())
                    {
                        arr[i].isInt = true;
                        arr[i].numberOfPages.numberPage_int = new_numberOfPages;
                    }
                    else
                    {
                        arr[i].isInt = false;
                        arr[i].numberOfPages.numberPage_short = new_numberOfPages;
                    }
            }
            break;
        default:
            isexit = false;
            std::cout << "Неправильный ввод ";
            break;
        }
        ofs.close();
    } while (!isexit);
}