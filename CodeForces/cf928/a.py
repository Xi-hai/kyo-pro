t = int(input())
for _ in range(t):
    s = input()
    cnt_a = 0
    for i in range(5):
        if s[i] == 'A':
            cnt_a += 1
    if cnt_a > 2:
        print('A')
    else:
        print('B')