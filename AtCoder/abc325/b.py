n = int(input())
w = [0] * n
x = [0] * n
for i in range(n):
    w[i], x[i] = map(int, input().split())

ans = 0
for t in range(24):
    cnt = 0
    for i in range(n):
        start = (t + x[i]) % 24
        if 9 <= start and start <= 17:
            cnt += w[i]
    ans = max(ans, cnt)

print(ans)