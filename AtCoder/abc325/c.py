'''
1. BFS

import queue

dx = [1, 1, 0, -1, -1, -1, 0, 1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

h, w = map(int, input().split())
s = [input() for _ in range(h)]

q = queue.Queue()
cnt = 1
grid = [[-1 for j in range(w)] for i in range(h)]

for i in range(h):
    for j in range(w):
        if s[i][j] != '#' or grid[i][j] > 0:
            continue
        
        q.put([i, j])
        grid[i][j] = cnt
        while not q.empty():
            v = q.get()
            for k in range(8):
                nv = [v[0] + dx[k], v[1] + dy[k]]
                if nv[0] < 0 or h <= nv[0] or nv[1] < 0 or w <= nv[1]:
                    continue
                if s[nv[0]][nv[1]] != '#' or grid[nv[0]][nv[1]] > 0:
                    continue
                grid[nv[0]][nv[1]] = cnt
                q.put(nv)
        
        cnt += 1

ans = 0
for i in range(h):
    for j in range(w):
        if ans < grid[i][j]:
            ans = grid[i][j]

print(ans)
'''

# union find
MAX_H, MAX_W = 1000, 1000
par = [[i*MAX_W + j for j in range(MAX_W)] for i in range(MAX_H)]
tree_rank = [[0 for j in range(MAX_W)] for i in range(MAX_H)]

def find_uf(y: int, x: int) -> int:
    if par[y][x] == y*MAX_W + x:
        return y*MAX_W + x
    else:
        par[y][x] = find_uf(par[y][x]//MAX_W, par[y][x]%MAX_W)
        return par[y][x]

def merge_uf(y1:int, x1:int, y2:int, x2:int):
    p1 = find_uf(y1, x1)
    p2 = find_uf(y2, x2)
    if p1 == p2:
        return
    
    p1y, p1x = p1//MAX_W, p1%MAX_W
    p2y, p2x = p2//MAX_W, p2%MAX_W
    if tree_rank[p1y][p1x] < tree_rank[p2y][p2x]:
        par[p1y][p1x] = par[p2y][p2x]
    else:
        par[p2y][p2x] = par[p1y][p1x]
        if tree_rank[p1y][p1x] == tree_rank[p2y][p2x]:
            tree_rank[p1y][p1x] += 1
    return

dx = [1, 1, 0, -1, -1, -1, 0, 1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

h, w = map(int, input().split())
s = [input() for _ in range(h)]

for i in range(h):
    for j in range(w):
        if s[i][j] != '#':
            continue

        for k in range(8):
            m, n = i + dy[k], j + dx[k]
            if m<0 or h<=m or n<0 or w<=n or s[m][n] != '#':
                continue
            merge_uf(i, j, m, n)

ans = 0
for i in range(h):
    for j in range(w):
        if s[i][j] == '#' and par[i][j] == i*MAX_W + j:
            ans += 1

print(ans)