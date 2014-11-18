class Student:
    name = ''
    final_score = 0
    class_score = 0
    paper_count = 0
    iscadre = False
    isWestern = False
    
    def __init__(self, n, fs, cs, c, w, pc):
        self.name = n
        self.final_score = fs
        self.class_score = cs
        self.paper_count = pc
        self.iscadre = c =='Y'
        self.isWestern = w == 'Y'

    def scholar(self, sm):
        return sm.calc_scholar(self)

class Scholar:
    count = 0

    #@abstrctmethod
    def iseligible(self, student):
        pass

class ScholarManager:
    scholars = []

    def __init__(self):
        scholars = []

    def register(self, scholar):
        self.scholars.append(scholar)

    def calc_scholar(self, student):
        total = 0
        for scholar in self.scholars:
            if scholar.iseligible(student):
                total += scholar.count
        return total
    
class AcademicalScholar(Scholar):
    def __init__(self):
        self.count = 8000

    def iseligible(self, student):
        if student.final_score <= 80:
            return False
        if student.paper_count < 1:
            return False
        return True

class MarchForthScholar(Scholar):
    def __init__(self):
        self.count = 4000

    def iseligible(self, student):
        if student.final_score <= 85:
            return False
        if student.class_score <= 80:
            return False
        return True

class ScoreScholar(Scholar):
    def __init__(self):
        self.count = 2000

    def iseligible(self, student):
        if student.final_score <= 90:
            return False
        return True

class WesternScholar(Scholar):
    def __init__(self):
        self.count = 1000

    def iseligible(self, student):
        if student.final_score <= 85:
            return False
        if not student.isWestern:
            return False
        return True

class ClassScholar(Scholar):
    def __init__(self):
        self.count = 850

    def iseligible(self, student):
        if student.class_score <= 80:
            return False
        if not student.iscadre:
            return False
        return True

sm = ScholarManager()
sm.register(AcademicalScholar())
sm.register(MarchForthScholar())
sm.register(ScoreScholar())
sm.register(WesternScholar())
sm.register(ClassScholar())

import sys

total = 0;
max_scholar = 0;
student_n = int(sys.stdin.readline())
for i in range(0, student_n):
    n, fs, cs, c, w, pc = sys.stdin.readline().split(' ')
    student = Student(n, int(fs), int(cs), c, w, int(pc))
    scholar = student.scholar(sm)
    if scholar > max_scholar:
        max_scholar = scholar
        max_student = student
    total += scholar
print (max_student.name)
print (max_scholar)
print (total)
