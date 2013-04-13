#!/usr/bin/python
from collections import deque
from decimal import *
import math

'''
Ahmed Medhat Othman
AMedOs
amedhat.cs@gmail.com
'''

def main():
	fin = open('C.in', 'r')
	fout = open('C.out','w')
	T = long(fin.readline())
	for tc in range(1,T+1):
		mn, mx = map(long, fin.readline().split())
		mn, mx = [1, 10**14]
		lo = int(mn**0.5)
		hi = int(mx**0.5)
		res =0
		for n in range(lo, hi + 1):
			if is_pal(n) and is_pal(n**2):
				res += 1

		fout.write("Case #" + str(tc) + ": " + str(res) +"\n")

def is_pal(num):
	s = str(num)
	l =len(s)
	f = True
	for i in range(l/2):
		if s[i] != s[l-i-1]:
			f = False
			break
	return f
if __name__ == '__main__':
	main()
