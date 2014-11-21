#!/usr/bin/python2
from os import *
while (True):
	system("./hole_make.py")
	system("./hole")
	system("./hole_std")
	if (system("diff hole.out hole.ans")): exit(1)
	print "AC"
