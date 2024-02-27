import bisect
N = int(input())
S = input()
li_RGB = [[] for _ in range(3)]
for i in range(N):
    if S[i] == 'R':
        li_RGB[0].append(i)
    elif S[i] == 'G':
        li_RGB[1].append(i)
    else:
        li_RGB[2].append(i)

len_RGB = [len(li_RGB[i]) for i in range(3)]
li_RGB = [sorted(li_RGB[i]) for i in range(3)]

ans = 0
idx_rot = [
    [0, 1, 2],
    [0, 2, 1],
    [1, 0, 2],
    [1, 2, 0],
    [2, 0, 1],
    [2, 1, 0]
]
for i in range(6):
    ix, iy, iz = idx_rot[i]
    for j in li_RGB[ix]:
        k_low = bisect.bisect_right(li_RGB[iy], j)
        for k in range(k_low, len_RGB[iy]):
            h_low = bisect.bisect_right(li_RGB[iz], li_RGB[iy][k])
            h_NG = li_RGB[iz][h_low:].count(2*li_RGB[iy][k] - j)
            ans += len_RGB[iz] - h_low
            if h_NG > 0:
                ans -= 1

print(ans)