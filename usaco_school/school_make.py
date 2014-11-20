#!/usr/bin/python
import sys
sys.stdout=open("school.in","w")
from random import *
n=5
S=set()
print n
for i in xrange(n):
	t=p=None
	while (True):
		p=randint(1,10)
		t=randint(1,p)
		if ((p/t) not in S): break
	S.add(p/t);
	print t, p
