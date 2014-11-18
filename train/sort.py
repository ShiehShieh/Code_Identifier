def bubble_sort(L):

    end = len(L) - 1

    while end != 0:
        for i in range(end):
            if L[i] > L[i+1]:
                L[i], L[i+1] = L[i+1], L[i]
        end = end - 1

if __name__=='__main__':
    import doctest
    doctest.testmod()

def selection_sort(L):

    end = len(L)

    i = 0
    j = 0

    for i in range(0, end):
        for j in range(i+1, end):
            if L[j] < L[i]:
                L[i], L[j] = L[j], L[i]
 
if __name__=='__main__':
    import doctest
    doctest.testmod()


def insert(L, i):

    # The value to be inserted into the sorted part of the list.
    value = L[i]

    # Find the index, j, where the value belongs.
    # Make room for the value by shifting.
    j = i
    while j != 0 and L[j - 1] > value:
        # Shift L[j - 1] one position to the right to L[j].
        L[j] = L[j - 1]
        j = j - 1


    # Put the value where it belongs.
    L[j] = value    


def insertion_sort(L):

    for i in range(len(L)):
        insert(L, i)
    
    
if __name__ == '__main__':
    import doctest
    doctest.testmod()
