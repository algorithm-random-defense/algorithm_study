# 타일링
dp = ["1"] * 251

def add_num(a, b):
    ret = ""
    carry = 0
    i = len(a) - 1
    j = len(b) - 1
    while i >= 0 or j >= 0 or carry:
        _sum = carry
        if i >= 0:
            _sum += int(a[i])
            i -= 1
        if j >= 0:
            _sum += int(b[j])
            j -= 1
        carry = _sum // 10
        ret = str(_sum % 10) + ret
    return ret

for i in range(2, 251):
    dp[i] = add_num(dp[i-1], add_num(dp[i-2], dp[i-2]))

while True:
    try:
        n = int(input())
        print(dp[n])
    except EOFError:
        break
