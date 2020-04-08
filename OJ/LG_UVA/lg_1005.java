package LG;

import java.math.BigInteger;
import java.util.Scanner;

public class lg_1005 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt(), m = cin.nextInt();
        BigInteger[] base = new BigInteger[85];
        base[0] = new BigInteger(String.valueOf(1));
        for(int i = 1; i <= m + 2; i++)
            base[i] = new BigInteger(String.valueOf(base[i-1].multiply(new BigInteger(String.valueOf(2)))));
        BigInteger ans = new BigInteger(String.valueOf(0));
        for(int k = 1; k <= n; k++) {
            int[] A = new int[85];
            for(int i = 1; i <= m; i++)
                A[i] = cin.nextInt();
            BigInteger[][] dp = new BigInteger[85][85];
            for(int i = 0; i <= m + 2; i++)
                for(int j = 0; j <= m + 2; j++)
                    dp[i][j] = new BigInteger(String.valueOf(0));
            for(int i = 1; i <= m; i++) {
                for(int j = m; j >= i; j--) {
                    BigInteger bigInteger = base[m - j + i - 1];
                    dp[i][j] = dp[i][j].max(dp[i-1][j].add(bigInteger.multiply(new BigInteger(String.valueOf(A[i-1])))));
                    dp[i][j] = dp[i][j].max(dp[i][j+1].add(bigInteger.multiply(new BigInteger(String.valueOf(A[j+1])))));
                }
            }
            BigInteger MAX = new BigInteger(String.valueOf(0));
            for(int i = 1; i <= m; i++)
                MAX = MAX.max(dp[i][i].add(base[m].multiply(new BigInteger(String.valueOf(A[i])))));
            ans = ans.add(MAX);
        }
        System.out.println(ans.toString());
    }
}
