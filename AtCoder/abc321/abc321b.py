n, x = map(int, input().split())
a = list(map(int, input().split()))
highest = 0
lowest = 100
sum = 0
for i in range(n-1):
    highest = max(highest, a[i])
    lowest = min(lowest, a[i])
    sum += a[i]

ans = -1
for i in range(0, highest+1):
    if i < lowest:
        sub_sum = sum - highest
        if sub_sum >= x:
            ans = i
            break
    elif i > highest:
        sub_sum = sum - lowest
        if sub_sum >= x:
            ans = i
            break
    else:
        sub_sum = sum + i - highest - lowest
        if sub_sum >= x:
            ans = i
            break
print(ans)