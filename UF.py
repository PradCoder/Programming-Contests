S,N,M = map(int, input().split()) #includes all S nodes and N edges

lst = [(0,0,0)] * (N+M)

link = [i for i in range(S)]
size = [1 for i in range(S)]

def union(x,y):
	global size, link;
	x = find(x)
	y = find(y)
	if(size[x]<size[y]):
		x,y = y,x
	link[y] = x
	size[x] += size[y]

def find(x):
	global link;
	while x != link[x]:
		x = link[x];
	return x

def same(x,y):
	return find(x) == find(y)

def solve():
	global link,N,M,lst;
	for i in range(N+M):
		x,y,l = map(int,input().split())
		lst[i] = (x,y,l)
	s1,s2 = sum([lst[i][2] for x in range(N)]),0
	lst = sorted(lst, key = lambda x: x[2]) 
	for i in range(N+M):
		if(not same(link[lst[i][0]-1],link[lst[i][1]-1])):
			union(link[lst[i][0]-1],link[lst[i][1]-1])
			s2 += lst[i][2]
	dif = s1-s2
	return dif

def main():
	print(solve())

if __name__ == "__main__":
	main()
