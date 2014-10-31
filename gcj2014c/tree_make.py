#!/usr/bin/python2
import sys
sys.stdout=open("tree.in","w")
from random import randint
t=10000
print t
for tt in xrange(t):
	n=120
	print n
	for i in xrange(n):
		print chr(randint(ord('A'),ord('D')))
	for i in xrange(2,n+1):
		print randint(1,i-1), i
