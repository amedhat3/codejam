#!/usr/bin/python
from collections import deque
from decimal import *

'''
Ahmed Medhat Othman
AMedOs
amedhat.cs@gmail.com
'''

def main():
	fin = open('A-large.in', 'r')
	fout = open('A.out','w')
	T = long(fin.readline())
	for tc in range(1,T+1):
		l = list()
		for i in range(4):
			s = fin.read(4)
			fin.readline()
			l.append(s)
		fin.readline()

		flag = 0
		for s in l:
			if s.find('.') != -1:
				flag = 1
		
		def check_winner():
			for i in range(4):
				# check rows
				if (l[i][0] == 'X' or l[i][0] == 'T') and (l[i][1] == 'X' or l[i][1] == 'T') and (l[i][2] == 'X' or l[i][2] == 'T') and (l[i][3] == 'X' or l[i][3] == 'T'):
					return 'X won'
				if (l[i][0] == 'O' or l[i][0] == 'T') and (l[i][1] == 'O' or l[i][1] == 'T') and (l[i][2] == 'O' or l[i][2] == 'T') and (l[i][3] == 'O' or l[i][3] == 'T'):
					return 'O won'
				# check for columns
				if (l[0][i] == 'X' or l[0][i] == 'T') and (l[1][i] == 'X' or l[1][i] == 'T') and (l[2][i] == 'X' or l[2][i] == 'T') and (l[3][i] == 'X' or l[3][i] == 'T'):
					return 'X won'
				if (l[0][i] == 'O' or l[0][i] == 'T') and (l[1][i] == 'O' or l[1][i] == 'T') and (l[2][i] == 'O' or l[2][i] == 'T') and (l[3][i] == 'O' or l[3][i] == 'T'):
					return 'O won'
			
			# check for the first diagonal
			if (l[0][0] == 'X' or l[0][0] == 'T') and (l[1][1] == 'X' or l[1][1] == 'T') and (l[2][2] == 'X' or l[2][2] == 'T') and (l[3][3] == 'X' or l[3][3] == 'T'):
				return 'X won'
			if (l[0][0] == 'O' or l[0][0] == 'T') and (l[1][1] == 'O' or l[1][1] == 'T') and (l[2][2] == 'O' or l[2][2] == 'T') and (l[3][3] == 'O' or l[3][3] == 'T'):
				return 'O won'
			#check for the other diagonal
			if (l[0][3] == 'X' or l[0][3] == 'T') and (l[1][2] == 'X' or l[1][2] == 'T') and (l[2][1] == 'X' or l[2][1] == 'T') and (l[3][0] == 'X' or l[3][0] == 'T'):
				return 'X won'
			if (l[0][3] == 'O' or l[0][3] == 'T') and (l[1][2] == 'O' or l[1][2] == 'T') and (l[2][1] == 'O' or l[2][1] == 'T') and (l[3][0] == 'O' or l[3][0] == 'T'):
				return 'O won'
			
			return ''

		r = check_winner()
		if flag == 1 and r == '':
			res = 'Game has not completed'
		elif flag == 0 and r == '':
			res = 'Draw'
		else:
			res = r

		fout.write("Case #" + str(tc) + ": " + res +"\n")

if __name__ == '__main__':
	main()
