#include <stdio.h>
#include <string.h>

enum Cmp    {
            LESS = -1,
            EQ = 0,
            MORE = 1
            };


enum Type   {
            INT = 1,
            CHAR = 2,
            DOUBLE = 3,
            FLOAT = 4
            };

int marinka(int (*cmp)(void *a, void *b), void *a, void *b);
int numCompare(void *a, void *b);
int strCompare(void *a, void *b);



int main(){

    int a = 0, b = 0;

    scanf("%d%d", &a, &b);

    printf("\n%d\n", marinka(&numCompare, (void *) &a, (void *) &b));
}


int marinka(int (*cmp)(void *a, void *b), void *a, void *b){

    return (*cmp)(a, b);
}

int numCompare(void *a, void *b){

    int dif = *(int *) a - *(int *) b;

    if (dif > 0) return 1;
    if (dif < 0) return -1;
    return 0;
}

int strCompare(void *a, void *b){

    int dif = strcmp((char *) a, (char *) b);

    if (dif > 0) return 1;
    if (dif < 0) return -1;
    return 0;
}
