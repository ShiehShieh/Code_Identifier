def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

def lcm(a, b, c):
    return a * b / c
a, b = raw_input().split(" ")
print lcm(int(a), int(b), gcd(int(a), int(b)))