#include "color.h"
#include "insert_sort.h"
#include "quick_sort.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int *getRandom(int n)
{
    int *res = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        res[i] = rand() % n;
    }
    return res;
}

bool check(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

void test_func(
    const char *file_name,
    const char *func_name,
    const int line_no,
    void (*func)(int *, int, int),
    int *arr,
    int n)
{
    int *tmp = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        tmp[i] = arr[i];
    long long s = clock();
    func(tmp, 0, n - 1);
    long long e = clock();

    if (!check(tmp, n))
    {
        printf(RED("[   Failure    ] %s %s %d"), file_name, func_name, line_no);
    }
    else
    {
        printf(GREEN("[    OK    ] %s %s %d"), file_name, func_name, line_no);
    }
    printf(YELLOW(" (%lld) \n"), (e - s) * 1000 / CLOCKS_PER_SEC);
    free(tmp);
    return;
}

#define TEST(func, arr, n) test_func(__FILE__, #func, __LINE__, func, arr, n)

int main()
{
#define MAXN 50000
    srand(time(0));
    int *arr = getRandom(MAXN);
    TEST(insert_sort, arr, MAXN);
    TEST(quick_sort_v1, arr, MAXN);
    TEST(quick_sort_v2, arr, MAXN);
    // void (*func)(int *, int, int) = quick_sort_v1;
    // func(arr, 0, MAXN - 1);
    // quick_sort_v1(arr, 0, MAXN - 1);
    // if (!check(arr, MAXN))
    // {
    //     printf(RED("[   Failure    ]\n"));
    // }
    // else
    // {
    //     printf(GREEN("[    OK    ]\n"));
    // }
    // for (int i = 0; i < MAXN; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");
#undef MAXN
    return 0;
}