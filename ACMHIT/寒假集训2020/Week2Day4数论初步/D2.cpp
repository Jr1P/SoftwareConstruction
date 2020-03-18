#include <cstdio>

int a[10] = {1, 5, 11, 36, 95, 281, 781, 2245, 6336, 18061};

int main()
{
    int x, y, z, u, v;
    bool f;
    for (x = -10; x <= 10; x++)
        for (y = -10; y <= 10; y++)
            for (z = -10; z <= 10; z++)
                for (u = -10; u <= 10; u++)
                    for (v = -10; v <= 10; v++)
                    {
                        f = true;
                        for (int i = 4; i < 10; i++)
                        {
                            if (a[i] != x * a[i - 1] + y * a[i - 2] + z * a[i - 3] + u * a[i - 4] + v)
                            {
                                f = false;
                                break;
                            }
                        }
                        if (f)
                        {
                            printf("%d %d %d %d %d\n", x, y, z, u, v);
                            return 0;
                        }
                    }
    return 0;
}