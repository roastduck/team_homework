#!/usr/bin/python
import sys,re,urllib2
now=[]
for i in range(5400,5700):
	pat=re.compile('P\d{4}\.')
	targeturl='http://www.tsinsen.com/P'+str(i)
	f1=urllib2.urlopen(targeturl)
	f1=f1.read()
	f1=re.findall(pat,f1)
	if len(f1)>0:
		print f1[0]
		now.append(i)
print now
