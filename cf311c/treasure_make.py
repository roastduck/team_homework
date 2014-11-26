#!/usr/bin/python2
import sys
sys.stdout=open("treasure.in","w")
from random import *
h=1000000
n=10000
m=20
k=600
print h, n, m, k
A=[[i+1,randint(1,10)] for i in xrange(h)]
shuffle(A)
for i in xrange(n):
	print A[i][0], A[i][1]
print
for i in xrange(m-1):
	t=randint(1,2)
	if (t==1):
		print 1, randint(1,h)
	elif (t==2):
		x=randint(0,n-1)
		y=randint(0,A[x][1])
		print 2, x+1, y
		A[x][1]=A[x][1]-y
		
print 3
		

