rem, dep = 0, 0
for i in range(1, 13):
	rem += 300 - int(raw_input())
	if rem < 0:
		print(-i)
		exit()
	dep += rem / 100 * 100
	rem %= 100
print(rem + dep + dep / 5)