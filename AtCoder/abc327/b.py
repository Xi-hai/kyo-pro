b = int(input())
ans = -1

for a in range(1, b+1):
    n = pow(a, a)
    if n > b:
        break
    if n == b:
        ans = a
        break

print(ans)