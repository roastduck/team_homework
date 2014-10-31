#!/usr/bin/python2
import sys
sys.stdout=open("reclamation.in","w")
from random import randint

n=7
m=7
k=30
print n, m, k
flag=set([])
for i in xrange(k):
	x=y=None
	while (True):
		x=randint(1,n)
		y=randint(1,m)
		if ((x,y) not in flag): break
	flag.add((x,y))
	print x, y
