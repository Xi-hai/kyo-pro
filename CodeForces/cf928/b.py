t = int(input())
for _ in range(t):
    n = int(input())
    grid = [input() for i in range(n)]
    cnts = [s.count('1') for s in grid]
    st = set(cnts)
    if len(st) < 3:
        print('SQUARE')
    else:
        print('TRIANGLE')