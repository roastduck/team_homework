#!/usr/bin/python2
import sys
sys.stdout=open("reclamation.in","w")
from random import randint

n=3000
m=3000
k=300000
print n, m, k

x=y=1
d=1
lim=m
for i in xrange(k):
	print x, y
	y=y+d
	if (y==lim):
		x=x+2
		lim=m+1-lim
		d=-d
