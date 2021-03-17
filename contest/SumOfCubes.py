def solve(m):
	lst = []
	c = 1
	while (c**3) < m:
		lst.append(c);
		c+=1
	
	dic = {(i**3):(m-i**3) for i in lst}
	
	for i in lst:
		if(i**3 in dic):
			if((m-i**3) in dic):
				return "YES"
	return "NO"
		
def main():
	n = int(input())
	for i in range(n):
		ans = solve(int(input()))
		print(ans)

if __name__ == "__main__":
	main()
