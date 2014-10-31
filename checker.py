# use it in windows

import sys, os

path = sys.argv[1]

if (not os.path.exists(path)):
	print "No such directory"
	exit(1)

spj = False

if (os.path.exists(path+'\\spj.exe')):
	spj = path+'\\spj.exe'

def judge(tester, dir, files):
	print '================'
	print 'running ' + tester
	global spj
	verdict = True
	IN = filter(lambda x: x.split('.')[-1]=='in', files)
	OUT = filter(lambda x: x.split('.')[-1]=='out', files)
	if (len(IN)!=len(OUT)):
		print "Ambious data"
		return False
	for i in xrange(len(IN)):
		IN[i] = dir + '\\' + IN[i]
		OUT[i] = dir + '\\' + OUT[i]
	for i in xrange(len(IN)):
		os.system(tester + ' < ' + IN[i] + ' > checker.tmp')
		res = None
		if (spj):
			os.system("%s %s %s %s %s"%(spj, IN[i], 'checker.tmp', OUT[i], 'spj.log'))
			FILE = open('spj.log')
			res = FILE.readline()
			if (res=='1\n'):
				res = False
			else:
				res = True
			FILE.close()
		else:
			res = os.system('fc /w checker.tmp ' + OUT[i])
		if (res) : 
			print IN[i], OUT[i], 'WRONG'
			verdict = False
		else:
			print IN[i], OUT[i], 'ACCEPT'
	return verdict

def runner(data, dir, files):
	verdict = True
	arr = filter(lambda x: x.split('.')[-1]=='exe', files)
	for exe in arr:
		res = os.path.walk(data, judge, dir+'\\'+exe)
		if (not res): verdict = False
	return verdict

if (not os.path.walk(path+'\\former', runner, path+'\\data')): exit(1)
exit(0)
