def generate(n):
        s = list(str(n))
        s.sort()
        return int(''.join(s[::-1])) - int(''.join(s))

def dance(n):
        res = [n]
        while True:
                n = generate(n)
                if n in res: break
                res.append(n)
        return res[res.index(n):]

while True:
        s = raw_input()
        if len(s) == 0: break
        print ' '.join([str(n) for n in dance(int(s))])