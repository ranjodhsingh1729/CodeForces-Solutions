# cook your dish here
t = int(input())

for _ in range(t):
    n, m = [int(i) for i in input().strip().split()]
    arrn = [int(i) for i in input().strip().split()]
    
    sum = 0
    for i in arrn:
        sum += i
        

    sums = dict()
    for i in range(n):
        for j in range(i+1, n):
            sums[2*sum-arrn[i]-arrn[j]] = (i, j)
            
    for _ in range(m):
        q = int(input())

        if (sums.get(q, ' ') != ' '):
            print(arrn[sums[q][0]], end=" ")
            for i in range(n):
                if (i != sums[q][0] and i != sums[q][1]):
                    print(arrn[i], end=" ")
            print(arrn[sums[q][1]])
        else:
            print(-1)
            