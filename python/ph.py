import urllib
from lxml import html
f=urllib.urlopen("http://www.python.org")
s=f.read()

tree = html.fromstring(s)

[td.text for td in tree.xpath("//td")]

#print tree
