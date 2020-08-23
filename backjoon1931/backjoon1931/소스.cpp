#include <cstdio>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

//[]회의수, []시작시간,끝나는시간
vector<vector<int>> tables;
int max_count = 0;
int n;

void Find(int i, int j, vector<int> check, int count)
{
    if (j >= n)
    {
        if (max_count < count)
        {
            max_count = count;
        }
        return;
    }

    for (int l = 0; l < check.size(); l++)
    {
        if (tables[j][0] <= check[l] && tables[j][1] > check[l])
        {
            Find(i, j + 1, check, count);
            return;
        }
    }

    //겹치는게 없을 경우
    for (int l = tables[j][0]; l < tables[j][1]; l++)
    {
        check.push_back(l);
    }
    count++;
    Find(i, j + 1, check, count);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int f, l;
        scanf("%d %d", &f, &l);

        vector<int> temp;
        temp.push_back(f);
        temp.push_back(l);
        tables.push_back(temp);
    }
    
    vector<int> check;
    for (int i = 0; i < n; i++)
    {
        check.clear();
        Find(i, i, check, 0);
    }

    printf("%d", max_count);

    return 0;
}
