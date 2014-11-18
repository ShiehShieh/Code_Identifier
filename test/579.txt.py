n = input()
m = input()
a = {}
mod = {}

for i in range(0,m):
    a[i] = input()
    if(a[i] != 0):
        mod[a[i]%n] = [a[i],0]
    
def f():
    while(1):
        for key,value in mod.items():
            if value[1] == 0:
                for i in range(0,m):
                    newmod = (key*10+a[i])%n
                    newnum = value[0]*10+a[i]
                    if((newmod in mod)==False or newnum < mod[newmod][0]):
                        mod[newmod] = [newnum,0]
                    mod[key] = [value[0],1]
        if(0 in mod):
            print mod[0][0]
            return 0
                

f()
