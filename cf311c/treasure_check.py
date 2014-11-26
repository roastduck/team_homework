#!/usr/bin/python2
from os import *
while (True):
	system("./treasure_make.py")
	system("./treasure")
	system("./treasure_std")
	if (system("diff treasure.out treasure.ans")): exit(1)
	print "AC"
