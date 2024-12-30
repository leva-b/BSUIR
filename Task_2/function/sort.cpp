#include "../Task_2.h"
#include <cwctype> 

int my_strcasecmp(wchar_t *str1, wchar_t *str2) {
    while (*str1 && *str2) {
        wchar_t c1 = towlower(*str1);
        wchar_t c2 = towlower(*str2);
        if (c1 != c2) {
            return c1 - c2;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2; 
}

void my_swap(book& a, book& b) {
    book temp = a;
    a = b;
    b = temp;
}

void quicksort(book arr[], unsigned int length) {
    unsigned int i, pivot = 0;
    if (length <= 1) 
        return;

    for (i = 0; i < length; i++) {

        if (my_strcasecmp(arr[i].author, arr[length - 1].author) < 0) {
            my_swap(arr[i], arr[pivot++]);
        }
    }

    my_swap(arr[pivot], arr[length - 1]);

    quicksort(arr, pivot);
    quicksort(arr + pivot + 1, length - pivot - 1);
}


void mySort()
{
    quicksort(arr, n);
    std::wcout << L"Отсортированный массив структур:\n";
    for (int i = 0; i < n; i++)
    {
        viewOneStruct(i);
        std::wcout << L'\n';
    }
}