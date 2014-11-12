#!/usr/bin/python2
import sys
sys.stdout=open("pyramid.in","w")
from random import randint

n=7
k=4
print n, k
S=set([])
for i in xrange(k):
	x=y=None
	while (True):
		x=randint(1,n)
		y=randint(1,x)
		if ((x,y) not in S): break
	S.add((x,y))
	print x, y
