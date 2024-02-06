H, W, K = map(int, input().split())
grid = [input() for _ in range(H)]

ans = 1e9

for h in range(H):
    right = 0
    cnt_replace = 0
    left = 0
    for j in range(W):
        while right < W and right - left < K and grid[h][right] != 'x':
            if grid[h][right] == '.':
                cnt_replace += 1
            right += 1

        if right - left == K:
            ans = min(ans, cnt_replace)
        if right >= W:
            break
        if right - left < K and grid[h][right] == 'x':
            left = right
            cnt_replace = 0

        if grid[h][right] != 'x' and grid[h][left] == '.':
            cnt_replace -= 1
        if right == left:
            right += 1

        left += 1
        if left >= W-K+1:
            break

for w in range(W):
    right = 0
    cnt_replace = 0
    left = 0
    for i in range(H):
        while right < H and right - left < K and grid[right][w] != 'x':
            if grid[right][w] == '.':
                cnt_replace += 1
            right += 1

        if right - left == K:
            ans = min(ans, cnt_replace)
        if right >= H:
            break
        if right - left < K and grid[right][w] == 'x':
            left = right
            cnt_replace = 0

        if grid[right][w] != 'x' and grid[left][w] == '.':
            cnt_replace -= 1
        if right == left:
            right += 1

        left += 1
        if left >= H-K+1:
            break

if ans > H*W:
    ans = -1
print(ans)