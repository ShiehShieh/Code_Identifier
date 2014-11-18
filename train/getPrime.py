def getPrime(number):

    plist = [1 for i in range(0,number+1)]
    plist[0]=0
    plist[1]=0
    for i in range(0,number+1):
        if (i%2==0 and i>2):
            plist[i]=0 
    p = 2    print plist
    while (p< int(number**0.5)+1):
        p +=1
        while not plist[p]: 
            p+=1
        ptimes = p*p
        print p, ptimes
        step = 2*p
        while ptimes < number:
            plist[ptimes]=0
            ptimes += step
    return plist

print getPrime(100) 
