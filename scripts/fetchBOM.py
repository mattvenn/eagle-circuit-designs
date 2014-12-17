#!/usr/bin/python
import mechanize
import sys
import csv


#from BeautifulSoup import BeautifulSoup
if len(sys.argv)<2:
    print "need part num"
    exit( 1)
part_num = sys.argv[1]

#get list of all primary keys from db
keys = []
db = "../partsdb.txt"
with open(db,'r') as csvfile:
    reader = csv.reader(csvfile, delimiter='\t')
    for row in reader:
        keys.append(row[0])
#we can fetch all the info we need from the title of the page
br = mechanize.Browser()
br.set_handle_robots(False)
br.open("http://uk.farnell.com")
br.select_form(name="CatalogSearchForm")
br["st"] = part_num
body = br.submit().read()
title = br.title()
#soup = BeautifulSoup(body)
#title = soup.title.string.strip()
details = title.split('|')[0].split(' - ')
manu_part = details[0]
manu = details[1]
desc = details[2]

""" before realised all the info is in the title!
dt = soup.findAll('dt')
manu = dt[0].nextSibling.nextSibling.string
part_num = dt[1].nextSibling.nextSibling.string
manu_part = dt[2].nextSibling.nextSibling.string
manu = manu.strip()
"""
#format like this:
#Mfg Part Num	Mfg Name	VID	Vendor Part Num	Description
print "found part:"
part_info = manu_part + "\t" + manu + "\tfarnell\t" + part_num + "\t" + desc + "\n"
print part_info

if manu_part in keys:
    print "duplicate part, not adding"
else:
    print "added to db"
    fd = open(db,'a')
    fd.write(part_info)
