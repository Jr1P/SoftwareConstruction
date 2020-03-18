#include <cstdio>

int s, a, b;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &s);

    for(int i = 0; i < 3; i++)
    {
        scanf("%d%d", &a, &b);
        if (s == a)
            s = b;
        else if (s == b)
            s = a;
    }
    printf("%d", s);

    return 0;
}
