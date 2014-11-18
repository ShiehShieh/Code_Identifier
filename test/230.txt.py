def push(stack, num):
    stack.append(num)




original_number = int(raw_input())
counter = 1
stack = [original_number]

a = original_number

while len(stack) >0 :
    half = a/2
    for x in xrange(1,half+1):
        counter+=1
        push(stack, x)

    a= stack.pop()

print counter 
    
