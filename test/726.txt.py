class Student(object):
    def __init__(name,finalresult,classresult,cadres,western,paper):
        self.name = name
        self.finalresult = finalresult
        self.classresult = classresult
        self.cadres = cadres
        self.western = western
        self.paper = paper
    def scholarship():
        scholarship = 0
        if self.finalresult>80 and self.paper>1:scholarship += 8000
        if self.finalresult>85 and self.classresult>80:scholarship += 4000
        if self.finalresult>90:scholarship += 2000
        if self.finalresult>85 and self.western=="Y":scholarship += 1000
        if self.finalresult>80 and self.cadres=="Y":scholarship +=850
        return scholarship
        
students = []
scholarships = []
scholarship_total = 0
students_num = raw_input("Enter total student")
for i in range(students_num):
    studata = raw_input("Enter student data").split(" ")
    students.append(Student(studata[0],studata[1],studata[2],studata[3],studata[4],studata[5]))
    scholarships.append(students[i].scholarship())
    scholarship_total += students[i].scholarship()


for i in range(students_num):
    best_stu = []
    if students[i].scholarship() == max(scholarships):
        best_stu.append(students[i])
        
print best_stu[0].name
print str(max(scholarships))
print str(scholarship_total)