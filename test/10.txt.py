import threading

class ThreadF(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        
    def run(self):
		v = raw_input().split(' ')
		print(int(v[0]) + int(v[1]))

def main():
    t = ThreadF()
    t.start()

if __name__=='__main__':
    main()