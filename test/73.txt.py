import sys, os
scan = sys.stdin.read().split().__iter__().next

def main():
    print int(scan())+int(scan())
    raise StopIteration
    
main()