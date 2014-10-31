#!/usr/bin/python2
from random import randint
import sys
sys.stdout=open("sale.in","w")

n=9
print n
for i in xrange(n):
	print randint(1,int(n*0.7)),

