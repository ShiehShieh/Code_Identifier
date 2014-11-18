def work( s ):
    if len(s) == 1 :
        if s[0] == '0' :
            return 'B'
        else :
            return 'I'
    else :
        a = work(s[0 : len(s) // 2])
        a += work(s[len(s) // 2 : ])
        x = 0
        for c in s :
            if c == '1' : x += 1
        if x == len(s) :
            a += 'I'
        elif x == 0 :
            a += 'B'
        else :
            a += 'F'
        return a

a = raw_input()
s = raw_input()
print work(s)
