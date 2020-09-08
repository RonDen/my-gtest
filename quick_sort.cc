#include <algorithm>
#include <cstdio>
using namespace std;

#define my_swap(a, b)        \
    {                        \
        __typeof(a) __a = a; \
        a = b;               \
        b = __a;             \
    }

/**
 * 朴素版快速排序
 */
void quick_sort_v1(int *arr, int l, int r)
{
    if (l >= r)
        return;
    int x = l, y = r, z = arr[l];
    while (x < y)
    {
        while (x < y && arr[y] >= z)
            y--;
        if (x < y)
            arr[x] = arr[y];
        while (x < y && arr[x] <= z)
            x++;
        if (x < y)
            arr[y] = arr[x];
    }
    arr[x] = z;
    quick_sort_v1(arr, l, x - 1);
    quick_sort_v1(arr, x + 1, r);
}

/**
 * 单边优化版快速排序
 */
void quick_sort_v2(int *arr, int l, int r)
{
    if (l >= r)
        return;
    while (l < r)
    {
        int x = l, y = r, z = arr[l];
        while (x < y)
        {
            while (x < y && arr[y] >= z)
                y--;
            if (x < y)
                arr[x] = arr[y];
            while (x < y && arr[x] <= z)
                x++;
            if (x < y)
                arr[y] = arr[x];
        }
        arr[x] = z;
        if (x - l < r - y)
        {
            // 递归短的一边，让长的一边在本层处理
            quick_sort_v2(arr, l, x - 1);
            l = x + 1;
        }
        else
        {
            quick_sort_v2(arr, x + 1, r);
            r = x - 1;
        }
    }
}

/**
 * 单边优化版快速排序，优化循环判断
 */
void quick_sort_v3(int *arr, int l, int r)
{
    while (l < r)
    {
        int i = l - 1, j = r + 1;
        int x = arr[l];
        while (i < j)
        {
            while (arr[++i] < x)
                ;
            while (arr[--j] > x)
                ;
            if (i < j)
                my_swap(arr[i], arr[j]);
        }
        if (j - l < r - j)
        {
            quick_sort_v3(arr, l, j);
            l = j + 1;
        }
        else
        {
            quick_sort_v3(arr, j + 1, r);
            r = j;
        }
    }
}

/**
 * 单边优化版快速排序，随机选择分区
 */
void quick_sort_v4(int *arr, int l, int r)
{
    while (l < r)
    {
        int i = l - 1, j = r + 1;
        int idx = l + rand() % (r - l + 1);
        int x = arr[idx];
        while (i < j)
        {
            while (arr[++i] < x)
                ;
            while (arr[--j] > x)
                ;
            if (i < j)
                my_swap(arr[i], arr[j]);
        }
        if (j - l < r - j)
        {
            quick_sort_v4(arr, l, j);
            l = j + 1;
        }
        else
        {
            quick_sort_v4(arr, j + 1, r);
            r = j;
        }
    }
}

/**
 * 单边优化版快速排序，三点取中选取法
 */
void quick_sort_v5(int *arr, int l, int r)
{
    while (l < r)
    {
        int i = l - 1, j = r + 1;
        int a = arr[l], b = arr[r], c = arr[(l + r) >> 1];
        if (a > b)
            my_swap(a, b);
        if (a > c)
            my_swap(a, c);
        if (b > c)
            my_swap(b, c);
        int x = b;
        while (i < j)
        {
            while (arr[++i] < x)
                ;
            while (arr[--j] > x)
                ;
            if (i < j)
                my_swap(arr[i], arr[j]);
        }
        if (j - l < r - j)
        {
            quick_sort_v5(arr, l, j);
            l = j + 1;
        }
        else
        {
            quick_sort_v5(arr, j + 1, r);
            r = j;
        }
    }
}

void my_quick_sort(int *arr, int l, int r)
{
    if (l < r)
    {
        int i = l - 1;
        int j = r + 1;
        int x = arr[(l + r) >> 1];
        while (i < j)
        {
            while (arr[++i] < x)
                ;
            while (arr[--j] > x)
                ;
            if (i < j)
            {
                my_swap(arr[i], arr[j]);
            }
        }
        my_quick_sort(arr, l, j);
        my_quick_sort(arr, j + 1, r);
    }
}

// #define _DEBUG_QUICK_SORT

#ifdef _DEBUG_QUICK_SORT
int main()
{
    int n = 5;
    // int a[5] = {1, 2, 3, 4, 5};
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = rand() % n;
    quick_sort_v3(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
#endif