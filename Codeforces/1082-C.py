from collections import defaultdict

n,m = map(int , raw_input().split())

Map = defaultdict(list)

for _ in range(n):
    s,r = map(int, raw_input().split())
    Map[s].append(r)

x = int(0)

for key,value in Map.iteritems():
    Map[key].sort(reverse=True)
    x = max(x , len(value))

for key,value in Map.iteritems():
    for i in range(1,len(value)):
        Map[key][i] += Map[key][i]

        i = i+1
ans = 0
while x>0:
    temp = 0
    for key,value in Map.iteritems():
        if x > len(value):
            continue
        if value[x-1] < 0:
            continue
        temp += value[x-1]
    ans = max(ans , temp)
    x = x-1;

print ans
