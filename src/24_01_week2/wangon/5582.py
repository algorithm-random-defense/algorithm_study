s1,s2 = input(), input()
ret = 0
dp = [[0] * 4000 for _ in range(4000)]

for i in range(len(s1)):
    for j in range(len(s2)):
        if (s1[i] == s2[j]):
            if (i == 0 or j == 0):
                dp[i][j] = 1
            else:
                dp[i][j] = dp[i-1][j-1] + 1
            ret = max(ret, dp[i][j])
print(ret)
