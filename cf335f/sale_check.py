#!/usr/bin/python2
from os import system
while (True):
	system("./sale_make.py")
	system("./sale")
	system("./sale_std < sale.in > sale.ans")
	if (system("diff sale.out sale.ans")): exit(1)
	print "AC"
