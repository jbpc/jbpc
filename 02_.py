import urllib, re
for i in ( re.findall( r'<img .*?src="(.*?)".*?>', urllib.urlopen(' 网址').read() ) )
    urllib.urlretrieve(i, i.split('/')[-1])
