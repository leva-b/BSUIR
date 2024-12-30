typedef struct
{
    char name[50];
    char author[30];
    char registerNumber[20];
    int date;
    union
    {
        int numberPage_int;
        short numberPage_short;
    } numberOfPages;
    bool isInt;
} book;
