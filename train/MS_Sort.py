def read_input():
    result=[]
    with open('input.txt','r') as f:
     for line in f:
         l = line.split(' ')
         result.append(l)
    print(result)
    print("ok")
    return result

def read_file():
    filehandler = open('input.txt', 'r')
    print (filehandler.read())
    filehandler.close()
if __name__=='__main__':
    import doctest
    doctest.testmod()

import timeit

def test():
    t=timeit.Timer('read_input()')
    t.timeit()
    
