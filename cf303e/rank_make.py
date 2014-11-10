#!/usr/bin/python2
from random import randint
import sys
sys.stdout=open("rank.in","w")

n=80
MAX=int(1e9)
print n
for i in xrange(n):
	x=randint(0,MAX)
	y=randint(0,MAX)
	if (x>y): (x,y)=(y,x)
	print x, y
