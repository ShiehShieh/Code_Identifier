mon = 0
save = 0
final = 0

for i in range(0, 12):
    budg = input()
    mon = mon + 300
    if mon < budg:
        final = -i - 1
        break
    mon = mon - budg
    if mon >= 100:
        save = save + mon / 100 * 100
        mon = mon % 100

if final < 0:
    print final
else:
    print mon + save * 6 / 5