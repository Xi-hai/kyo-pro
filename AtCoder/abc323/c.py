n, m = map(int, input().split())
a = list(map(int, input().split()))
s = [input() for _ in range(n)]

highest = 0
second_highest = 0
unsolved = [[] for _ in range(n)]
points_now = [i+1 for i in range(n)]
for i in range(n):
    for j in range(m):
        if s[i][j] == 'o':
            points_now[i] += a[j]
        else:
            unsolved[i].append(a[j])

    unsolved[i] = sorted(unsolved[i], reverse=True)
    if points_now[i] > highest:
        second_highest = highest
        highest = points_now[i]
    elif points_now[i] > second_highest:
        second_highest = points_now[i]

for i in range(n):
    if points_now[i] == highest and points_now[i] > second_highest:
        print(0)
    else:
        ans = 0
        while points_now[i] <= highest:
            points_now[i] += unsolved[i][ans]
            ans += 1
        print(ans)