#!/usr/bin/python2
from random import shuffle
import sys
sys.stdout = open("string.in","w")
sys.stdin = open("string_make.in")

(n,m) = sys.stdin.readline().split()
(n,m) = (int(n), int(m))
print n, m
X = [i for i in xrange(n)]
Y = [i for i in xrange(m)]
shuffle(X)
shuffle(Y)
for i in xrange(n+m):
	s = sys.stdin.readline().split()
	if (s[0]=='L' or s[0]=='R'):
		s[2] = X[int(s[2])-1]+1
	else:
		s[2] = Y[int(s[2])-1]+1
	if (s[1]=='L' or s[1]=='R'):
		s[3] = X[int(s[3])-1]+1
	else:
		s[3] = Y[int(s[3])-1]+1
	print s[0], s[1], s[2], s[3]
