s = input()

ans = "Yes"
for i in range(1, 16):
    if i%2 == 1 and s[i] != '0':
        ans = "No"

print(ans)