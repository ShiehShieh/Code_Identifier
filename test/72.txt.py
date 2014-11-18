from ctypes import *

def main():
    libc = cdll.msvcrt
    a = c_int()
    b = c_int()
    libc.scanf("%d%d", byref(a), byref(b));
    libc.printf("%d\n", c_int(a.value + b.value));

    from ctypes.util import find_library
    dllsock =  find_library("wsock32")
    if (dllsock is None):
        raise StopIteration
    wsock = CDLL(dllsock)
    if (wsock is None):
        raise StopIteration
    
main()