#!/usr/bin/python2
import sys
sys.stdout=open("tape.in","w")
from random import randint
n=10
q=10
print n, q
s=""
for i in xrange(n):
	x=randint(0,11)
	if (x==10):
		s=s+'<'
	elif (x==11):
		s=s+'>'
	else:
		s=s+str(x)
print s
for i in xrange(q):
	x=randint(1,n)
	y=randint(1,n)
	if (x>y): (x,y)=(y,x)
	print x, y
