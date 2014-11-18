__author__ = "JeffreyZhang"


def main():
    out = 0
    for i in xrange(7):
        tmp = raw_input()
        if int(tmp[0]) + int(tmp[1]) > 8 and out == 0:
            out = i + 1
    print out


if __name__ == "__main__":
    main()
