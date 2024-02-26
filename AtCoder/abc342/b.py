N = int(input())
p = list(map(int, input().split()))
Q = int(input())
for _ in range(Q):
    a, b = map(int, input().split())
    for i in range(N):
        if p[i] == a:
            print(a)
            break
        if p[i] == b:
            print(b)
            break