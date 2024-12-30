#include <iostream>
#include <cwctype> // Для towlower
#include <clocale>

// Сравнение строк без учета регистра
int my_strcasecmp(const wchar_t* str1, const wchar_t* str2) {
    while (*str1 && *str2) {
        wchar_t c1 = towlower(*str1); // Используем wchar_t
        wchar_t c2 = towlower(*str2);
        if (c1 != c2) {
            return c1 - c2;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2; 
}

// Функция swap для строк (меняем указатели)
void my_swap(const wchar_t*& a, const wchar_t*& b) {
    const wchar_t* temp = a;
    a = b;
    b = temp;
}

// Функция быстрой сортировки для массива строк
void quicksort(const wchar_t* arr[], unsigned int length) {
    if (length <= 1) 
        return;

    const wchar_t* pivot = arr[length - 1];
    unsigned int i, pivotIndex = 0;

    for (i = 0; i < length - 1; i++) {
        if (my_strcasecmp(arr[i], pivot) < 0) {
            my_swap(arr[i], arr[pivotIndex++]);
        }
    }

    my_swap(arr[pivotIndex], arr[length - 1]);

    quicksort(arr, pivotIndex);
    quicksort(arr + pivotIndex + 1, length - pivotIndex - 1);
}

// Функция для вывода отсортированного массива строк
void mySort(const wchar_t* arr[], unsigned int n) {
    quicksort(arr, n);
    std::wcout << L"Отсортированный массив строк:\n";
    for (unsigned int i = 0; i < n; i++) {
        std::wcout << arr[i] << L'\n';
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    const wchar_t* arr[] = {
        L"Книга А",
        L"автор Б",
        L"Автор А",
        L"Книга Б",
        L"Книга В"
    };
    unsigned int n = sizeof(arr) / sizeof(arr[0]);

    mySort(arr, n);

    return 0;
}