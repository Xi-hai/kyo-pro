N = int(input())
dam = list(map(int, input().split()))
mountain = [0 for _ in range(N)]

for i in range(N):
    if i%2 == 0:
        mountain[0] += dam[i]
    else:
        mountain[0] -= dam[i]
mountain[0] //= 2

for i in range(1, N):
    mountain[i] = dam[i-1] - mountain[i-1]

for i in range(N):
    mountain[i] *= 2

print(*mountain)