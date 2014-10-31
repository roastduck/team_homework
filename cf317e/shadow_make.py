#!/usr/bin/python2
import sys
sys.stdout=open("shadow.in","w")
from random import randint
m=400
S=set([])

def randpoint():
	x=y=None
	while (True):
		x=randint(-100,100)
		y=randint(-100,100)
		if ((x,y) not in S):
			S.add((x,y))
			print x, y
			return
		
randpoint()
randpoint()
print m
for i in xrange(m):
	randpoint()
