#include "../Task_2.h"
#include <limits>

void inputStruct(int i)
{
    std::cout << "Введите данные " << i + 1 << " книги\n";
    std::cout << "Название: ";
    std::cin.getline(arr[i].name, sizeof(arr[i].name));

    std::cout << "Фамилия автора: ";
    std::cin.getline(arr[i].author, sizeof(arr[i].author));

    std::cout << "Регистрационный номер: ";
    std::cin.getline(arr[i].registerNumber, sizeof(arr[i].registerNumber));

    std::cout << "Год издания: ";
    std::cin >> arr[i].date;

    std::cout << "Количество страниц: ";
    int numberOfPages;
    std::cin >> numberOfPages;
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
    std::cin.ignore();
    std::cout << '\n';
}

void input()
{
    if (arr != nullptr || arr != NULL)
        free(arr);
    arr = nullptr;
    n = 0, siz = 100;
    int t;
    std::cout << "1. Ввод заранее известного количества книг\n";
    std::cout << "2. Ввод до появления заданного признака\n";
    std::cout << "3. Ввод c возможностью выхода в любой момент\n";
    std::cout << "4. Считывание данных из текстового файла\n\n";
    bool isCorrect = false;
    do
    {
        std::cin >> t;
        std::cin.ignore();
        isCorrect = false;
        switch (t)
        {
        case 1:
            inputN();
            break;
        case 2:
            inputSign();
            break;
        case 3:
            inputExit();
            break;
        case 4:
            // inputTxt();
            break;
        default:
            isCorrect = true;
        }
    } while (isCorrect);
}

void inputN()
{
    std::ofstream ofs;
    ofs.open("Task_2.txt", std::ios::out);
    if (!ofs)
    {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return;
    }
    std::cout << "\nВведите количество книг\n";
    std::cin >> n;
    std::cin.ignore();
    std::cout << '\n';
    if (n != 0)
        arr = (book *)malloc(n * sizeof(book));

    siz = n;
    for (int i = 0; i < n; i++)
    {
        inputStruct(i);
        // //writeCurrent(ofs, i);
    }
    ofs.close();
}

void inputSign()
{
    bool isCorrect;
    char Name[50], Autor[30], registerNumber[20];
    int date, page;
    int sign;
    do
    {
        std::cout << "Выберите номер признака по которому хотите останавливать ввод:" << std::endl;
        std::cout << "Структура имеет следующий вид\n";
        std::cout << "1. Название книги\n";
        std::cout << "2. Автор\n";
        std::cout << "3. Регистрационный номер\n";
        std::cout << "4. Дата издания\n";
        std::cout << "5. Количество страниц\n";
        std::cin >> sign;
        std::cin.ignore();
        isCorrect = false;

        switch (sign)
        {
        case 1:
            std::cin.getline(Name, sizeof(Name));
            break;
        case 2:
            std::cin.getline(Autor, sizeof(Autor));
            break;
        case 3:
            std::cin.getline(registerNumber, sizeof(registerNumber));
            break;
        case 4:
            std::cin >> date;
            std::cin.ignore();
            break;
        case 5:
            std::cin >> page;
            std::cin.ignore();
            break;
        default:
            std::cout << "Ошибка, введены неверные данные";
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
            if (strcmp(arr[n].name, Name) == 0)
                isbreak = true;
            break;
        case 2:
            if (strcmp(arr[n].author, Autor) == 0)
                isbreak = true;
            break;
        case 3:
            if (strcmp(arr[n].registerNumber, registerNumber) == 0)
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
    ofs.open("Task_2.txt", std::ios::out);
    if (!ofs)
    {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }
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

        string s;
        std::cout << "Введите данные " << n + 1 << " продукта или '*' для выхода\n";
        std::cout << "Название: ";
        
        getline(std::cin, s);
        if (s == "*")
            break;

        strcpy(arr[n].name, (s.substr(0,49)).c_str());


        std::cout << "Фамилия автора: ";
        std::cin.getline(arr[n].author, sizeof(arr[n].author));

        std::cout << "Регистрационный номер: ";
        std::cin.getline(arr[n].registerNumber, sizeof(arr[n].registerNumber));

        std::cout << "Год издания: ";
        std::cin >> arr[n].date;

        std::cout << "Количество страниц: ";
        int numberOfPages;
        std::cin >> numberOfPages;
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
        std::cout << '\n';
        // writeCurrent(ofs, n);
        n++;
        std::cin.ignore();
    }
    ofs.close();
}

void additionalInput()
{
    std::ofstream ofs;
    ofs.open("Task_2.txt", std::ios::out);
    if (!ofs)
    {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }
    int count;
    std::cout << "Введите количество структур для дополнения массива: ";
    std::cin >> count;
    std::cin.ignore();
    arr = (book *)realloc(arr, (n + count) * sizeof(book));
    for (int i = n; i < n + count; i++)
    {
        inputStruct(i);
        // writeCurrent(ofs, i);
    }
    n += count;
    ofs.close();
}
