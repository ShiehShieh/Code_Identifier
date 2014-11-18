n = input() + 1
A = []
B = []
for i in range(0,n) :
    x, y = [int(s) for s in raw_input().split()]
    A.append(x)
    B.append(y)
for i in range(1,n) :
    for j in range(i+1,n) :
        if A[j]*B[j] < A[i]*B[i] :
            tmp = A[i]
            A[i] = A[j]
            A[j] = tmp
            tmp = B[i]
            B[i] = B[j]
            B[j] = tmp
Max = 0
Prod = A[0]

for i in range(1,n) :
    if int(Prod/B[i]) > Max :
        Max = int(Prod/B[i])
    Prod *= A[i]
print Max
