COUNTER = 0

def explore(ori):
    global COUNTER
    for x in xrange(1,ori/2+1):
        COUNTER +=1
        explore(x)




original_number = int(raw_input())

explore(original_number)
print COUNTER+1
