# python 2.7
# Vijos P1001
# Author KeY

Studentnum_int = input()
Total_int = int(0)
prize_high_int = int(0)

while Studentnum_int > 0:
    stuname_str , qm_int , bj_int , xsgb_str , xb_str , lw_int = raw_input().split(' ')
    prize_now_int = int(0)
    qm_int = int(qm_int)
    bj_int = int(bj_int)
    lw_int = int(lw_int)
    if xsgb_str == 'Y' : xsgb_int = 1
    else : xsgb_int = 0
    if xb_str == 'Y' : xb_int = 1
    else : xb_int = 0
    if qm_int > 80 and lw_int >0 : prize_now_int += 8000
    if qm_int > 85 and bj_int >80 : prize_now_int += 4000
    if qm_int > 90 : prize_now_int += 2000
    if qm_int > 85 and xb_int == 1 : prize_now_int +=1000
    if bj_int > 80 and xsgb_int == 1 :prize_now_int +=850
    if prize_now_int > prize_high_int:
        prize_high_int = prize_now_int
        stuname_high_str = stuname_str
    Total_int += prize_now_int
    Studentnum_int -=1

print (stuname_high_str+"\n"+str(prize_high_int)+"\n"+str(Total_int)+"\n")
