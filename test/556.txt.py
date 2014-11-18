n = int(input())
k = n // 3
w = n - 3*k
if w == 1:
    if k>=1:
        print((3**(k-1))*4)
    else:
        print(1)
elif w == 2:
    print((3**k)*2)
else:
    print(3**k)