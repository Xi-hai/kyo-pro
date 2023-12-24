n = int(input())
s = [input() for _ in range(n)]

li = [[0, -1] for _ in range(n)]
for i in range(n):
    li[i][1] = i

for i in range(n):
    for j in range(n):
        if i==j:
            continue
        if s[i][j] == 'o':
            li[i][0] -= 1
        else:
            li[j][0] -= 1

li_sort = sorted(li)
for i in range(n):
    print(li_sort[i][1] + 1, end=" ")