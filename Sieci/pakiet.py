#!/usr/bin/python

from ctypes import *
from random import choice

class INFO(Structure):
	_fields_ = [("size", c_int),
				("offset", c_int),
				("data", c_byte * 1307)] # 1307 - wielkosc pakietu w bajtach

# prototypy tablic - cos jak klasy
byte_array = c_byte * 1307
pakiety = byte_array * 19 # 1307*19 = 24833 - ilosc bajtow w pliku
calosc = INFO * 19
plik = c_byte * 24833


with open('1535-Tenderness.jpg', 'rb') as fh:
  b = bytearray(fh.read())

array = pakiety() # "obiekt" "klasy" pakiety - tablica 1307x19
for i in range(0, 19):
	for x in range(0, 1307):
		array[i][x] = (b[i*1307+x])

file_info = calosc() # "obiekt" "klasy" calosc - 19-elementowa tablica struktur typu INFO
for x in range(1, 19):
	file_info[x] = INFO(1307, x, array[x])

# wszystkie struktury zawierajace dane i informacje o nich znajduja sie w 19-elementowej tablicy file_info
# tworzymy druga tablice ze wzorca calosc, w ktora wsadzimy pomieszane struktury
pomieszane = calosc()
# lista do losowania kolejnosci pakietow
lista = []
for x in range(0, 19):
	lista.append(x)
# losowanie kolejnosci i ustawianie pakietow
i = 0
while (i != 19):
	index = choice(lista)
	pomieszane[index] = file_info[i]
	lista.remove(index)
	i = i+1
# tworzenie nowej tablicy, identycznej z pierwowzorem
kopia = plik()
for x in range(0, 19):
	for i in range(0, 1307):
		print str(pomieszane[x].data[i]) + ' ' + "x: " + str(x) + " i: " + str(i)
		kopia[(1307*pomieszane[x].offset)+i] = pomieszane[x].data[i]
