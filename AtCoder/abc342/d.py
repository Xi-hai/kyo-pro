N = int(input())
a = list(map(int, input().split()))

counts = [0 for _ in range(202020)]
for i in range(N):
    if a[i] == 0:
        counts[0] += 1
        continue

    div = [0 for _ in range(500)]
    k = a[i]
    for j in range(2, 500):
        if j*j > a[i]:
            break
        while k % j == 0:
            div[j] += 1
            k //= j
    if k<500:
        div[k] += 1

    for j in range(2, 500):
        while div[j] > 1:
            a[i] //= (j*j)
            div[j] -= 2
    counts[a[i]] += 1

ans = counts[0] * (N - counts[0])
for i in range(202020):
    ans += counts[i] * (counts[i] - 1) // 2
print(ans)