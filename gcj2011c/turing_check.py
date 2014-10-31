#!/usr/bin/python2
I = open("turing.out")

n = int(I.readline())
T = {}
M = {}

def mark(x):
	global M
	if (not M.has_key(x)):
		return 0
	else:
		return M[x]

for i in xrange(n):
	s = I.readline().split()
	T[(int(s[0]),int(s[1]))] = s[3:]

stat = 0
dist = 0
cnt = 0
while (T[(stat, mark(dist))][0]!='R'):
	tmp = T[(stat, mark(dist))]
	stat = int(tmp[1])
	M[dist] = int(tmp[2])
	if (tmp[0]=='E'):
		dist = dist + 1
	else:
		dist = dist - 1
	cnt = cnt + 1
print dist
print cnt
