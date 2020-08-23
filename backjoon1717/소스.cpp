#include <cstdio>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

vector<int> parent;

int Find(int node) {
    if (parent[node] == node)
        return node;
    else
        return parent[node] = Find(parent[node]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    parent[b] = a;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++)
        parent.push_back(i);

    int cmd, a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &cmd, &a, &b);

        if (cmd == 0) {
            Union(a, b);
        }
        else {
            if (Find(a) == Find(b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
