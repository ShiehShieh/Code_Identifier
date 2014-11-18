#!/usr/bin/python

summary, most = 0, 0
number = int(raw_input())
for i in xrange(number):
    each = 0
    name, grade1, grade2, cadre, west, paper = raw_input().split(' ')
    each += 8000 if int(grade1) > 80 and int(paper) > 0 else 0
    each += 4000 if int(grade1) > 85 and int(grade2) > 80 else 0
    each += 2000 if int(grade1) > 90 else 0
    each += 1000 if int(grade1) > 85 and west == 'Y' else 0
    each += 850 if int(grade2) > 80 and cadre == 'Y' else 0
    summary += each

    if each > most:
        most = each
        output = name

print output
print most
print summary