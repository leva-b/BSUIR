#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cstring> 
#include <fstream>

using namespace std;

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

extern product *arr;
extern int n;
extern int siz;
extern int structSize;

void menu();
void input();
void inputN();
void inputExit();
void inputSign();
void viewArray();
void additionalInput();
void viewOneStruct(int);
void findStruct();
void deleteByValue(int);
void deleteStruct();
void whatChange();
void change();
void changeAll();
void shekerSort();
void inputBinary();
void writeCurrent(ofstream&, int);
void writeCurrent(FILE *, int); 
void readCurrent(ifstream&, int);
void deleteStructFromFile(int indexToDelete);