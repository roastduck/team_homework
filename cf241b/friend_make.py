#!/usr/bin/python
import sys
sys.stdout=open("friend.in","w")
from random import randint

n=50000
m=randint(1,n*(n-1)/2)
print n, m
for i in xrange(n):
	print randint(0,1e9),
