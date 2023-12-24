n, t = map(str, input().split())
n = int(n)
len_t = len(t)
s = [input() for _ in range(n)]

def possible_fault(k: int, t1: str, m: int, t2: str) -> bool:
    res = False
    if k == m:
        if t1 == t2:
            res = True
        else:
            changed = False
            res = True
            for i in range(k):
                if t1[i] != t2[i]:
                    if not changed:
                        changed = True
                    else:
                        res = False
                        break

    elif k-1 == m:
        mem = 0
        res = True
        for i in range(m):
            if t1[i] != t2[i+mem]:
                if mem == 0:
                    mem = -1
                else:
                    res = False
    
    elif k+1 == m:
        mem = 0
        res = True
        for i in range(k):
            if t1[i] != t2[i+mem]:
                if mem == 0 and t1[i] == t2[i+1]:
                    mem = 1
                else:
                    res = False
    
    return res

ans = []
for i in range(n):
    m = len(s[i])
    if possible_fault(len_t, t, m, s[i]):
        ans.append(i+1)

print(len(ans))
print(*ans)