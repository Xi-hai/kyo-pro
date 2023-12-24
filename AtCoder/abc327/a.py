n = int(input())
s = input()
ans = False

for i in range(n-1):
    if s[i] == 'a' and s[i+1] == 'b':
        ans = True
        break
    if s[i] == 'b' and s[i+1] == 'a':
        ans = True
        break

print("Yes" if ans else "No")