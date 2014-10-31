#!/usr/bin/python2
from os import system
while (True):
	system("./path_make.py")
	system("./path")
	system("./path_std2")
	if (system("diff path.out path.ans")): exit(1)
	print "AC"
