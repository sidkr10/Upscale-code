#include<bits/stdc++.h>
#define R 7
#define C 5
using namespace std;
bool isvalid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < R && j < C);
}
struct ele {
    int x, y;
};
bool isdelim(ele temp)
{
    return (temp.x == -1 && temp.y == -1);
}
bool checkall(int arr[][C])
{
    for (int i=0; i<R; i++)
       for (int j=0; j<C; j++)
          if (arr[i][j] == 1)
             return true;
    return false;
}
int rotOranges(int arr[][C])
{
    queue<ele> Q;
    ele temp;
    int ans = 0;
    for (int i=0; i<R; i++)
    {
       for (int j=0; j<C; j++)
       {
            if (arr[i][j] == 2)
            {
                temp.x = i;
                temp.y = j;
                Q.push(temp);
            }
        }
    }
    temp.x = -1;
    temp.y = -1;
    Q.push(temp);
    while (!Q.empty())
    {
        bool flag = false;
        while (!isdelim(Q.front()))
        {
            temp = Q.front();
            if (isvalid(temp.x+1, temp.y) && arr[temp.x+1][temp.y] == 1)
            {
                if (!flag) ans++, flag = true;
                arr[temp.x+1][temp.y] = 2;
                temp.x++;
                Q.push(temp);
            }
            if (isvalid(temp.x-1, temp.y) && arr[temp.x-1][temp.y] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x-1][temp.y] = 2;
                temp.x--;
                Q.push(temp);
                temp.x++;
            }
            if (isvalid(temp.x, temp.y+1) && arr[temp.x][temp.y+1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y+1] = 2;
                temp.y++;
                Q.push(temp);
                temp.y--;
            }
            if (isvalid(temp.x, temp.y-1) && arr[temp.x][temp.y-1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y-1] = 2;
                temp.y--;
                Q.push(temp);
            }

            Q.pop();
        }
        Q.pop();
        if (!Q.empty()) {
            temp.x = -1;
            temp.y = -1;
            Q.push(temp);
        }
    }
    return ans;
}
int calcfresh(int v[R][C])
{
    int fresh=0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(v[i][j]==1)
                fresh++;
        }
    }
    return fresh;
}
int calcrot(int v[R][C])
{
    int rotten=0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(v[i][j]==2)
                rotten++;
        }
    }
    return rotten;
}
int main()
{
    int arr[][C] = {{2, 1, 0, 2, 1},
                    {1, 0, 1, 2, 1},
                    {1, 0, 0, 2, 1},
                    {1, 0, 0, 0, 0},
                    {1, 1, 1, 1, 1},
                    {1, 0, 0, 0, 1},
                    {1, 0, 1, 0, 1}};
    int ans = rotOranges(arr);
    int f=calcfresh(arr);
    int r=calcrot(arr);
    cout << "time frames: " << ans << endl;
    cout << "fresh: " << f << endl;
    cout << "Rotten oranges: " << r << endl;
    return 0;
}
