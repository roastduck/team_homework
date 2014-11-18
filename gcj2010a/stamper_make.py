#!/usr/bin/python2
from random import randint
import sys
sys.stdout=open("stamper.in","w")
t=1
l=4
print t
for tt in xrange(t):
	s=""
	for ll in xrange(l):
		s=s+chr(randint(ord('A'),ord('C')))
	print s
