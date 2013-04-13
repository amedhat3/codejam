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
	fin = open('B-small-attempt0.in', 'r')
	fout = open('B.out','w')
	T = long(fin.readline())
	for tc in range(1,T+1):	
		N, M = map(long,fin.readline().split())
		data = []
		for i in range(N):
			data.append(map(int,fin.readline().split()))
		
		tcount = 0
		for i in range(N):
			for j in range(M):
				if data[i][j] == 1:
					tcount += 1
		#print 'tcount' , tcount
		
		for i in range(N):
			rem = 0
			rcount = 0
			for j in range(M):
				if data[i][j] == 1:
					rem += 1
				if data[i][j] <= 1:
					rcount +=1
			#print 'rcount ' ,rcount
			#print 'rem ' ,rem
			if rcount >= M:
				tcount-= rem
				for j in range(M):
					if data[i][j] == 1:
						data[i][j] -= 1

		for j in range(M):
			rem = 0
			ccount = 0
			for i in range(N):
				if data[i][j] == 1:
					rem += 1
				if data[i][j] <= 1:
					ccount +=1
			
			#print 'ccount ' ,ccount
			#print 'rem ' ,rem
			if ccount >= N:
				tcount -= rem
				for i in range(N):
					if data[i][j] == 1:
						data[i][j] -= 1

		#print 'tcount' , tcount
		if tcount > 0:
			res = 'NO'
		else:
			res = 'YES'

		fout.write("Case #" + str(tc) + ": " + res +"\n")

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
