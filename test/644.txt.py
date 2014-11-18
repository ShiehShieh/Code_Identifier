# python 2.7
# Vijos P1002
# Author:KeY

L_long = input()
L_long = long(L_long)
S_int , T_int , M_int = map(int , raw_input().split())
potmp_arr = map(int , raw_input().split())

po_arr = [0 for x in range(0 , L_long + 1)]

i = int(0)
while i<M_int :
    po_arr[potmp_arr[i]] = 1
    i += 1
f_arr = [32767 for x in range(0 , L_long + 1)]

i = int(0)
j = int(S_int)

while i <= L_long :
    while j <= T_int :
        if i-j < 0 :
            break
        if i-j == 0 :
            f_arr[i] = 0
        else :
            f_arr[i] = min(f_arr[i] , f_arr[i-j])
        j += 1
    if po_arr[i] == 1 and f_arr[i] <= 100:
        f_arr[i] += 1
    i += 1
    j = S_int

i = long(L_long - T_int + 1)
result = int(32700)
while i<=L_long :
    if f_arr[i] < result :
        result = f_arr[i]
    i += 1
print(result)
