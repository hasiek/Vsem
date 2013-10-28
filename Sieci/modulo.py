#!/usr/bin/python

from bitarray import bitarray

# fixed value of modulo
modulo = 13

def count_modulo(a):
	sum_modulo_local = 0
	ascii = 0
	i = 0
	while (i != len(a)):
		byte = bitarray()
		ascii = 0
		for x in range(i, i+8):
			byte.append(a[x])
		# print str(byte) + ' '
		for x in range(7, -1, -1):
			ascii += byte[x] * pow(2, x)
			# print byte[x] * pow(2, x)
		# print "x = " + str(x) + " ASCII = " + str(ascii)
		# print ascii % modulo
		sum_modulo_local += ascii % modulo
		del byte
		i += 8
	return sum_modulo_local

a = bitarray()
sum_modulo = 0

with open('1535-Tenderness.jpg', 'rb') as fh:
  a.fromfile(fh)
  
if len(a) % 8 == 0:
	print "No bits left."
	sum_modulo = count_modulo(a)
else:
	for i in range (0, len(a) % 8):
		a.append(False)
	sum_modulo = count_modulo(a)

print sum_modulo
