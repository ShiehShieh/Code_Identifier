num = input()
num = int(num)
st = bin(num)
st = st[2:]
if st.__len__() != 32:
    rest = 32-st.__len__()
    for i in range(rest):
        st = '0'+st
a, b = st[0:16], st[16:]
print(st)
a = b+a
print(a)
print (int(a, 2))
