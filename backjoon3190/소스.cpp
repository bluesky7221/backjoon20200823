#include <iostream>
#include <vector>
#include <string>
#include <deque>
#pragma warning(disable:4996)
using namespace std;

const int MAX = 100;
typedef struct
{
    int y, x;
}
Dir;
Dir moveDir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; //E S W N
int N, K, L;
bool visited[MAX][MAX];
bool apple[MAX][MAX];
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> K;
    for (int k = 0; k < K; k++)
    {
        int y, x; cin >> y >> x;
        apple[y - 1][x - 1] = true;
    }
    cin >> L;
    deque<pair<int, char>> turn;
    for (int l = 0; l < L; l++)
    {
        int X; char C;
        cin >> X >> C;
        turn.push_back({ X, C });
    }
    int sec = 0;
    int idx = 0; //초기 오른쪽
    deque<pair<int, int>> snake;
    snake.push_back({ 0, 0 }); //초기 위치
    visited[0][0] = true;
    while (1)
    {
        sec++;
        pair<int, int> before = snake.back();
        pair<int, int> cur = { before.first + moveDir[idx].y, before.second + moveDir[idx].x }; //뱀의 머리가 몸에 부딪히거나, 범위를 벗어날 경우
        if (visited[cur.first][cur.second] || !(0 <= cur.first && cur.first < N && 0 <= cur.second && cur.second < N))
        {
            cout << sec << "\n"; break;
        }
        visited[cur.first][cur.second] = true;
        snake.push_back(cur); //사과가 있는 위치면 꼬리 그대로
        if (apple[cur.first][cur.second])
            apple[cur.first][cur.second] = false; //사과 없으면 꼬리가 있던 칸을 지운다
        else
        {
            pair<int, int> tail = snake.front();
            visited[tail.first][tail.second] = false;
            snake.pop_front();
        }
        //마지막에 방향 전환
        if (turn.size() && turn.front().first == sec)
        {
            if (turn.front().second == 'L')
                idx = (idx + 3) % 4;
            else idx = (idx + 1) % 4;
            turn.pop_front();
        }
    }
    return 0;
}

/*
int N, K, L;
int x = 1;
int y = 1;//현재 위치
vector<int*> tails;    //꼬리들 위치
vector<int*> apples;   //사괴들 위치
vector<int> rotation_s;    //L: 반시계 방향 90도 회전, D: 시계 방향 90도 회전
vector<char> rotation_c;
int s = 0;  //현재 시간
int r = 0;  //현재 각도 0: 오른쪽, 1: 아래쪽, 2: 왼쪽, 3: 위쪽

void Play()
{
    bool isDie = false;
    while(!isDie)
    {
        int* current = new int[2];
        current[0] = x;
        current[1] = y;
        
        //회전 확인
        if (!rotation_s.empty())
        {
            if (rotation_s[0] == s)
            {
                char temp = rotation_c[0];
                if (temp == 'L')
                {
                    r--;
                    if (r < 0)
                    {
                        r = 3;
                    }
                }
                else if (temp == 'D')
                {
                    r++;
                    if (r > 3)
                    {
                        r = 0;
                    }
                }
                rotation_s.erase(rotation_s.begin());
                rotation_c.erase(rotation_c.begin());
            }
        }

        //이동
        switch (r)
        {
        case 0: //오른쪽
            x++;
            break;
        case 1: //아래쪽
            y++;
            break;
        case 2: //왼쪽
            x--;
            break;
        case 3: //위쪽
            y--;
            break;
        default:
            break;
        }

        s++;

        //벽 Die 확인
        if (x < 1 || x > N || y < 1 || y > N)
        {
            isDie = true;
            break;
        }
        //꼬리 Die 확인
        for (int i = 0; i < tails.size(); i++)
        {
            if (tails[i][0] == x && tails[i][1] == y)
            {
                isDie = true;
            }
        }
        //사과 확인
        bool isApple = false;
        for (int i = 0; i < apples.size(); i++)
        {
            if (x == apples[i][0] && y == apples[i][1])
            {
                isApple = true;
                break;
            }
        }
        //꼬리 이동 + 늘리기 확인
        if (isApple)
        {
            tails.insert(tails.begin(), current);
        }
        else
        {
            tails.insert(tails.begin(), current);
            tails.erase(tails.end() - 1);
        }
    }
}

int main() {
    scanf("%d", &N);
    scanf("%d", &K);

    for (int i = 0; i < K; i++)
    {
        int* temp = new int[2];
        scanf("%d %d", &temp[1], &temp[0]);

        apples.push_back(temp);
    }

    scanf("%d", &L);
    for (int i = 0; i < L; i++)
    {
        int _s;
        char _r = 0;
        scanf("%d %c", &_s, &_r);

        rotation_s.push_back(_s);
        rotation_c.push_back(_r);
    }
    
    Play();

    printf("%d", s);

    return 0;
}
*/