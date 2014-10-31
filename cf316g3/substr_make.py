#!/usr/bin/python2
import sys
sys.stdout=open("substr.in","w")
from random import randint

def randstr(len):
	s=""
	for i in xrange(len):
		s=s+chr(randint(ord('a'),ord('c')))
	return s

l=5
m=2
print randstr(randint(1,l))
print m
for i in xrange(m):
	L=randint(0,l)
	R=randint(0,l)
	if (L>R): (L,R)=(R,L)
	print randstr(randint(1,l)), L, R
