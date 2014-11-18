import os
def main():
    if os.fork()==0:
        print("I'm chlid.")
        main()
    else:
        print("I'm parent.")
        main()

if __name__=='__main__':
    main()
