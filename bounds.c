#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

void pedirArreglo(int a[], unsigned int length){
  unsigned int i=0;
  int e = 0;
  do{
    printf("Ingrese el valor para el lugar %d\n",i);
     scanf("%d",&e);
    a[i]=e;
    i=i+1;
  } while(i<length);
}

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    unsigned int i = 0;
    struct bound_data res;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    while (i < length)
    {
        if (value < arr[i])
        {
            res.is_upperbound = false;
        }
        if (value > arr[i])
        {
            res.is_lowerbound = false;
        }
        if (value == arr[i])
        {
            res.exists = true;
            res.where = i;
        }
        i = i +1;
    }
    return res;
}

int main(void) {
    int a[ARRAY_SIZE];
    int value;
    pedirArreglo(a, ARRAY_SIZE);
    printf("Ingrese un valor a verificar ");
    scanf("%d", &value);
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);
    printf("%d\n", result.is_upperbound);
    printf("%d\n", result.is_lowerbound);
    printf("%u\n", result.exists);
    printf("%u\n", result.where);

    return EXIT_SUCCESS;
}