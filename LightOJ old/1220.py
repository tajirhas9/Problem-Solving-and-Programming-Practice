import math

data = []*70000
MAX = pow(2,32)
sqrnMax = math.sqrt(MAX)

def gen():
    sqrnMax++

    for i in range(2,sqrnMax,2):
        x = 1

        while (x <= MAX) :
            data[i].append(x)
            x *= i


T = input()

for kase in range(1,T):
    n = input()
    sqrn = math.sqrt(n)
    start = 2
    if ( n & 1 ) :
        start = 3
    else:
        start = 2

    for i in range(start,sqrnMax,2):


