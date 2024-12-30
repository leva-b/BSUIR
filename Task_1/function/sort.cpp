#include "../Task_1.h"

void shekerSort()
{
    int factory;
    std::cout << "Введите номер цеха для сортировки по количеству выпущенных изделий: ";
    std::cin >> factory;
    std::cout << '\n';
    int left = 0, right = n - 1; 
    int flag = 1; 
   
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++) 
        {
            if (arr[i].quantity < arr[i + 1].quantity) 
            {             
                int t = arr[i].quantity;
                arr[i].quantity = arr[i + 1].quantity;
                arr[i + 1].quantity = t;
                flag = 1;      
            }
        }
        right--; 
        for (int i = right; i > left; i--)  
        {
            if (arr[i - 1].quantity < arr[i].quantity) 
            {            
                int t = arr[i].quantity;
                arr[i].quantity = arr[i - 1].quantity;
                arr[i - 1].quantity = t;
                flag = 1;    
            }
        }
        left++; 
        if(flag == 0) break;
    }
    int count = 0;
    std::ofstream ofs;
    ofs.open("binary.bin", std::ios::out | std::ios::binary);
    for(int i = 0; i < n; i++){
        writeCurrent(ofs, i);
        if(arr[i].number == factory){
            viewOneStruct(i);
            count++;
        }
    }
    ofs.close();
    if(!count){
        std::cout << "Информации по продукции данного цеха нет\n\n";
    }
}
