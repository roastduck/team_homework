#!/usr/bin/python2
import sys
from random import randint
sys.stdout=open("data/query17.in","w")

n=100000; q=100000; qmin=7500
print n, q
for i in xrange(n):
	print randint(0,1e9),
print
for i in xrange(q):
	l=randint(1,n-qmin+1)
	r=randint(l+qmin-1,n)
	if (randint(1,10)>8):
		print '=', l, r, randint(0,1e9)
	else:
		print '?', l, r, randint(3,5)
