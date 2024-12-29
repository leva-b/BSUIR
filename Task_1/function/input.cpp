#include "../Task_1.h"

void inputStruct(int i)
{
    std::cout << "Введите данные " << i + 1 << " продукта\n";
    std::cout << "Наименование: ";
    std::cin >> arr[i].name;

    std::cout << "Номер цеха: ";
    std::cin >> arr[i].number;

    std::cout << "Количество: ";
    std::cin >> arr[i].quantity;
    if (arr[i].quantity > 100)
    {
        std::cout << "Партия: большая\n";
        arr[i].party = true;
    }
    else
    {
        std::cout << "Партия: маленькая\n";
        arr[i].party = false;
    }

    std::cout << "Дата производства: ";
    std::cin >> arr[i].date;

    std::cout << "Введите 0, если указываете вес продукции, или любое другое значение если указываете объем: ";
    std::cin >> arr[i].isWeight;
    if (!arr[i].isWeight)
    {
        std::cout << "Вес (кг): ";
        std::cin >> arr[i].Measurement.weight;
    }
    else
    {
        std::cout << "Объем (мл): ";
        std::cin >> arr[i].Measurement.volume;
    }
    std::cout << '\n';
}

void input()
{
    free(arr);
    arr = nullptr;
    n = 0, siz = 100;
    int t;
    std::cout << "1. Ввод заранее известного количества продуктов\n";
    std::cout << "2. Ввод до появления заданного признака\n";
    std::cout << "3. Ввод c возможностью выхода в любой момент\n";
    std::cout << "4. Считывание данных из бинарного файла\n\n";
    bool isCorrect = false;
    do
    {
        std::cin >> t;
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
            inputBinary();
            break;
        default:
            isCorrect = true;
        }
    } while (isCorrect);
}

void inputN()
{
    std::ofstream ofs;
    ofs.open("binary.bin", std::ios::out | std::ios::binary);
    if (!ofs)
    {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }
    std::cout << "\nВведите количество продуктов\n";
    std::cin >> n;
    std::cout << '\n';
    if (n != 0)
        arr = (product *)malloc(n * sizeof(product));

    siz = n;
    for (int i = 0; i < n; i++)
    {
        inputStruct(i);
        writeCurrent(ofs, i);
    }
    ofs.close();
}

void inputSign()
{
    bool isCorrect;
    char Name[50], Date[11];
    int number, quantity, weight, volume;
    int sign;
    do
    {
        std::cout << "Выберите номер признака по которому хотите останавливать ввод:" << std::endl;
        std::cout << "1. Наименование\n";
        std::cout << "2. Номер цеха\n";
        std::cout << "3. Количество\n";
        std::cout << "4. Дата произведения\n";
        std::cout << "5. Вес(кг)\n";
        std::cout << "6. Объем(мл)\n\n";
        std::cin >> sign;
        isCorrect = false;

        switch (sign)
        {
        case 1:
            std::cin >> Name;
            break;
        case 2:
            std::cin >> number;
            break;
        case 3:
            std::cin >> quantity;
            break;
        case 4:
            std::cin >> Date;
            break;
        case 5:
            std::cin >> weight;
            break;
        case 6:
            std::cin >> volume;
            break;
        default:
            std::cout << "Ошибка, введены неверные данные";
            isCorrect = true;
            break;
        }
    } while (isCorrect);
    bool isbreak = false;
    std::ofstream ofs;
    ofs.open("binary.bin", std::ios::out | std::ios::binary);
    if (!ofs)
    {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }
    n = 0;
    while (true)
    {

        if (n == 0)
        {
            arr = (product *)malloc(siz * sizeof(product));
        }
        else if (n == siz)
        {
            siz *= 2;
            product *arr1 = (product *)malloc(siz * sizeof(product));
            for (int i = 0; i < n; i++)
            {
                arr1[i] = arr[i];
            }
            free(arr);
            arr = arr1;
        }
        inputStruct(n);
        writeCurrent(ofs, n);

        switch (sign)
        {
        case 1:
            if (strcmp(arr[n].name, Name) == 0)
                isbreak = true;
            break;
        case 2:
            if (arr[n].number == number)
                isbreak = true;
            break;
        case 3:
            if (arr[n].quantity == quantity)
                isbreak = true;
            break;
        case 4:
            if (strcmp(arr[n].date, Date) == 0)
                isbreak = true;
            break;
        case 5:
            if (arr[n].isWeight && arr[n].Measurement.weight == weight)
                isbreak = true;
            break;
        case 6:
            if (!arr[n].isWeight && arr[n].Measurement.volume == volume)
                isbreak = true;
            break;
        }
        n++;
        if (isbreak)
        {

            break;
        }
    }
    ofs.close();
}

void inputExit()
{
    std::ofstream ofs;
    ofs.open("binary.bin", std::ios::out | std::ios::binary);
    if (!ofs)
    {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }
    while (true)
    {
        if (n == 0)
        {
            arr = (product *)malloc(siz * sizeof(product));
        }
        else if (n == siz)
        {
            siz *= 2;
            product *arr1 = (product *)malloc(siz * sizeof(product));
            for (int i = 0; i < n; i++)
            {
                arr1[i] = arr[i];
            }
            free(arr);
            arr = arr1;
        }

        std::cout << "Введите данные " << n + 1 << " продукта или '*' для выхода\n";
        std::cout << "Наименование: ";
        string s;

        std::cin >> s;
        if (s == "*")
            break;
        strcpy(arr[n].name, s.c_str());

        std::cout << "Номер цеха: ";
        std::cin >> arr[n].number;

        std::cout << "Количество: ";
        std::cin >> arr[n].quantity;
        if (arr[n].quantity > 100)
        {
            std::cout << "Партия: большая\n";
            arr[n].party = true;
        }
        else
        {
            std::cout << "Партия: маленькая\n";
            arr[n].party = false;
        }

        std::cout << "Дата производства: ";
        std::cin >> arr[n].date;

        std::cout << "Введите 0, если указываете вес продукции, или любое другое значение если указываете объем: ";
        std::cin >> arr[n].isWeight;
        if (!arr[n].isWeight)
        {
            std::cout << "Вес (кг): ";
            std::cin >> arr[n].Measurement.weight;
        }
        else
        {
            std::cout << "Объем (мл): ";
            std::cin >> arr[n].Measurement.volume;
        }
        std::cout << '\n';
        writeCurrent(ofs, n);
        n++;
    }
    ofs.close();
}

void additionalInput()
{
    std::ofstream ofs;
    ofs.open("binary.bin", std::ios::out | std::ios::binary | std::ios::app);
    if (!ofs)
    {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }
    int count;
    std::cout << "Введите количество структур для дополнения массива: ";
    std::cin >> count;
    arr = (product *)realloc(arr, (n + count) * sizeof(product));
    for (int i = n; i < n + count; i++)
    {
        inputStruct(i);
        writeCurrent(ofs, i);
    }
    n += count;
    ofs.close();
}
