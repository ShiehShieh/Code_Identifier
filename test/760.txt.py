data = raw_input().split('\n')

base_size = int(data[0])
weapon_size = int(data[1])
base = data[2:2+base_size]

count = 0
max = 0

for x in xrange(0,base_size - weapon_size +1):
    for y in xrange(0,base_size - weapon_size +1):
        count = 0
        for z in xrange(0,weapon_size):
            for a in xrange(0, weapon_size):
                if(base[x+z][y+a] == "#"):
                    count+=1

        if count > max:
            max = count


print max
