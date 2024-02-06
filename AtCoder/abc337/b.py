s = input()
n = len(s)
ans = "Yes"
for i in range(1, n):
    if s[i] == 'A' and s[i-1] != 'A':
        ans = "No"
    if s[i] == 'B' and s[i-1] == 'C':
        ans = "No"
print(ans)