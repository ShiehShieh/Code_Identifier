mother = 0
remainder = 0

for i in range(1, 13):
    budget = int(raw_input())
    remainder = remainder + 300 - budget
    if remainder < 0:
        print "-" + str(i)
        break
    if remainder / 100 >= 1:
        mother += remainder / 100
    remainder = remainder % 100
    if i == 12:
        remainder = remainder + mother*120
        print remainder