m = int(input())
d = list(map(int, input().split()))
all = sum(d)

mid = (all + 1) // 2
for i in range(m):
    if mid > d[i]:
        mid -= d[i]
        continue
    print("{} {}".format(i+1, mid))
    break