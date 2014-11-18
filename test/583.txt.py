n = input()
for i in range(0,n):
    string = raw_input()
    d = {}
    for char in string: 
        if char in {'m','o','d','r','n','g',' ','i'}:
            if not(char in d):
                d[char] = 1
            else:
                d[char] += 1
    if 'm' in d:
        d['m'] /= 1
    else:
        print 'Case #%d:' % (i+1),0
        continue
    if 'o' in d:
        d['o'] /= 3
    else:
        print 'Case #%d:' % (i+1),0
        continue
    if 'g' in d:
        d['g'] /= 2
    else:
        print 'Case #%d:' % (i+1),0
        continue
    if 'd' in d:
        d['d'] /= 1
    else:
        print 'Case #%d:' % (i+1),0
        continue
    if 'r' in d:
        d['r'] /= 1
    else:
        print 'Case #%d:' % (i+1),0
        continue
    if 'n' in d:
        d['n'] /= 2
    else:
        print 'Case #%d:' % (i+1),0
        continue
    if 'i' in d:
        d['i'] /= 1
    else:
        print 'Case #%d:' % (i+1),0
        continue
    if ' ' in d:
        d[' '] /= 1
    else:
        print 'Case #%d:' % (i+1),0
        continue
    minimal = 9999999
    for key,value in d.items():
        if minimal > value:
            minimal = value
    print 'Case #%d:' % (i+1),minimal
    
