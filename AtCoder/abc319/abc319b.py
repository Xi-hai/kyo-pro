n = int(input())
s = ""
for i in range(n+1):
    si = '-'
    for j in range(1, 10):
        if (n%j == 0 and i%(n//j) == 0):
            si = str(j)
            break
    s += si
print(s)