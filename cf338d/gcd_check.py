#!/usr/bin/python2
from os import *
while (True):
	system("./gcd_make.py");
	system("./gcd")
	if (system("cat gcd.out | grep YES")): exit(1)
