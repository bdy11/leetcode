#include "InsertionSort.h"

void swap(int (&arr)[], int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}
void insertionSort(int (&arr)[], int size)
{
    for (int i = 0; i < size; i++)
    {
        // 寻找元素 arr[i] 合适的插入位置
        for (int j = i; j > 0; j--)
            if (arr[j] < arr[j - 1])
                swap(arr, j, j - 1);
            else
                break;
    }
}

