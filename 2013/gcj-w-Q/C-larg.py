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
	fin = open('C-large-1.in', 'r')
	fout = open('C.out','w')
	mem = dict()

	data = dict()
		
	data[1]=[1,2,3,4,5,6,7,8,9]
	data[2]=[11,22,33,44,55,66,77,88,99]

	def solve(size):
		if size < 3:
			return data[size]
		if size % 2 ==0:
			ot = data[size-2]
			ins = data[2]
		else:
			ot = data[size-1]
			ins = data[1]

		data[size] = []
		for i in ot:
			s = str(i)
			s1 = s[0:len(s)/2]
			s2 = s[len(s)/2:len(s)]
			for j in ins:
				data[size].append(long(s1 + str(j) + s2))
		return data[size]

	for i in range(1,14):
		solve(i)

	def is_pal(num):
		if num in mem:
			return mem[num]

		s = str(num)
		l =len(s)
		f = True
		for i in range(l/2):
			if s[i] != s[l-i-1]:
				f = False
				break
		mem[num] = f
		return f

	T = long(fin.readline())
	for tc in range(1,T+1):
		mn, mx = map(long, fin.readline().split())
		lo = int(mn**0.5)
		hi = int(mx**0.5)
		res = 0
		
		slo = str(lo)
		shi = str(hi)

		for x in range(len(slo),len(shi)+1):
			for d in data[x]:
				dd = d**2
				if d >= lo and d <= hi and dd >= mn and dd <= mx and is_pal(dd):
					res+=1

		fout.write("Case #" + str(tc) + ": " + str(res) +"\n")	
if __name__ == '__main__':
	main()
