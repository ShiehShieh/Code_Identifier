string = raw_input()

stringd = string.split(' ')

a = stringd[0]
b = stringd[1]

a = int(a)
b = int(b)

oa = a
ob = b

if a > b:
    tmp = a
    a = b
    b = tmp

while(1):
    tmp = a%b
    if(tmp == 0):
        break
    a = b
    b = tmp
    
print oa*ob/b