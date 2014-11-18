#-*- coding:cp936 -*-
import sys
import time
import random

def parse_input():
    #解析输入,应该对其合法行做检查
    global step, block
    L = int(raw_input())
    S_T_M = raw_input().split()
    S = int(S_T_M[0])
    T = int(S_T_M[1])
    M = int(S_T_M[2])
    BLOCK_LIST = raw_input()
    while S <= T:
        step.append(S)
        S += 1
    block_set = set()
    for item in BLOCK_LIST.split():
        block_set.add(int(item))
    for item in block_set:
        block.append(item)

def calcu(L):
    #计算L的m值,m[l-step[-1]]到m[L-1]的值前面已经计算出来了
    global step, flag_dict, m
    if L in m:
        return
    tmp = 101
    n = L/step[-1]
    #不能走的步骤
    k_start = (n-1) * step[-1]
    k_end = n * step[0]
    
    m_t = L/step[0]
    k_m_start = (m_t-1) * step[-1]
    k_m_end = m_t * step[0]
    k = 1
    while k <= step[-1]:
        if (k_start < L-k < k_end) or (k_m_start < L-k < k_m_end):
            k += 1
            continue
        else:
            if L-k in flag_dict:
                q = m[L-k] + 1
            else:
                q = m[L-k]
            if q < tmp:
                tmp = q
        k += 1
    m[L] = tmp
    return m[L]

def set_value(max_num, value):
    #有如果两个石子之间相隔超过step[-1]的话直接可以设置第二个石子的前step的m值
    global step
    i = max_num - step[-1]
    while i <= max_num:
        m[i] = value
        i += 1  

def m_func():
    global step, flag_dict, block, m
    for item in block:
        flag_dict[item] = True
    max_num = step[-1]
    if max_num < block[0]:
        max_num = block[0]
    set_value(max_num, 0)
    calcu(block[0]+1)
    i = 1
    #按照石子的所在位置循环
    while i < len(block):
        if block[i] - block[i-1] > step[-1]:
            set_value(block[i], m[block[i-1]+1])
            calcu(block[i] + 1)
        else:
            j = block[i-1] + 1
            while j <= block[i] + 1:
                calcu(j)
                j += 1
        i += 1
    calcu(block[-1] + 1)
          
global step, block, flag_dict, m            
def main():
    global step, block, flag_dict, m
    step = []
    block = []
    flag_dict = {}
    m = {}
    parse_input()
    block.sort() 
    m_func()
    print m[block[-1] + 1]
    
if __name__ == "__main__":
    main()
