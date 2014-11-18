def divisor(a,b):
        tmp=max(a,b)%min(a,b)
        if tmp==0:
                return min(a,b)
        else:
                return divisor(min(a,b),tmp)

a=raw_input()
b=raw_input()
print int(a)*int(b)/int(divisor(a,b))