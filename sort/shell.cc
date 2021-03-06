/*
 * @Author: zengqinxiong 
 * @Date: 2018-07-01 11:59:05 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-07-08 15:30:01
 */
#include "../util/array.h"

/**
 * @brief 希尔排序：插入排序的变种，使用递减步长每次排序小数组，逐步将数组变得有序，最后退化为步长为1的插入排序
 * 
 * @param array 
 * @param n 
 */
void shell(int *array, int n)
{
    for (int offset = n / 2; offset >= 1; offset /= 2)
    {
        // 进行按步长的插入排序
        for (int i = 1; i < n ; i += offset)
        {
            for (int j = i; j >= offset && isLess(array, j, j-offset); j -= offset)
            {
                swap(array, j, j - offset);
            }
        }
    }
}

void shellBook (int *array, int n)
{
    int h = 1;
    while (h < n / 3) h = 3 * h + 1;
    while (h >= 1)
    {
        for (int i = h; i < n; i++)
        {
            for (int j = i; j >= h && isLess(array, j, j - h); j -= h)
            {
                swap(array, j, j-h);
            }
        }
        h /= 3;
    }
}

int main(int argc, char const *argv[])
{
    int array[10] = {8,4,7,5,2,6,3,9,0,1};
    int *p = array;

    shell(p, 10);
    // shellBook(p, 10);
    print(p, 10);
    return 0;
}
