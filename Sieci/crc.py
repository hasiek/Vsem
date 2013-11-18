#!/usr/bin/python

from bitarray import bitarray

# fixed key
key = bitarray([True, True, False, False])
#print key

i = 0
a = bitarray()
with open('1535-Tenderness.jpg', 'rb') as fh:
  a.fromfile(fh)
  
for i in range (0, 3):
	a.append(False)

	
i = 0
  
for i in range(0, len(a) - 3):
	if (a[i] == True):
		for x in range(i, i+4):
			#print "x: " + str(x)
			#print "Poprzednie: " + str(a[i])
			a[x] = a[x] ^ key[x-i]
			#print "Obecne: " + str(a[i])
	else:
		continue

print a[-3:]
