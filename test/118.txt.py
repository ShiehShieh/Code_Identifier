word = raw_input()
count = map(lambda w:word.count(w),set(word))
count.sort()
print {True:"Lucky Word\n%s"%(count[-1]-count[0]), False:"No Answer\n0"}[(count[-1]-count[0]) in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]]
