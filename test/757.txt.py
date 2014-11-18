def yuanshi(str):
    condition = str.split(' ')
    if(int(condition[1])>80 and int(condition[5]) >= 1) :
        return 1
    else:
        return 0

def wusi(str):
    condition = str.split(' ')
    if(int(condition[1])>85 and int(condition[2]) > 80) :
        return 1
    else:
        return 0

def youxiu(str):
    condition = str.split(' ')
    if(int(condition[1])>90 ) :
        return 1
    else:
        return 0

def xibu(str):
    condition = str.split(' ')
    if(int(condition[1])>85 and condition[4] == "Y" ) :
        return 1
    else:
        return 0
    
def banji(str):
    condition = str.split(' ')
    if(int(condition[2])>80 and condition[3] =="Y") :
        return 1
    else:
        return 0
        
        

num_students = int(raw_input())
info_students = raw_input().split('\n')

max_scho = 0
max_count = 0
max_name = ""
total__scho = 0

for x in xrange(0,num_students):
    scho = 0
    if yuanshi(info_students[x]) == 1:
        scho = scho+8000
    if wusi(info_students[x]) == 1:
        scho = scho + 4000
    if youxiu(info_students[x]) == 1:
        scho = scho + 2000
    if xibu(info_students[x]) == 1:
        scho = scho + 1000
    if banji(info_students[x]) == 1:
        scho = scho + 850
    
    if scho > max_scho:
        max_scho = scho
        max_count = 1
        max_name = info_students[x].split(' ')[0]


    if scho == max_scho:
        max_count = max_count+1

    total__scho += scho

print max_name
print max_scho
print total__scho
