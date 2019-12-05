a = int(input())
s = str(input())

sum = [0]*4000

l = len(s)

for i in range(0,l) :
    sum[i] = sum[i-1] + int(s[i])

for i in range(0,l) :
    for j in range(0,l) :
        x = sum[j] - sum[i-1]

