#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

long long zero;
long long one;

void fibonacciValue(int n) {
    zero = 1;
    one = 0;

    while (n != 0)
    {
        n--;
        long long temp = zero;
        zero = one;
        one += temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    fibonacciValue(n);

    cout << one;

    return 0;
}
