#include <cstdio>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

static int zero;
static int one;

void fibonacciValue(int n) {
    zero = 1;
    one = 0;

    while (n != 0)
    {
        n--;
        int temp = zero;
        zero = one;
        one += temp;
    }
}

int fibonacci(int n) {
    if (n == 0) {
        zero++;
        return 0;
    }
    else if (n == 1) {
        one++;
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int count;
    scanf("%d", &count);

    int n;
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &n);

        //zero = 0, one = 0;
        //fibonacci(n);
        //printf("%d %d\n", zero, one);

        zero = 0, one = 0;
        fibonacciValue(n);

        printf("%d %d\n", zero, one);
    }
   
    return 0;
}