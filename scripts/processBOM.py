#!/usr/bin/python
import sys
import csv
if len(sys.argv)<2:
    print >>sys.stderr, "need bom file"
    exit( 1)
bom_file = sys.argv[1]

rows = 0
bad_rows = 0

with open(bom_file,'r') as csvfile:
    reader = csv.reader(csvfile, delimiter='\t')
    for row in reader:
        #check for errors
        rows += 1
        if rows == 1:
            continue
        if not 'ERROR' in row[0]:
            #check row length, should be 10
            if len(row) != 10:
                print >> sys.stderr, "bad row length: ", row
                bad_rows+=1
            else:
                print ', '.join([row[3],row[5],row[4]])
        else:
            bad_rows += 1
print >>sys.stderr ,"processed %d rows with %d missing rows" % (rows,bad_rows)

