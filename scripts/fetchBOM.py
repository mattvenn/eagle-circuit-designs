#!/usr/bin/python
import mechanize
import sys
from BeautifulSoup import BeautifulSoup
if len(sys.argv)<2:
    print "need part num"
    exit( 1)
part_num = sys.argv[1]
br = mechanize.Browser()
br.set_handle_robots(False)
br.open("http://uk.farnell.com")
br.select_form(name="textsearch")
br["searchTerms"] = part_num
body = br.submit().read()
soup = BeautifulSoup(body)
title = soup.title.string.strip()
details = title.split('|')[0].split(' - ')
manu_part = details[0]
manu = details[1]
desc = details[2]
"""
dt = soup.findAll('dt')
manu = dt[0].nextSibling.nextSibling.string
part_num = dt[1].nextSibling.nextSibling.string
manu_part = dt[2].nextSibling.nextSibling.string
manu = manu.strip()
"""
#format like this:
#Mfg Part Num	Mfg Name	VID	Vendor Part Num	Description
print manu_part + "\t" + manu + "\tfarnell\t" + part_num + "\t" + desc
