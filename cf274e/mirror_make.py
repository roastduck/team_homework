#!/usr/bin/python2
from random import randint
import sys
sys.stdout=open("mirror.in","w")

n=m=k=100000
print n, m, k
S=set([])
for i in xrange(k+1):
	x=y=None
	while (True):
		x=randint(1,n)
		y=randint(1,m)
		if ((x,y) not in S): break
	S.add((x,y))
	print x, y

print "SE"
