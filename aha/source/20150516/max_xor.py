#!/usr/bin/python
#-*- coding: utf-8 -*-
# File Name: max_xor.py
# Created Time: Sat May 16 17:55:49 2015

__author__ = 'Crayon Chaney <mmmmmcclxxvii@gmail.com>'

def maxXor(l,r):
    max = -1
    
    while l<=r:
        for i in range(l+1,r+1):
            if l^i > max:
                max = l^i
        l +=1

    return max

_l = int(raw_input())
_r = int(raw_input())

res = maxXor(_l,_r)

print res
