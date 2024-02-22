t = int(input())
M = (1 << 32) - 1
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    dct = dict()
    for i in a:
        if i in dct:
            dct[i] += 1
        else:
            dct[i] = 1

    for i in a:
        if i not in dct:
            continue
        k = i^M
        if k in dct:
            dct[k] -= 1
            if dct[k] == 0:
                dct.pop(k)
        dct[i] -= 1
        if dct[i] == 0:
            dct.pop(i)
        ans += 1
    print(ans)