#!/usr/bin/python2
from random import randint, shuffle

n=9
print n

s=[['0']*n for i in xrange(n)]

for i in xrange(n):
	l=randint(0,n)
	r=randint(0,n)
	if (l>r): (l,r)=(r,l)
	for j in xrange(l,r):
		s[j][i]='1'

shuffle(s)
for i in xrange(n):
	t=""
	for j in xrange(n):
		t=t+s[j][i]
	print t
