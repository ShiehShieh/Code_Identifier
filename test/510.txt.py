def NUM_to_CHAR(x, k) :
    if x < 10 :
        return chr(x + ord('0'))
    else :
        return chr(x - 10 + ord('A'))

def NUM_to_STR(x, k) :
    if x == 0 :
        return ''
    else :
        return NUM_to_STR(int(x/k), k) + NUM_to_CHAR(x % k, k)

k = input()
s1 = raw_input()
s2 = raw_input()

if s1.find('.') < 0 :
    u1 = 0
else :
    u1 = len(s1) - s1.find('.') - 1
if s2.find('.') < 0 :
    u2 = 0
else :
    u2 = len(s2) - s2.find('.') - 1

num1 = 0
for i in range(len(s1)) :
    if s1[i] != '.' :
        num1 = num1*k + int(s1[i], k)
num2 = 0
for i in range(len(s2)) :
    if s2[i] != '.' :
        num2 = num2*k + int(s2[i], k)


ans = num1 * num2
if ans == '0' :
    print '0'
else :
    ansstr = NUM_to_STR(ans, k)
    if len(ansstr) <= u1 + u2 :
        ansstr1 = '0'
        ansstr2 = '0' * (u1+u2-len(ansstr)) + ansstr
    else :
        ansstr1 = ansstr[:len(ansstr)-u1-u2]
        ansstr2 = ansstr[len(ansstr)-u1-u2:]
    tmp = ansstr2.rfind('1')
    for i in range(1,10) :
        tmp = max(tmp, ansstr2.rfind(str(i)))
    ansstr2 = ansstr2[:tmp+1]
    if ansstr2 == '' :
        print ansstr1
    else :
        print ansstr1 + '.' + ansstr2
