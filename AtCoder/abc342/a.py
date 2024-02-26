s = input()
n = len(s)
if s[0] != s[1] and s[1] == s[2]:
    print(1)
    exit()
for i in range(n-1):
    if s[i] != s[i+1]:
        print(i+2)
        break