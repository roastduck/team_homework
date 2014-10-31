#!/usr/bin/python2
from random import randint, uniform

T = 50
HEIGHT = 100
SMALL_M = 10
P_SMALL = 0.6
P_CONTINUE = 0.1
H=20
W=20

walk = ((-1,0),(0,1),(1,0),(0,-1))

def Fill(A, x, y, h, M):
	global H, W, P_CONTINUE, HEIGHT
	cnt = 1
	A[x][y] = h
	for k in xrange(4):
		if (uniform(0,1)<P_CONTINUE):
			_x = x+walk[k][0]
			_y = y+walk[k][1]
			if (_x<0 or _x>=H or _y<0 or _y>=W or A[_x][_y]!=-1): continue
			_h = randint(max(0,h-M),min(HEIGHT,h+M))
			cnt = cnt + Fill(A, _x, _y, _h, M)
	return cnt

print T
for t in xrange(T):
	if (uniform(0,1)<P_SMALL):
		M = randint(1,SMALL_M)
	else:
		M = randint(1,HEIGHT)
	print H, W, M
	A = [[-1]*W for i in xrange(H)]
	cnt = 0
	while (cnt<H*W):
		x = y = None
		while (True):
			x = randint(0,H-1)
			y = randint(0,W-1)
			if (A[x][y]==-1): break
		cnt = cnt + Fill(A, x, y, randint(0,HEIGHT), M)
	for i in xrange(H):
		for j in xrange(W):
			print A[i][j],
		print
