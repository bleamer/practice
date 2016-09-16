''' Solution to Coin change problem https://www.hackerrank.com/challenges/coin-change '''

import os,sys

def solutions(expectedTotal, denominations):
    NSol = [0 for x in range(expectedTotal+1)] # Number of solutions for all totals
    #print(NSol)
    #print(denominations)
    NSol[0] = 1
    # for all denominations
    for x in range(len(denominations)):
        denomination = denominations[x]
        # For every possible total
        for total in range(1, expectedTotal+1):
            # if a total is greater than current denomination
            if (total >= denomination):
                # No. of solutions for a total = Current no. of solutions + Existing no. solutions for a total 
                # that is current denomination lesser than the current total
                NSol[total] += NSol[total-denomination]
                #print(NSol[total],total, denomination)
    return NSol[expectedTotal]


if __name__ == "__main__":
    n, m = (sys.stdin.readline().split())
    n, m = int(n),int(m)
    C = [int(x) for x in sys.stdin.readline().split()]
    #print (C)
    
    print (solutions(n, C))
    
