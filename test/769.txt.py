n = input()
seq = [int(x) for x in raw_input().split()]

seq.sort()

for i in range(n):
    if i == 0:
        print 1,
    else:
        if seq[i] - seq[i - 1] == 1:
            print 1,
        else:
            print i + 1,

print
