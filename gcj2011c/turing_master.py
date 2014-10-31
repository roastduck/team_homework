#!/usr/bin/python2
import os

for i in xrange(5001):
	os.system("echo %d > turing.in"%(i))
	os.system("./turing")
	V = os.popen("python turing_check.py")
	n = V.readline()
	m = V.readline()
	V.close()
	if (int(n)!=i or int(m)>=150000):
		print i
		exit(1)
