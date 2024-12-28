#include "../Task_1.h"
#include <unistd.h>

void inputBinary()
{
    std::ifstream fs("binary.bin", std::ios::binary);
    if (!fs)
    {
        std::cout << "Ошибка открытия файла!\n";
        return;
    }

    fs.seekg(0, std::ios::end);
    std::streamsize fileSize = fs.tellg();

    n = fileSize / structSize;
    fs.seekg(0, std::ios::beg);
    if (n > 0)
    {
        arr = (product *)malloc(n * sizeof(product));
        if (arr == nullptr)
        {
            std::cerr << "Ошибка выделения памяти!\n";
            fs.close();
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            readCurrent(fs, i);
        }
    }
    fs.close();
}

void writeCurrent(std::ofstream &ofs, int k)
{
    ofs.write((char *)(&arr[k].name), sizeof(arr[k].name));
    ofs.write((char *)(&arr[k].number), sizeof(arr[k].number));
    ofs.write((char *)(&arr[k].quantity), sizeof(arr[k].quantity));
    ofs.write((char *)(&arr[k].date), sizeof(arr[k].date));
    ofs.write((char *)(&arr[k].isWeight), sizeof(arr[k].isWeight));
    ofs.write((char *)(&arr[k].Measurement), sizeof(arr[k].Measurement));
    ofs.write((char *)(&arr[k].party), sizeof(arr[k].party));
}

void writeCurrent(FILE *file, int k) {
    fwrite(arr[k].name, sizeof(arr[k].name), 1, file);
    fwrite(&arr[k].number, sizeof(arr[k].number), 1, file);
    fwrite(&arr[k].quantity, sizeof(arr[k].quantity), 1, file);
    fwrite(arr[k].date, sizeof(arr[k].date), 1, file);
    fwrite(&arr[k].isWeight, sizeof(arr[k].isWeight), 1, file);
    fwrite(&arr[k].Measurement, sizeof(arr[k].Measurement), 1, file);
    fwrite(&arr[k].party, sizeof(arr[k].party), 1, file);
}

void readCurrent(std::ifstream &ifs, int k)
{
    ifs.read((char *)(&arr[k].name), sizeof(arr[k].name));
    ifs.read((char *)(&arr[k].number), sizeof(arr[k].number));
    ifs.read((char *)(&arr[k].quantity), sizeof(arr[k].quantity));
    ifs.read((char *)(&arr[k].date), sizeof(arr[k].date));
    ifs.read((char *)(&arr[k].isWeight), sizeof(arr[k].isWeight));
    ifs.read((char *)(&arr[k].Measurement), sizeof(arr[k].Measurement));
    ifs.read((char *)(&arr[k].party), sizeof(arr[k].party));
}

void deleteStructFromFile(int indexToDelete) {
    FILE *file = fopen("binary.bin", "r+b");
    if (!file) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    int totalRecords = fileSize / structSize;

    if (indexToDelete < 0 || indexToDelete >= totalRecords) {
        std::cerr << "Индекс вне диапазона!" << std::endl;
        fclose(file);
        return;
    }

    product nextProduct;
    int position = structSize * indexToDelete;
    long nextPosition;

    fseek(file, position, SEEK_SET);

    
    int i = position;
    while (position < n* structSize) {
        nextPosition = ftell(file); 
        fseek(file, position, SEEK_SET);
        writeCurrent1(file, i + 1);
        position += structSize; 
        fseek(file, nextPosition, SEEK_SET);
    }

    ftruncate(fileno(file), position);

    fclose(file);
}