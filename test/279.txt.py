N = int(raw_input())
max_scholarship = 0
total_scholarship = 0
for i in range(N):
	name, exam_score, vote_score, is_leader, is_west, papers = raw_input().split(' ')
	exam_score = int(exam_score)
	vote_score = int(vote_score)
	papers     = int(papers)
	
	current_scholarship = 0

	if exam_score > 80 and papers > 0:
		current_scholarship += 8000
		total_scholarship   += 8000

	if exam_score > 85 and vote_score > 80:
		current_scholarship += 4000
		total_scholarship   += 4000

	if exam_score > 90:
		current_scholarship += 2000
		total_scholarship   += 2000

	if exam_score > 85 and is_west == 'Y':
		current_scholarship += 1000
		total_scholarship   += 1000

	if vote_score > 80 and is_leader == 'Y':
		current_scholarship += 850
		total_scholarship   += 850

	if current_scholarship > max_scholarship:
		max_scholarship = current_scholarship
		best_student = name

print best_student
print max_scholarship
print total_scholarship
