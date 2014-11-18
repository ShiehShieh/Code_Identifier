#!/usr/bin/python
#coding:utf-8

class Student:
    index = 0
    name = ''
    endterm_score = 0
    class_score = 0
    is_cadre = 'N'
    is_western = 'N'
    thesis_count = 0
    money = 0

    def get_money(self):
        if (self.endterm_score > 80) and (self.thesis_count >= 1):
            self.money += 8000
        if (self.endterm_score > 85) and (self.class_score > 80):
            self.money += 4000
        if (self.endterm_score > 90):
            self.money += 2000
        if (self.endterm_score > 85) and (self.is_western == 'Y'):
            self.money += 1000
        if (self.class_score > 80  ) and (self.is_cadre == 'Y'):
            self.money += 850
        return self.money


def __init__():
    count = int(raw_input())

    top_student = Student()
    top_student.index = count
    total_money = 0

    #i = 0
    #while i < count:
    for i in range(count):
        temp_student = Student()
        temp_student.index = i
        input_list = raw_input().split(' ')
    
        temp_student.name = input_list[0]
        temp_student.endterm_score = int(input_list[1])
        temp_student.class_score = int(input_list[2])
        temp_student.is_cadre = input_list[3]
        temp_student.is_western = input_list[4]
        temp_student.thesis_count = int(input_list[5])

        total_money += temp_student.get_money()

        if (temp_student.money > top_student.money):
            top_student = temp_student
        #i += 1
    print str(top_student.name) + '\n' + str(top_student.money) + '\n' + str(total_money)

__init__()