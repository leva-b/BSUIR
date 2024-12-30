typedef struct
{
    wchar_t name[50];
    wchar_t author[30];
    wchar_t registerNumber[20];
    int date;
    union
    {
        int numberPage_int;
        short numberPage_short;
    } numberOfPages;
    bool isInt;
} book;
