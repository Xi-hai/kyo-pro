import numpy as np
a, b, x = map(int, input().split())
theta = None
if a*a*b < x*2:
    # a*b*(b/tan(theta)) / 2 == x
    theta = np.arctan(a*b*b*0.5 / x)
else:
    # a*a*(a*tan(theta)) / 2 == a*a*b - x
    theta = np.arctan(2*(a*a*b - x) / (a*a*a))
print(theta * 180 / np.pi)