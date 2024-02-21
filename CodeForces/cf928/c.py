pref_sum = [0, 1, 3, 6, 10, 15, 21, 28, 36, 45]
t = int(input())
for _ in range(t):
    n = int(input())
    s_n = str(n)
    m = len(s_n) - 1
    ans = 0
    for i in range(m):
        ans += 45 * ( n // (10**(i+1)) ) * (10**i)
        ans += pref_sum[int(s_n[m-i])] * (n % (10**i) + 1)
    if m==0:
        ans = pref_sum[n]
    print(f'ans={ans}')