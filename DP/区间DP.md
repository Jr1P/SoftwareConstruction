# 区间DP

## 常用板子

```cpp
for(int len = 1; len <= n; len++) {
	for(int l = 1; l <= n - len + 1; l++) {
		int r = l + len - 1;
		for(int k = i; k <= r; k++)
			dp[l][r] = f(dp[l][r], dp[l][k] + dp[k][r] + "代价");
	}
}		
```

