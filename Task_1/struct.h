typedef struct
{
    char name[50];
    int number;
    int quantity;
    char date[11];
    union
    {
        float weight;
        int volume;
    } Measurement;
    int isWeight;
    bool party;
} product;
