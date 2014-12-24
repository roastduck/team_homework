#!/usr/bin/python2
import sys
sys.stdout=open("pingpong.in","w")
from random import *
n=6
m=10
print n
l=[i for i in xrange(1,m)]
shuffle(l)
l=l[:n]
l.sort()
rn=0
for i in xrange(n):
	t=randint(1,2)
	if t==1 or rn<=1:
		x=randint(1,m-l[rn])
		print 1, x, x+l[rn]
		rn+=1
	else:
		x=randint(0,rn-1)
		y=randint(0,rn-1)
		while x==y: y=randint(0,rn-1)
		print 2, x+1, y+1
