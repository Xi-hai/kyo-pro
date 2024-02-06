n = int(input())
a = list(map(int, input().split()))
a_rev = [-1 for _ in range(n+1)]
for i in range(n):
    if a[i] == -1:
        a_rev[0] = i+1
    else:
        a_rev[a[i]] = i+1

v = 0
ans = []
for i in range(n):
    ans.append(a_rev[v])
    v = a_rev[v]
print(*ans)