for _ in range(int(input())):
	n = int(input())
	if 3**(n-1) > 10**9:
		print("NO")
	else:
		print("YES")
		print(*[3**x for x in range(n)])
