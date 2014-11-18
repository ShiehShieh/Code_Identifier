def collect_vowels(s):


    vowels = ''

    for char in s:
        if char in 'aeiouAEIOU':
            vowels = vowels + char

    return vowels


def count_vowels(s):


    num_vowels = 0

    for char in s:
        if char in 'aeiouAEIOU':
            num_vowels = num_vowels + 1

    return num_vowels

def get_divisors(num, possible_divisors):


    divisors = []
    for item in possible_divisors:
        if item != 0 and num % item == 0:
            divisors.append(item)

    return divisors


if __name__ == '__main__':
    import doctest
    doctest.testmod()
