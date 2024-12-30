#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cstring> 
#include <fstream>
#include <cwchar>
#include "struct.h"
using namespace std;

const std::string filename = "Task_2.txt";
extern book *arr;
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
//void findStruct();
void deleteByValue(int);
void deleteStruct();
void whatChange();
void change();
void changeAll();
void mySort();
void writeToFile();
void inputToArray();