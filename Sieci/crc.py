#!/usr/bin/python

from bitarray import bitarray

# fixed key
key = bitarray([True, False, True, False])
#print key

i = 0
a = bitarray()
with open('1535-Tenderness.jpg', 'rb') as fh:
  a.fromfile(fh)
  
for i in range (0, 3):
	a.append(False)
  
while (i != len(a) - 1):
	#print i
	for x in range(i, i+4):
		a[i] = a[i] ^ key[x-i]
	i += 4
	
print a[-3:]
