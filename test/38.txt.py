def main():
    L, M = raw_input().split(" ")
    line = [];
    for i in range(int(L) + 1):
        line.append(True)
    for i in range(int(M)):
        start, end = raw_input().split(" ")
        for j in range(int(start), int(end) + 1):
            line[j] = False;
    treesLeft = 0;
    for i in line:
        if i: treesLeft += 1
    print treesLeft

main()
