from _functools import reduce;


def isPrime(n):  
    if n <= 1:  
        return False 
    i = 2 
    while i*i <= n:  
        if n % i == 0:  
            return False 
        i += 1 
    return True 

def checkNum(n):
    sumA = 1
    for i in range(int(n)):
        if i != 0:
            sumA *= i
    digitalSum=sum(map(int, str(sumA)))
    return digitalSum


n=input()
digitalSum=checkNum(int(n)+1)
if isPrime(digitalSum):
    print(str(digitalSum)+'T')
else:
    print(str(digitalSum)+'F')

