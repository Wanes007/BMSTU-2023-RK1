#include "tasks_rk1.h"

void task_1(){
    WorkWithFile a("sourceFile_task1.txt");
    a.writeStatInfoToFile("result_sourceFile_task1.txt");
}

void task_2(){
    convertDecToBin(25);
}

void task_4(){
    buildTree (5);
}

void task_5(){
    const int N = 5;
    const int M = 3;
    float ar[N][M];
    randFill(&ar[0][0], N*M);
    std::vector<std::pair<int,float>> res = averStr2DArray(&ar[0][0],M,N);
    FILE* pFile = fopen("result_task5.txt", "w");
    for(std::pair<int,float> p:res)
        fprintf(pFile, "%d\t%c\t%f\n", p.first, ':', p.second);
    fclose(pFile);
}

int main(){
    //task_1();
    //task_4();
    //std::cout<<  convertDecToBin(25);
    //task_2();
    //task_5();
    return 0;
}