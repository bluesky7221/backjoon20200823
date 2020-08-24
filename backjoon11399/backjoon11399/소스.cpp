#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> p;

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);

        p.push_back(temp);
    }

    sort(p.begin(), p.end(), less<int>());
    
    //x1*n + x2*(n-1) ...
    int sum = 0;
    int j = p.size();
    for (int i = 0; i < p.size(); i++)
    {
        sum += p[i] * j;
        j--;
    }

    printf("%d", sum);

    return 0;
}
