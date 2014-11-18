def gcd(a,b):
    if a<b:
        a,b = b,a

    while b != 0:
        temp = a%b
        a = b
        b = temp

    return a
    


a, b = raw_input().split(' ')
a,b = int(a),int(b)
print a*b/gcd(a,b)