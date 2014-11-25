#!/usr/bin/python2
import sys
sys.stdout=open("flipboard.in","w")
from random import *
n=33
print n
for i in xrange(n):
	for j in xrange(n):
		print randint(-9,9),
	print
