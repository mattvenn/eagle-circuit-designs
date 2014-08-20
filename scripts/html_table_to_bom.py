#!/usr/bin/python
from BeautifulSoup import BeautifulSoup
import sys
import re
import csv

html_doc=open('shrimpv1.htm').read()
soup = BeautifulSoup(html_doc)
output = csv.writer(sys.stdout,delimiter='\t')

for table in soup.findAll('table'):
    for row in table.findAll('tr'):
        col = map(lambda x: x.getText(), row.findAll(re.compile('t[dh]')))
        output.writerow(col)
    output.writerow([])
