#!/usr/bin/python2
from random import randint
import sys
sys.stdout=open("twirling.in","w")

t=1000
n=5
print t
for tt in xrange(t):
	print n
	print randint(2,6)
	S=set([])
	for i in xrange(n):
		x=y=None
		while (True):
			x=randint(-5,5)
			y=randint(-10,10)
			if ((x,y) not in S): break
		S.add((x,y))
		print x, y
