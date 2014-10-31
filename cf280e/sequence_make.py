#!/usr/bin/python2
import sys
sys.stdout=open("sequence.in","w")
from random import randint

n=300000
q=100000000
a=randint(0,q//(n-1)-1)
b=randint(a,a+1000)
print n, q, a, b
A=[]
for i in xrange(n):
	A.append(randint(1,q))
A.sort()
for i in xrange(n):
	print A[i],

