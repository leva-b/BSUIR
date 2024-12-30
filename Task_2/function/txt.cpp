#include "../Task_2.h"
#include <limits>
#define MAX_LENGTH 100

void writeToFile()
{
    std::wofstream ofs(filename, std::ios::out);
    if (!ofs)
    {
        std::wcout << L"Ошибка открытия файла для записи!" << std::endl;
        return;
    }
    ofs << n << L'\n';
    for (int i = 0; i < n; i++)
    {
        ofs << arr[i].name << L','
            << arr[i].author << L','
            << arr[i].registerNumber << L','
            << arr[i].date << L','
            << (arr[i].isInt ? arr[i].numberOfPages.numberPage_int : arr[i].numberOfPages.numberPage_short) << L',';
        ofs << L'\n';
    }
    ofs.close();
}

void inputToArray()
{
    std::wifstream ifs(filename, std::ios::in);
    if (!ifs)
    {
        std::wcout << L"Ошибка открытия файла для записи!" << std::endl;
        return;
    }
    ifs >> n;
    ifs.ignore();
    arr = (book *)malloc(n * sizeof(book));
    if (arr == NULL || arr == nullptr)
    {
        std::wcout << L"Ошибка выделения памяти!" << std::endl;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        std::wstring line;
        std::getline(ifs, line);
        std::wistringstream wss(line);
        std::wstring token;

        book Book;

        wss.getline(arr[i].name, MAX_LENGTH, L',');
        wss.getline(arr[i].author, MAX_LENGTH, L',');
        wss.getline(arr[i].registerNumber, MAX_LENGTH, L',');
        wss >> arr[i].date;
        wss.ignore();

        int numberOfPages;
        wss >> numberOfPages;
        if (numberOfPages > std::numeric_limits<short>::max())
        {
            arr[i].isInt = true;
            arr[i].numberOfPages.numberPage_int = numberOfPages;
        }
        else
        {
            arr[i].isInt = false;
            arr[i].numberOfPages.numberPage_short = static_cast<short>(numberOfPages);
        }
    }
}