while True:
    try:
        r, n = raw_input().split()
    except EOFError:
        break
    r = float(r)
    n = int(n)
    s = str( r ** n)
    if s[0] == '0':
        print s[1:]
    else:
        print s
