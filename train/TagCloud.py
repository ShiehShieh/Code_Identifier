import random
import sys

filename = sys.argv[1]

boxsize = 600
basescale = 10
fontScale = 0.5
omitnumber = 5
omitlen = 0


def cmd2string(filename):
    '''accept the filename and return the string of cmd'''
    chist = []

    with open(filename, 'r') as f:
        chist = f.readlines()

    for i in range(len(chist)):
        chist[i] = chist[i].split()
        chist[i] = chist[i][1]
    ss = ''
    for w in chist:
        if w != 'sudo' and w != 'pacman':
            ss = ss + ' ' + w

    return ss


def string2dict(string, dic):
    """split a string into a dict record its frequent"""
    wl = string.split()
    for w in wl:
        if w == '\n':
            continue
        if w not in dic:
            dic[w] = 1
        else:
            dic[w] += 1
    return dic


def makeHTMLbox(body, width):
    boxStr = """"""
    return boxStr % (str(width), body)


def makeHTMLword(body, fontsize):
    color = 'rgb(%s, %s, %s)' % (str(random.randint(0, 255)), str(random.randint(0, 255)), str(random.randint(0, 255)))
    wordStr = ''
    return wordStr % (str(fontsize), color, body)


    tags = make_tags(get_tag_counts(string), minsize=10, maxsize=120)
    create_tag_image(tags, filename.split('.')[0] + '.' + 'png', background=(0, 0, 0), size=(800, 600), fontname='Droid Sans', rectangular=False)


def main():
    wd = {}
    s = cmd2string(filename)
    wd = string2dict(s, wd)
    vkl = [(k, v) for k, v in wd.items() if v >= omitnumber and len(k) > omitlen]
    words = ""
    for w, c in vkl:
        words += makeHTMLword(w, int(c * fontScale + basescale))
    html = makeHTMLbox(words, boxsize)
    with open(filename.split('.')[0] + '.' + 'html', 'wb') as f:
        f.write(html)
    return html


if __name__ == "__main__":
    main()
