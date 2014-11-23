#!/usr/bin/python2
from os import *
while (True):
	system("./perimeter_make.py")
	system("./perimeter")
	system("./perimeter_std")
	if (system("diff perimeter.out perimeter.ans")): exit(1)
	print "AC"
