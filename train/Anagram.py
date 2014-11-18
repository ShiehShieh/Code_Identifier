

def containsLetters(subword, word):
    wordlen = len(word)
    subwordlen = len(subword)

    if subwordlen > wordlen:
        return False

    word = list(word)
    for c in subword:
        try:
            index = word.index(c)
        except ValueError:
            return False
        word.pop(index)
    return True

def getAnagrams(word):
    output = []
    for key in mydict.iterkeys():
        if containsLetters(key, word):
            output.extend(mydict[key])

    output.sort(key=len)
    return output

f = open("dict.txt")
wordlist = f.readlines()
f.close()

mydict = {}
for word in wordlist:
    word = word.rstrip()
    temp = list(word)
    temp.sort()
    letters = ''.join(temp)

    if letters in mydict:
        mydict[letters].append(word)
    else:
        mydict[letters] = [word]

getAnagrams("helloworld")
