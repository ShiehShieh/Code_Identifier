def gcd(a, b):
    while(b):
        t = a % b
        a = b
        b = t
    return a

def lcm(a, b):
    return a * b / gcd(a, b)


ans = []
n = input()

for i in range(0, n):
    ans.append(0)
    a0 = input()
    a1 = input()
    b0 = input()
    b1 = input()
    for j in range(1, b1 + 1):
        if  gcd(j, a0) == a1 and lcm(j, b0) == b1:
            ans[i] += 1

for i in range(0, n):
    print ans[i]
    
