MOD = 998244353
MOD_over = [1]
for i in range(70000):
    MOD_over.append((MOD_over[-1]*(10**9-MOD)) % MOD)
s = ['1']
erase_cnt = 0
Q = int(input())
for _ in range(Q):
    q = list(map(int, input().split()))
    if q[0] == 1:
        s.append(chr(q[1] + ord('0')))
    elif q[0] == 2:
        erase_cnt += 1
    else:
        s = s[erase_cnt:]
        erase_cnt = 0
        num_str = "".join(s)
        digit = 0
        ans = 0
        while len(num_str) > 0:
            length = len(num_str)
            tmp_str = num_str[max(length-9, 0):]
            ans += int(tmp_str) * MOD_over[digit] % MOD

            num_str = num_str[:length-9] if length>9 else ""
            digit += 1
        print(ans)