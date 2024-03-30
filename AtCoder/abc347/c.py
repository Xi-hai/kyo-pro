n, a, b = map(int, input().split())
d = list(map(int, input().split()))
maximum = -1
minimum = (a+b)
for i in d:
    r = i % (a+b)
    if r < minimum:
        minimum = r
    if r > maximum:
        maximum = r
ans = False
if maximum - minimum < a:
    ans = True
else:
    maximum = -(a+b)
    minimum = (a+b)
    for i in d:
        r = i % (a+b)
        if r > (a+b)/2:
            r -= (a+b)
        if r < minimum:
            minimum = r
        if r > maximum:
            maximum = r
    if maximum - minimum < a:
        ans = True
print("Yes" if ans==True else "No")