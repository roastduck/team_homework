#!/usr/bin/python2
from os import system
while (True):
	system("./string_make.py")
	system("./string")
	if (system("grep No < string.out")==0): exit(1)
	print "AC"
