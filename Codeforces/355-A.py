k,d = map(int, raw_input().split())
s = ""
s += str(d)

if k > 1 and d == 0 :
    print("No solution")
else :

    while len(s) < k :
        s += str(0)
    print(s);
