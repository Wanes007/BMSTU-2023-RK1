#include "tasks_rk1.h"
#include <iostream>


char* NewC1(const char* x){
    char* NewS1 = new char[20];
    int count = 0;
    for(int i = 0; i < strlen(x); ++i){
        int k = 0;
        for(int j = i; j > 0; j--){
            if(x[i] == x[j-1]){
                count++;
                k++;
                break;
            }
        }
        if(k == 0){
            NewS1[i - count] = x[i];
            NewS1[i - count + 1] = '\0';
        }
    }
    return NewS1;
}

void WorkWithFile::readFromFile(const char *fileName){
    FILE* pFile;
    pFile = fopen(fileName, "r");
    fscanf(pFile, "%s", dataOfFile);
    fclose(pFile);
}

void WorkWithFile::prepareTestFile(const char *fileName){
    FILE* pFile;
    pFile = fopen(fileName, "w");
    int l = 20;
    int i;
    srand(time(nullptr));
    char b;
    for(i = 0; i < l; ++i){
        b = (rand() % ('z' - 'a' + 1)) + 'a';
        if(b < 'a')
            b = ' ';
        fwrite(&b, 1, sizeof(b), pFile);
    }
    fclose(pFile);
}

WorkWithFile::WorkWithFile(const char *fileName){
    prepareTestFile(fileName);
    readFromFile(fileName);
}

WorkWithFile::~WorkWithFile(){
    delete[] dataOfFile;
}

void WorkWithFile::writeStatInfoToFile(const char *outFile){
    char* c = NewC1(dataOfFile);
    int* count = new int[strlen(c)];
    for(int i = 0; i < strlen(c); ++i){
        count[i] = 0;
    }
    for(int i = 0; c[i] != '\0'; ++i){
        for(int j = 0; j < strlen(dataOfFile); ++j){
            if(c[i] == dataOfFile[j])
                count[i]++;
        }
    }
    FILE* pFile = fopen(outFile, "w");
    for(int i = 0; i < strlen(c); ++i){
        fprintf(pFile, "%c\t%d\n", c[i], count[i]);
    }
    fclose(pFile);
    delete[] c;
    delete[] count;
}





void buildTree(int height) {
    int i = 0, j;
    while (i < height) {
        j = 0;
        while (j < height - i) {
            std::cout << " ";
            j++;
        }
        j = 0;
        while (j < (i * 2 + 1)) {
            std::cout << "*";
            j++;
        }
        std::cout << std::endl;
        i++;
    }
}






char* convertDecToBin(int number){
    char* string = new char[33];
    int count = 0;
    for (int i =32; number >0; i--){
        string[i]= number%2 + '0';
        number = number / 2;
        count++;

    }
    char * CoolString = new char[count];
    int Index = 33 - count;
    for(int i = 0; i < count; i++){
        CoolString[i] = string[Index++];
        CoolString[i+1] = '\0';

    }
    delete[]string;
    return CoolString;
}

void writeToFile(const char* fileName, const char* strNum) {
    FILE *pFile = fopen(fileName, "w");
    fprintf(pFile, "%s", strNum);
    fclose(pFile);
}









void randFill(float* ar, int N){
    for(int i = 0; i < N; i++){
        ar[i] = static_cast<float>(rand())/RAND_MAX;
    }
}



std::vector<std::pair<int,float>> averStr2DArray(const float* ar, int colCount, int rowCount){
    std::vector<std::pair<int,float>> res(rowCount);
    for(int i = 0; i < rowCount; i++){
        float sum = 0;
        for(int j = 0; j < colCount; j++){
            sum += ar[i * colCount + j];
        }
        res[i] = std::make_pair(i,sum/colCount);
    }
    return res;
}
