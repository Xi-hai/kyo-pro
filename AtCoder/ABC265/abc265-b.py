n, m, t = map(int, input().split())
a = list(map(int, input().split()))
bonus = [0 for _ in range(n)]
for _ in range(m):
    x, y = map(int, input().split())
    bonus[x-1] = y
room = 0
for _ in range(n):
    t -= a[room]
    if t <= 0:
        break
    room += 1
    t += bonus[room]
if room == n:
    print("Yes")
else:
    print("No")