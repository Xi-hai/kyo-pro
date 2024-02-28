X, Y, A, B = map(int, input().split())
dp = [X]
for _ in range(10101010):
    if dp[-1] >= Y:
        print(len(dp)-2)
        break
    dp.append(min(dp[-1]*A, dp[-1]+B))
# print(dp)