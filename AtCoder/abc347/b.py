s = input()
n = len(s)
st = set()
for i in range(n):
    for j in range(1, n-i+1):
        st.add(s[i:i+j])
print(len(st))