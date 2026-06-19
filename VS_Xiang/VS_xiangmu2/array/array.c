#include"array.h"
#include<stdio.h>
#include<stdlib.h>

const BLOCK_SIZE = 20;

// typedef struct {
//     int *array;
//     int size;
// } Array;

Array array_create(int init_size)
{
    Array a;
    a.array=(int*)malloc(sizeof(int)*init_size);
    a.size=init_size;
    return a;
}

void array_free(Array *a)
{
    free(a->array);
    //防止别人调两次
    a->array = NULL;
    a->size = 0;
}

//封装,保护内部的实现细节
//防止"printf("%d\n",a.size);"今后由于其他原因无法实现
int array_size(const Array *a)
{
    return a->size;
}

int* array_at(Array *a, int index)
{
    if(index >= a->size){
        array_inflate(a, (index/BLOCK_SIZE+1)*BLOCK_SIZE-a->size);
    }
    return &(a->array[index]);
}

void array_inflate(Array *a, int more_size)
{
    int*p(int*)malloc(sizeof(int)(a->size+more_size));
    int i;
    //下面这个循环可以用memcpy函数实现
    for( i=0; i<a->size; i++ ){
        p[i] = a->arrat[i];
    }
    free(a->array);
    a->array = p;
    a->size += more_size;
}

int main(int argc,char const *argv[])
{
    Array a = array_create(100);
    printf("%d\n",array_size(&a));
    *array_at(&a,0)=10;     //定位到数组的那个位置，并对其赋值
    printf("%d\n",*array_at(&a,0));
    int number=0;
    int cnt=0;
    while(number != -1){
        scanf("%d",&number);
        if( number != -1)
            *array_at(&a, cnt++) = number;
    }
    array_free(&a);

    return 0;
}