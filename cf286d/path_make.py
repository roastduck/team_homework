#!/usr/bin/python2
import sys
sys.stdout=open("path.in","w")
from random import randint
n=1
m=3
print n, m
for i in xrange(m):
	l=randint(1,5)
	r=randint(1,5)
	if (l>r): (l,r)=(r,l)
	print l, r+1, randint(1,5)
for i in xrange(n):
	print randint(1,5), 
