#!/usr/bin/python
import sys
import shutil
import os
fileTypes = [ "GM1", "dri", "drd", "drl", "GBL", "GBO", "GBS", "gpi", "GTL", "GTO", "GTP", "GTS", "TXT" ]

if len(sys.argv)<2:
	print "need name of file"
	exit( 1)

fileStart = sys.argv[1]
dest = "./toFab/"
print "using", fileStart
for fileType in fileTypes: 
	src = fileStart + "." + fileType
	try:
		os.remove(  dest + src  )
	except Exception, e :
		#do nothing
		pass

	try:
		shutil.copy( src, dest )
		print "moved %s -> %s" % ( src, dest )
	except Exception, e :
		print "file error: %s" % e
