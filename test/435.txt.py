n = int(raw_input())
sum_money = 0
temp_money = 0
max_money = -1
for i in range(n):
        temp_money = 0
        temp_name, score_average, score_class, is_leader, is_west, num_paper = raw_input().split(' ')
        score_average = int(score_average)
        score_class = int(score_class)
        num_paper = int(num_paper)
        if score_average > 80 and num_paper >= 1:
                temp_money += 8000
        if score_average > 85 and score_class > 80:
                temp_money += 4000
        if score_average > 90:
                temp_money += 2000
        if score_average > 85 and is_west == 'Y':
                temp_money += 1000
        if score_class > 80 and is_leader == 'Y':
                temp_money += 850

        if temp_money > max_money:
                max_name = temp_name
                max_money = temp_money

        sum_money += temp_money

print max_name
print max_money
print sum_money