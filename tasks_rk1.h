#include <iostream>
#include <Windows.h>
#include <cstring>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <vector>

#ifndef UNTITLED_TASKS_RK1_H
#define UNTITLED_TASKS_RK1_H
char* NewC1(const char* x);
class WorkWithFile{
private :
    char* dataOfFile = new char[20];

    void readFromFile(const char* fileName);

    void prepareTestFile(const char* fileName);

public :
    WorkWithFile(const char* fileName);

    ~WorkWithFile();

    void writeStatInfoToFile(const char* outFile);

};



void buildTree(int height);



char* convertDecToBin(int number);
void writeToFile(const char* fileName, const char* strNum);


void randFill(float* ar, int N);

std::vector<std::pair<int,float>> averStr2DArray(const float* ar, int colCount, int rowCount);

#endif //UNTITLED_TASKS_RK1_H
