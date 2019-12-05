from __future__ import print_function
from collections import defaultdict

t = int(raw_input())
for _ in range(t):
    
    n = int(raw_input())
    a = list(map(int, raw_input().strip().split()))

    Map = {x:0 for x in range(10001) }

    for x in a:
        Map[a]++

    print(Map)
