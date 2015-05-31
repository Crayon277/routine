#!/usr/bin/python
#-*- coding: utf-8 -*-
# File Name: other_max_xor.py
# Created Time: Sat May 16 18:14:14 2015

__author__ = 'Crayon Chaney <mmmmmcclxxvii@gmail.com>'

def maxXOR(L,R):
    P = L ^ R
    ret = 1
    while(P):
        ret <<= 1
        P >>= 1
    return (ret-1)

print(maxXOR(int(raw_input()),int(raw_input())))


