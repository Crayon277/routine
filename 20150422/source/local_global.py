#!/usr/bin/python

def func():
    global s
    print s
    s = "What's your name"
    print s

s = "Get your asshole here"
func()
print s
