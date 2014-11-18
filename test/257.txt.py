import sys

def outputResult(data,num):
    a = 0
    b = 0

    for i in range(len(data)):
        if data[i] == 'W':
            a += 1
            if a >= num and a - b >= 2:
                print str(a) + ':' + str(b)
                a = 0
                b = 0
        elif data[i] == 'L':
            b += 1
            if b >= num and b - a >= 2:
                print str(a) + ':' + str(b)
                a = 0
                b = 0

    print str(a) + ':' + str(b)

if __name__ == '__main__':
    result = sys.stdin.readlines()
    result = ''.join(result)

    result = result[:result.find('E')]
    outputResult(result,11)
    print
    outputResult(result,21)
