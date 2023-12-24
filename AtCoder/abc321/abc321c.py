numbers = []
for i in range(2, (1 << 10)):
    x = 0
    p = 1
    for j in range(10):
        if (i >> j) & 1:
            x += j * p
            p *= 10
    numbers.append(x)

numbers.sort()
k = int(input())
print(numbers[k-1])