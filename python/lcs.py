

''' Recursive algo to find length of longest common substring'''

import sys
inStr1 = "Wakaka"
inStr2 = "kakakaburaburaWakakaDadada"

lcslen = 0

def lcs(str1, str2, l1, l2):
	print(str1[:l1-1],str2[:l2-1])
	if l1 == 0 or l2 == 0:
		return 0
	elif str1[l1-1] == str2[l2-1]:
		return 1 + lcs(str1, str2, l1-1, l2-1)
	else: 
		return max(lcs(str1, str2, l1-1, l2), lcs(str1, str2, l1, l2-1))



lcslen  = lcs(inStr1, inStr2, len(inStr1), len(inStr2))
print(lcslen)