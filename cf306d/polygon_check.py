import math
I=open("polygon.out")
A=I.readlines()
for i in xrange(len(A)):
	A[i]=map(float,A[i].split())
for i in xrange(len(A)):
	x1=A[i-2][0]-A[i-1][0]
	y1=A[i-2][1]-A[i-1][1]
	x2=A[i][0]-A[i-1][0]
	y2=A[i][1]-A[i-1][1]
	print math.acos((x1*x2+y1*y2)/math.sqrt((x1*x1+y1*y1)*(x2*x2+y2*y2)))
print
for i in xrange(len(A)):
	x=A[i][0]-A[i-1][0]
	y=A[i][1]-A[i-1][1]
	print math.sqrt(x*x+y*y)
