    #include <cstdio>
    #define N 5050

    int n, k;

    int main()
    {
        scanf("%d%d", &n, &k);
        int d = (k < n-k+1)?k:n-k+1;
        int ans;
        if (k != 1 && k != n)
            ans = 3*d+2*(n-d)+n-1;
        else
            ans = 3*n;
        printf("%d\n", ans);
        return 0;
    }
