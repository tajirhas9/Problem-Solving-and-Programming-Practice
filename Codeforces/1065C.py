from __future__ import print_function

n,k = map(int , raw_input().strip().split())
a = list(map(int,raw_input().strip().split()))

cur_sum = 0

minim = min(a)
Map = {x:0 for x in a}

for x in a:
    cur_sum += (x - minim)
    Map[x] = Map[x]+1
print(Map)
target_height = minim*n

cnt = 0

heights = list()

for key,value in Map.iteritems():
    heights.append(key)

sorted(heights)
heights.reverse()
print(heights)
for height in heights:
    if cur_sum - height * Map[height] == 0:
        continue
    if cur_sum - (height * Map[height]) <= k:
        cnt = cnt + 1
        cur_sum = height * Map[height]
        print(height , Map[height] , cur_sum)
print(cnt)
