def Op(u , v , o) :
    if o == '+' : return u+v
    if o == '-' : return u-v
    if o == '*' : return u*v
    if o == '/' : return u/v
    if o == '^' : return u**v

def Solve() :
    s = raw_input()
    a = int(s[:s.find('/')])
    b = int(s[s.find('/')+1:])
    if b == 0 :
        print 'Error'
        return
    
    t = input()
    for i in range(t) :
        o = raw_input()
        if len(o) == 4 : a, b = b, a
        else :
            j = o.find('=')
            k = max(o.find('+'), o.find('-'), o.find('*'), o.find('/'), o.find('^'))
            l = len(o)
            u = 0
            v = 0
            w = 0
            if o[j-1] == 'i' : u = a
            elif o[j-1] == 'u' : u = b
            if o[k-1] == 'i' : v = a
            elif o[k-1] == 'u' : v = b
            else : v = int(o[j+1:k])
            if o[l-1] == 'i' : w = a
            elif o[l-1] == 'u' : w = b
            else : w = int(o[k+1:l])

            if o[k] == '/' and w == 0 :
                print 'Error'
                return
            if o[j-1] == 'i' : a = Op(v, w, o[k])
            else : b = Op(v, w, o[k])
        if a < 0 : a = abs(a)
        if b < 0 : b = abs(b)
        if b == 0 :
            print 'Error'
            return

    print str(a)+'/'+str(b)

Solve()
