#!/usr/bin/python

from ctypes import *
from random import choice

class INFO(Structure):
	_fields_ = [("size", c_int),
				("offset", c_int)]
rozmiar_pakietu = 1307

with open('1535-Tenderness.jpg', 'rb') as fh:
  b = bytearray(fh.read())

# lista tablic bitow - pakietow
plik = []
#plik.append(bytearray(INFO(rozmiar_pakietu, 0)) + b[:1307])
for i in range(0, 19):
	plik.append(bytearray(INFO(rozmiar_pakietu, (i*rozmiar_pakietu)-1))+b[i*rozmiar_pakietu:(i+1)*rozmiar_pakietu-1])

# lista do losowania kolejnosci pakietow
lista = []
for x in range(0, 19):
	lista.append(x)

# mieszanie pakietow
pomieszane = []
i = 0
while (i != 19):
	index = choice(lista)
	pomieszane.append(plik[i])
	lista.remove(index)
	i = i+1

# odtworzenie pliku
kopia = [None]*19
for i in range(0, 19):
	temp = pomieszane[i]
	info = INFO.from_buffer_copy(temp[:9])
	temp = temp[8:]
	kopia[info.offset/rozmiar_pakietu] = temp
