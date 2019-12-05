prime = []
marked = [0]*(10000000/64+2)

def on(x) :
    return marked[x/64] & (1 << ((x%64)/2))
def mark(x) :
    marked[x/64] |= (1 << (x % 64)/2)
    return

def sieve(n) :
    i = 3
    while i * i <= n :
        if not on(i) :
            for j in range(i*i , n , i+i) :
                mark(j)
        i += 2
    prime.append(2)
    for i in range(3,n,2) :
        if not on(i) :
            prime.append(i)
    return

sieve(3200000)

n = int(input())
i = 0
cnt = 0
ans = 1
while prime[i] * prime[i] <= n : 
    while n % prime[i] == 0 :
        if cnt == 2 :
            break
        n /= prime[i]
        cnt  += 1
        ans *= prime[i]
    i += 1

if cnt == 0 :
    print '1 \n0'
elif n == 1 and cnt <= 2 :
    print '2\n'
elif n != 1 and cnt < 2 :
    print '2\n'
else :
    print '1'
    print ans

