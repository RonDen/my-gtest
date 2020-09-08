#include <algorithm>
#include <cstdio>

/**
 * 插入排序，经典版
 */
void insert_sort(int *arr, int l, int r)
{
    if (l >= r)
        return;
    for (int i = l + 1; i <= r; i++)
    {
        int j = i;
        while (j - 1 >= l && arr[j] < arr[j - 1])
        {
            // int t = arr[j];
            // arr[j] = arr[j - 1];
            // arr[j - 1] = t;
            // j--;
            std::swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

/**
 * 插入排序，哨兵版本
 */
void insert_sort_v2(int *arr, int l, int r)
{
    if (l >= r)
        return;
    int idx = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i] < arr[idx])
            idx = i;
    }
    while (idx > l)
    {
        std::swap(arr[idx], arr[idx - 1]);
        idx--;
    }
    // std::swap(arr[l], arr[idx]);
    for (int i = l + 2; i <= r; i++)
    {
        int j = i;
        while (arr[j] < arr[j - 1])
        {
            // int t = arr[j];
            // arr[j] = arr[j - 1];
            // arr[j - 1] = t;
            std::swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

// #define BUG_INSERT

#ifdef BUG_INSERT
int main()
{
    int n = 5;
    int a[5] = {1, 2, 3, 4, 5};
    // int a[5] = {5, 4, 3, 2, 1};
    // insert_sort(a, 0, n - 1);
    insert_sort_v2(a, 0, n - 1);
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
#endif