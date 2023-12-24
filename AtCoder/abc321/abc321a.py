s = input()
n = len(s)
ans = True
for i in range(n-1):
    if s[i] <= s[i+1]:
        ans = False
        break
print("Yes" if ans else "No")