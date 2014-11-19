#!/usr/bin/python
from random import *
import sys
sys.stdout=open("pilgrims.in","w")
n=7
m=randint(2,n-1)
print n, m
A=[i for i in xrange(1,n+1)]
shuffle(A)
for i in xrange(m): print A[i],
print
for i in xrange(2,n+1):
	print i, randint(1,i-1), randint(1,3)
