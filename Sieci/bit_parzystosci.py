#!/usr/bin/python

from bitarray import bitarray
import random

def check_parity(a):
  even = True
  for i in range(0, len(a) - 1):
    if(a[i] & True):
      if even == True:
	even = False
      else:
	even = True
  return even

a = bitarray()
change_percentage = 0.15

with open('1535-Tenderness.jpg', 'rb') as fh:
  a.fromfile(fh)

#print ("Read " + str(len(a)) + " bits.")

even = check_parity(a)
print even

#change_perc = input("How many bits should be changed? (%)\n")
#if (change_perc < 0 or change_perc > 100):
  #print "\nPlease enter the number between 0 and 100"
  #change_perc = raw_input("How many bits should be changed? (%)")

change = int(len(a) * change_percentage)
print str(change) + " bits will be changed."

changed_bits = []

for i in range(0, change - 1):
  number = random.randint(0, len(a) - 1)
  changed_bits.append(number)
  if a[number] == True:
    a[number] = False
  elif a[number] == False:
    a[number] = True 

even = check_parity(a)
print even
#print changed_bits