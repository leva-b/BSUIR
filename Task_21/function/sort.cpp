#include "../Task_2.h"
#include <cctype> // Для функции tolower
#include <cstring> // Для функции strlen

// int my_strcasecmp(const char* str1, const char* str2) {
//     while (*str1 && *str2) {
        
//         char lower1 = tolower(static_cast<unsigned char>(*str1));
//         char lower2 = tolower(static_cast<unsigned char>(*str2));

//         if (lower1 != lower2) {
//             return lower1 - lower2;
//         }

//         str1++;
//         str2++;
//     }

//     return *str1 - *str2;
// }

int my_strcasecmp(char *str1, char *str2) {
    while (*str1 && *str2) {
        char c1 = tolower(static_cast<unsigned char>(*str1));
        char c2 = tolower(static_cast<unsigned char>(*str2));
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
    std::cout << "Отсортированный массив структур:\n";
    for (int i = 0; i < n; i++)
    {
        viewOneStruct(i);
        std::cout << '\n';
    }
}