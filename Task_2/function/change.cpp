#include "../Task_2.h"
#include <limits>
void whatChange()
{
    std::wcout << L"Если хотите изменить конкретную структуру нажмите 1,";
    std::wcout << L"если хотите изменить все структуры по одному признаку нажмите другую клавишу: ";
    wstring chang;
    std::wcin >> chang;
    wcin.ignore();
    chang == L"1" ? change() : changeAll();
}
void change()
{
    int k;
    std::wcout << L"Введите номер структуры для изменения от 1 до " << n << L" : ";
    std::wcin >> k;
    wcin.ignore();
    k--;
    bool isexit = true;
    do
    {
        std::wcout << L"Структура имеет следующий вид\n";
        std::wcout << L"1. Название книиги\n";
        std::wcout << L"2. Автор\n";
        std::wcout << L"3. Регистрационный номер\n";
        std::wcout << L"4. Дата издания\n";
        std::wcout << L"5. Количество страниц\n";

        int choice;
        std::wcin >> choice;
        wcin.ignore();
        isexit = true;
        switch (choice)
        {
        case 1:
            wchar_t new_name[50];
            std::wcout << L"Введите новое наименование: ";
            std::wcin.getline(new_name, sizeof(new_name));
            wcscpy(arr[k].name, new_name);
            // writeCurrent(ofs, k, k);
            break;
        case 2:
            wchar_t new_author[30];
            std::wcout << L"Введите нового автора: ";
            std::wcin.getline(new_author, sizeof(new_author));
            wcscpy(arr[k].author, new_author);
            // writeCurrent(ofs, k, k);
            break;
        case 3:
            wchar_t regNumber[20];
            std::wcout << L"Введите новый регистрационный номер: ";
            std::wcin.getline(regNumber, sizeof(regNumber));
            wcscpy(arr[k].registerNumber, regNumber);
            // writeCurrent(ofs, k, k);
            break;
        case 4:
            int new_date;
            std::wcout << L"Введите новый год издания: ";
            std::wcin >> new_date;
            wcin.ignore();
            arr[k].date = new_date;
            // writeCurrent(ofs, k, k);
            break;
        case 5:
            int pages;
            std::wcout << L"Введите новое количество страниц: ";
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
            std::wcout << L"Неправильный ввод ";
            break;
        }
    } while (!isexit);
}

void changeAll()
{
    bool isexit = true;
    do
    {
        std::wcout << L"Введите номер признака для изменения информации: ";
        std::wcout << L"1. Название книиги\n";
        std::wcout << L"2. Автор\n";
        std::wcout << L"3. Регистрационный номер\n";
        std::wcout << L"4. Дата издания\n";
        std::wcout << L"5. Количество страниц\n";
        int choice;
        std::wcin >> choice;
        wcin.ignore();
        isexit = true;
        switch (choice)
        {
        case 1:
            wchar_t name[50];
            wchar_t new_name[50];
            std::wcout << L"Введите начальное название: ";
            std::wcin.getline(name, sizeof(name));
            std::wcout << L"Введите новое название: ";
            std::wcin.getline(new_name, sizeof(new_name));
            for (int i = 0; i < n; i++)
            {
                if (wcscmp(arr[i].name, name) == 0)
                {
                    wcscpy(arr[i].name, new_name);
                    // writeCurrent(ofs, i, i);
                }
            }
            break;
        case 2:
            wchar_t author[30];
            wchar_t new_author[30];
            std::wcout << L"Введите текущего автора: ";
            std::wcin.getline(author, sizeof(author));
            std::wcout << L"Введите нового автора: ";
            std::wcin.getline(new_author, sizeof(new_author));
            for (int i = 0; i < n; i++)
            {
                if (wcscmp(arr[i].author, author) == 0)
                {
                    wcscpy(arr[i].author, new_author);
                    // writeCurrent(ofs, i, i);
                }
            }
            break;
        case 3:
            wchar_t reg[20];
            wchar_t new_reg[20];
            std::wcout << L"Введите текущий регистрационный номер: ";
            std::wcin.getline(reg, sizeof(reg));
            std::wcout << L"Введите новый регистрационный номер: ";
            std::wcin.getline(new_reg, sizeof(new_reg));
            for (int i = 0; i < n; i++)
            {
                if (wcscmp(arr[i].registerNumber, new_reg) == 0)
                {
                    wcscpy(arr[i].registerNumber, new_reg);
                    // writeCurrent(ofs, i, i);
                }
            }
            break;
        case 4:
            int date;
            int new_date;
            std::wcout << L"Введите текущую дату издания: ";
            std::wcin >> date;
            std::wcout << L"Введите новую дату издания: ";
            std::wcin >> new_date;
            wcin.ignore();
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
            std::wcout << L"Введите текущее количество страниц: ";
            std::wcin >> numberOfPages;
            std::wcout << L"Введите новое количестов страниц: ";
            std::wcin >> new_numberOfPages;
            wcin.ignore();
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
            std::wcout << L"Неправильный ввод ";
            break;
        }
    } while (!isexit);
}