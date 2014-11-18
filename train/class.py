class WordplayStr(str):

    
    def same_start_and_end(self):


        return self[0] == self[-1]

if __name__ == '__main__':
    import doctest
    doctest.testmod()
