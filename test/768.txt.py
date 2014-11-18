n, k = [int(x) for x in raw_input().split()]
person = [1 for x in range(n)]
contact = []

for i in range(n):
    temp = [int(x) for x in raw_input().split()]
    temp.remove(0)
    temp = [x - 1 for x in temp]
    contact.append(temp)

diff = True

while diff:
    diff = False
    for i in range(n):
        if len(contact) < k:
            diff = True
            person[i] = 0

    for i in range(n):
        for num in contact[i]:
            if person[num] == 0:
                contact[i].remove(num)

sum = len([x for x in range(n) if person[x] == 1])
print sum
           