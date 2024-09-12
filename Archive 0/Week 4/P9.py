t = int(input())

for _ in range(t):
    n = int(input())
    x = input()
    y = input()

    sp = ""
    for i in range(n-1):
        sp += x[i]
        if (x[i+1] > y[i]):
            sp += y[i:]
            break
    else:
        sp += y[-2:]

    print(sp)

    np = 0
    for i in range(n-1):
        if sp[i+1:] == y[i:]:
            np+=1
    
    if (x[-1] == y[-2]):
        np+=1

    print(np)