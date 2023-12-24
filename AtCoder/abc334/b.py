a, m, l, r = map(int, input().split())

if a > l:
    a -= (a-l+1) // m * m
else:
    a += (l-a) // m * m
l -= a
r -= a
print(l, r)
ans = (r - l + 1) // m
# if l==0:
#     ans += 1

margin = 0
if l > 0:
    margin += m - l

if r%m != 0:
    margin += r - (r//m * m)

ans += margin // m
print(ans)