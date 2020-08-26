#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

void partition(int* arr, int left, int right)
{
    if (left > right) return;
    int pivot = left;
    int low = left + 1;
    int high = right;
    while (true)
    {
        while (low <= right && arr[pivot] >= arr[low]) low++;
        while (high >= left + 1 && arr[pivot] <= arr[high]) high--;
        if (low >= high) break;
        int temp0 = arr[low];
        arr[low] = arr[high];
        arr[high] = temp0;
    }
    int temp1 = arr[high];
    arr[high] = arr[pivot];
    arr[pivot] = temp1;
    partition(arr, 0, high - 1);
    partition(arr, high + 1, right);
}

int main() {
    int n;
    scanf("%d", &n);

    int p[1000] = { 0 };

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);

        p[i] = temp;
    }

    partition(p, 0, n - 1);
    
    //x1*n + x2*(n-1) ...
    int sum = 0;
    int j = n;
    for (int i = 0; i < n; i++)
    {
        sum += p[i] * j;
        j--;
    }

    printf("%d", sum);

    return 0;
}
