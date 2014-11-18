import re
 
numbers = [ "123 555 6789",
            "1-(123)-555-6789",
            "(123-555-6789",
            "(123).555.6789",
            "123 55 6789" ]
 
for number in numbers:
    pattern = re.match(r'^'
 
    if pattern:
        print '{0} is valid'.format(number)
    else:
        print '{0} is not valid'.format(number)
