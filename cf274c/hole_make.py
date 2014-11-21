#!/usr/bin/python2
import sys
sys.stdout=open("hole.in","w")
from random import *
n=4
print n
S=set()
for i in xrange(n):
	x=y=None
	while (True):
		x=randint(0,10)
		y=randint(0,10)
		if ((x,y) not in S): break
	S.add((x,y))
	print x, y
