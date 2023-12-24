n, k = map(int, input().split())
a = list(map(int, input().split()))

socks = []

idx = 0
for i in range(2*n):
    color = (i+2)//2
    if idx < k and color == a[idx]:
        idx += 1
    else:
        socks.append(color)

ans = 0
if k%2 == 0:
    for i in range(0, 2*n-k, 2):
        ans += socks[i+1] - socks[i]

else:
    max_diff = 0
    for i in range(k-1):
        max_diff = max(max_diff, a[i+1] - a[i])
        idx = i

    ans1 = 0
    ans2 = 0
    
print(ans)