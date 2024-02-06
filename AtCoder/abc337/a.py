n = int(input())
taka = 0
aoki = 0
for i in range(n):
    x, y = map(int, input().split())
    taka += x
    aoki += y

if taka > aoki:
    print("Takahashi")
elif taka < aoki:
    print("Aoki")
else:
    print("Draw")