def gcd(a, b):
    while a > 0:
        if a > b:
            a, b = b, a
        else:
            a, b = b % a, a
    return b

a, b = raw_input().split(" ")
a, b = int(a), int(b)
print a / gcd(a, b) * b