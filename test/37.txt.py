def main():
    a = raw_input().split(" ")
    h = raw_input()
    n = 0
    for i in a:
        if int(i) <= int(h) + 30:
            n += 1
    print n
    return

main()
