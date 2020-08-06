//POJ1077-经典BFS-八数码
//单组数据(HDU1043多组数据较强)
//正向搜索(用string类型会TLE,所以改用字符串+父结点及方向标记)
//Time:313Ms    Memory:9870K

#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

#define MAX 400000
#define AIM 46234    //123456780对应的康托Hash值

bool v[MAX];
char path[MAX];    //总路径
int len, tt;    //路径长

/*udlr*/
char *dir = "udlr";    //正向搜索
int mov[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

//八数码状态结构体
struct Node{
    int s[9];
    int loc;    //空位
    int status;    //Hash值-排列值
    int fa;    //记录父状态
    char d;    //到此状态的移动方向
}n[MAX];

int fac[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
//对序列ncur.s[9]康托展开-返回Hash值
int cantor(int s[9])
{
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        int num = 0;    //逆序数计数器
        for (int j = i + 1; j < 9; j++)
            if (s[j] < s[i])
                num++;
        sum += num*fac[9 - i - 1];
    }
    return sum + 1;
}

/*反向记录路径*/
void count_path(Node end)
{
    int f = end.fa;
    len = 0;
    path[len++] = end.d;
    while (f)
    {
        path[len++] = n[f].d;
        f = n[f].fa;
    }
}

bool BFS()
{
    memset(v, 0, sizeof(v));
    Node next;    //下一临时状态
    int head = 0, tail = 0;

    n[0].status = cantor(n[0].s);
    v[n[0].status] = true;
    while (head <= tail)    //模拟队列
    {
        bool f = false;
        if (n[head].status == AIM)    //达到AIM
        {
            count_path(n[head]);
            return true;
        }
        //计算二维坐标
        int x = n[head].loc / 3;
        int y = n[head].loc % 3;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + mov[i][0];
            int ty = y + mov[i][1];
            if (tx < 0 || tx>2 || ty < 0 || ty>2)continue;
            //新状态更新
            next = n[head];
            next.loc = tx * 3 + ty;    //计算新空位
            next.s[n[head].loc] = next.s[next.loc];    //原空位替换
            next.s[next.loc] = 0;    //新空位
            next.fa = head;
            next.d = dir[i];
            next.status = cantor(next.s);
            //判重并入队
            if (!v[next.status])
            {
                v[next.status] = true;
                if (next.status == AIM)
                {
                    count_path(next);
                    return true;
                }
                n[++tail] = next;
                // if(!f) tt++, f = false;
            }
        }
        head++;
    }
    return false;
}

int main()
{
    /*input*/
    char ch[3];
    for (int i = 0; i < 9; i++)
    {
        scanf("%s",ch);
        if (!strcmp(ch,"x"))
        {
            n[0].s[i] = 0;
            n[0].loc = i;
        }
        else n[0].s[i] = ch[0] - '0';
    }

    /*output*/
    if (BFS())
    {    //反向输出路径
        for (int i = len - 1; i>=0; i--)
            printf("%c", path[i]);
        printf("\n");
        // printf("%d\n", tt);
    }
    else
        printf("unsolvable\n");
    return 0;
}