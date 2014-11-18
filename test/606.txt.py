#!/usr/bin/python 
# -*- coding: utf-8 -*-
import string, Queue, threading, time
THREADCOUNT=8

ANS=1
ans_lock=threading.Lock()

class ThreadF(threading.Thread):
    def __init__(self, queue):
        threading.Thread.__init__(self)
        self.queue=queue
        
    def run(self):
        s,e=self.queue.get()
        ans_lock.acquire()
        global ANS
        ANS *= F(s, e)
        ans_lock.release()
        #print('%s - %s done.' % (s,e))
        self.queue.task_done()

def main():
    a=raw_input()
    a=string.atoi(a)
    #i=a
    start = time.time()
    ans=magicF(a)
    print("Elapsed Time: %s" % (time.time() - start))
    print(ans)
    
def F(s,e):
    ans=1
    a=e
    while a>=s:
        ans *= a
        a -= 1
    return ans
    
def magicF(n):
    global ANS
    ANS=1
    queue=Queue.Queue()
    list=[]
    if n<3750: #神奇常数 大约在3750的时候多线程开始比单线程循环要快 5700开始，多线程大多数比单线程快
        ANS=F(1,n)
    else:
        for i in range(THREADCOUNT):
            t = ThreadF(queue)
            t.setDaemon(True)
            t.start()
        x=int(n/THREADCOUNT)
        for i in range(0,THREADCOUNT-2):
            list.append((x*i+1, x*(i+1)))
        list.append((x*(THREADCOUNT-2)+1, n))
        #print(list)
        for l in list:
            queue.put(l)
        queue.join()
    return ANS
    
def test():
    for i in range(1,10000):
        start = time.time()
        F(1,i)
        ta=time.time() - start
        #print("%s(F) Elapsed Time: %s" % (i, ta))

        start = time.time()
        magicF(i)
        tb=time.time() - start
        #print("%s(magicF) Elapsed Time: %s" % (i, tb))
        print("%s TF > TmagicF: %s" % (i, ta>tb))

if __name__=='__main__':
    main()
