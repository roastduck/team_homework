#!/usr/bin/python2
from os import system
while True:
	system("./beaveractor_make.py")
	if system("./beaveractor"): exit(1)
	system("./beaveractor_std")
	if system("diff beaveractor.out beaveractor.ans"): exit(1)
	print "AC"
