#include "../Task_2.h"
#include <limits>

void inputStruct(int i)
{
    std::wcout << L"Введите данные " << i + 1 << L" книги\n";
    std::wcout << L"Название: ";
    std::wcin.getline(arr[i].name, sizeof(arr[i].name) / sizeof(wchar_t));

    std::wcout << L"Фамилия автора: ";
    std::wcin.getline(arr[i].author, sizeof(arr[i].author));

    std::wcout << L"Регистрационный номер: ";
    std::wcin.getline(arr[i].registerNumber, sizeof(arr[i].registerNumber));

    std::wcout << L"Год издания: ";
    std::wcin >> arr[i].date;

    std::wcout << L"Количество страниц: ";
    int numberOfPages;
    std::wcin >> numberOfPages;
    if (numberOfPages > std::numeric_limits<short>::max())
    {
        arr[i].isInt = true;
        arr[i].numberOfPages.numberPage_int = numberOfPages;
    }
    else
    {
        arr[i].isInt = false;
        arr[i].numberOfPages.numberPage_short = numberOfPages;
    }
    std::wcin.ignore();
    std::wcout << L'\n';
}

void input()
{
    if (arr != nullptr || arr != NULL)
        free(arr);
    arr = nullptr;
    n = 0, siz = 100;
    int t;
    std::wcout << L"1. Ввод заранее известного количества книг\n";
    std::wcout << L"2. Ввод до появления заданного признака\n";
    std::wcout << L"3. Ввод c возможностью выхода в любой момент\n";
    std::wcout << L"4. Считывание данных из текстового файла\n\n";
    bool isCorrect = false;
    do
    {
        std::wcin >> t;
        std::wcin.ignore();
        isCorrect = false;
        switch (t)
        {
        case 1:
            inputN();
            writeToFile();
            break;
        case 2:
            inputSign();
            writeToFile();
            break;
        case 3:
            inputExit();
            writeToFile();
            break;
        case 4:
            inputToArray();
            break;
        default:
            isCorrect = true;
        }
    } while (isCorrect);
}

void inputN()
{
    std::wcout << L"\nВведите количество книг\n";
    std::wcin >> n;
    std::wcin.ignore();
    std::wcout << L'\n';
    if (n != 0)
        arr = (book *)malloc(n * sizeof(book));
    siz = n;
    for (int i = 0; i < n; i++)
    {
        inputStruct(i);
        // //writeCurrent(ofs, i);
    }

}

void inputSign()
{
    bool isCorrect;
    wchar_t Name[50], Autor[30], registerNumber[20];
    int date, page;
    int sign;
    do
    {
        std::wcout << L"Выберите номер признака по которому хотите останавливать ввод:" << std::endl;
        std::wcout << L"Структура имеет следующий вид\n";
        std::wcout << L"1. Название книги\n";
        std::wcout << L"2. Автор\n";
        std::wcout << L"3. Регистрационный номер\n";
        std::wcout << L"4. Дата издания\n";
        std::wcout << L"5. Количество страниц\n";
        std::wcin >> sign;
        std::wcin.ignore();
        isCorrect = false;

        switch (sign)
        {
        case 1:
            std::wcin.getline(Name, sizeof(Name) / sizeof(wchar_t));
            break;
        case 2:
            std::wcin.getline(Autor, sizeof(Autor) / sizeof(wchar_t));
            break;
        case 3:
            std::wcin.getline(registerNumber, sizeof(registerNumber) / sizeof(wchar_t));
            break;
        case 4:
            std::wcin >> date;
            std::wcin.ignore();
            break;
        case 5:
            std::wcin >> page;
            std::wcin.ignore();
            break;
        default:
            std::wcout << L"Ошибка, введены неверные данные";
            isCorrect = true;
            break;
        }
    } while (isCorrect);
    bool isbreak = false;

    n = 0;
    while (true)
    {

        if (n == 0)
        {
            arr = (book *)malloc(siz * sizeof(book));
        }
        else if (n == siz)
        {
            siz *= 2;
            book *arr1 = (book *)malloc(siz * sizeof(book));
            for (int i = 0; i < n; i++)
            {
                arr1[i] = arr[i];
            }
            free(arr);
            arr = arr1;
        }
        inputStruct(n);
        ////writeCurrent(ofs, n);

        switch (sign)
        {
        case 1:
            if (wcscmp(arr[n].name, Name) == 0)
                isbreak = true;
            break;
        case 2:
            if (wcscmp(arr[n].author, Autor) == 0)
                isbreak = true;
            break;
        case 3:
            if (wcscmp(arr[n].registerNumber, registerNumber) == 0)
                isbreak = true;
            break;
        case 4:
            if (arr[n].date = date)
                isbreak = true;
            break;
        case 5:
            if ((arr[n].isInt && arr[n].numberOfPages.numberPage_int == page) || (!arr[n].isInt && arr[n].numberOfPages.numberPage_short == page))
                isbreak = true;
            break;
        }
        n++;
        if (isbreak)
        {
            break;
        }
    }
}

void inputExit()
{
    std::ofstream ofs;
    while (true)
    {
        if (n == 0)
        {
            arr = (book *)malloc(siz * sizeof(book));
        }
        else if (n == siz)
        {
            siz *= 2;
            book *arr1 = (book *)malloc(siz * sizeof(book));
            for (int i = 0; i < n; i++)
            {
                arr1[i] = arr[i];
            }
            free(arr);
            arr = arr1;
        }

        wstring s;
        std::wcout << L"Введите данные " << n + 1 << L" продукта или '*' для выхода\n";
        std::wcout << L"Название: ";

        getline(std::wcin, s);
        if (s == L"*")
            break;

        int length = s.length() < 49 ? s.length() : 49; // Убедитесь, что не превышаем размер
        s.copy(arr[0].name, length);                       // Копируем нужное количество символов
        arr[0].name[length] = L'\0';

        std::wcout << L"Фамилия автора: ";
        std::wcin.getline(arr[n].author, sizeof(arr[n].author) / sizeof(wchar_t));

        std::wcout << L"Регистрационный номер: ";
        std::wcin.getline(arr[n].registerNumber, sizeof(arr[n].registerNumber));

        std::wcout << L"Год издания: ";
        std::wcin >> arr[n].date;

        std::wcout << L"Количество страниц: ";
        int numberOfPages;
        std::wcin >> numberOfPages;
        if (numberOfPages > std::numeric_limits<short>::max())
        {
            arr[n].isInt = true;
            arr[n].numberOfPages.numberPage_int = numberOfPages;
        }
        else
        {
            arr[n].isInt = false;
            arr[n].numberOfPages.numberPage_short = numberOfPages;
        }
        std::wcout << L'\n';
        // writeCurrent(ofs, n);
        n++;
        std::wcin.ignore();
    }
}

void additionalInput()
{
    std::wofstream ofs(filename, std::ios::out);
    if (!ofs) {
        std::wcout << L"Ошибка открытия файла для записи!" << std::endl;
        return;
    }
    
    int count;
    std::wcout << L"Введите количество структур для дополнения массива: ";
    std::wcin >> count;
    std::wcin.ignore();
    arr = (book *)realloc(arr, (n + count) * sizeof(book));
    for (int i = n; i < n + count; i++)
    {
        inputStruct(i);
        ofs << arr[i].name << L','
            << arr[i].author << L','
            << arr[i].registerNumber << L','
            << arr[i].date << L','
            << (arr[i].isInt ? arr[i].numberOfPages.numberPage_int : arr[i].numberOfPages.numberPage_short) << L'\n';
        // writeCurrent(ofs, i);
    }
    n += count;
    ofs.close();
}
