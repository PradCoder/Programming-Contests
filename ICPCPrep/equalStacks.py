import math
import os
import random
import re
import sys
import functools

def solve1 (h1, h2, h3):
    if (sum(h1) == sum(h2) and sum(h2) == sum(h3) and sum(h3) == sum(h1)):
        return sum(h1)
    else:
        return (max[solve1(h1[:-1], h2, h3), solve1(h1, h2[:-1], h3), solve1(h1,h2,h3[:-1])])
        
        
def equalStacks(h1, h2, h3):
    h1.reverse()
    h2.reverse()
    h3.reverse()
    return solve1 (h1,h2,h3)
    # Write your code here

if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    n1 = int(first_multiple_input[0])

    n2 = int(first_multiple_input[1])

    n3 = int(first_multiple_input[2])

    h1 = list(map(int, input().rstrip().split()))

    h2 = list(map(int, input().rstrip().split()))

    h3 = list(map(int, input().rstrip().split()))

    result = equalStacks(h1, h2, h3)

    sys.stdout.write(str(result) + '\n')


