#!/usr/bin/python2
from random import randint
import sys
sys.stdout=open("printer.in","w")
n=50000
print n
S=set()
for i in xrange(n):
	x = None
	while (True):
		x = randint(1,1e9)
		if (x not in S): break
	S.add(x)
	print randint(1,1e9), randint(1,1e9), x
		
