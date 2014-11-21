#!/usr/bin/python2
import sys
sys.stdout=open("gcd.in","w")
from random import *

def gcd(a,b):
	if (a<b): (a,b)=(b,a)
	while (b):
		c=a%b
		a=b
		b=c
	return a

#k=randint(1,10000)
k=9748
print 1000000000000, 1000000000000, k
#x=randint(1,30000)
#y=randint(1,30000)
x=175168980
y=104187295
sys.stderr.write("%d %d\n"%(x,y))
for i in xrange(k):
	print gcd(x,y+i),
