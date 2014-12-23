#!/usr/bin/python2
import sys
sys.stdout=open("beaveractor.in","w")
from random import randint
N=20
B=100000
Q=100000
print N, B
#for i in xrange(N):
#	x=randint(0,B)
#	y=randint(0,B)
#	if randint(0,1)==0:
#		y2=randint(0,B)
#		while y2==y: y2=randint(0,B)
#		print x, y, x, y2
#	else:
#		x2=randint(0,B)
#		while x2==x: x2=randint(0,B)
#		print x, y, x2, y
print """58048 46600 37102 46600
29978 99316 19422 99316
17515 64057 17515 1618
40532 46601 40532 51656
64054 60992 64054 63642
71242 73952 747 73952
49105 73951 49105 46601
95984 31721 95984 72803
59775 14382 59775 73951
72533 2550 63755 2550
6934 76994 25039 76994
91108 66736 59776 66736
24341 71329 24341 9892
50009 24129 59774 24129
9340 9911 12024 9911
18041 3134 18041 43431
77545 16103 62364 16103
68918 87442 87990 87442
85689 13072 85689 66735
67631 75771 67631 74297"""
print Q
dir=['L','U','R','D']
for i in xrange(Q):
	print randint(0,B), randint(0,B), dir[randint(0,3)], randint(0,1e15)

