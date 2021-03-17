class DepthFirstOrd:
	def __init__(self, G):
		self.pre = []
		self.post = []
		self.reversePost = []
		self.marked = [False] * len(G)
		
		for i in range(len(marked)):
			if(not marked[i]) dfs(G,v);
	
	def dfs(G,v):
		marked[v] = true
		self.pre.append(v)
		self.marked[v] = True
		for i in G[v]:
			if(not marked[i]):
				dfs(G,i)
		self.post.append(v)
		self.reversePost.insert(0,v)

	def reversePostOrd():
		return self.reversePost

visited = []
def main():
	N = (int,input())
	G = [[] for i in range(N)] #for N nodes
	global visited;
	visited = [False for i in range(N+1)]
	for i in range(N):
		s,e = map(int,input().split())
		G[s] = e #exclude one if un directed
		G[e] = s
def dfs(G,v):
	global visited;
	stack = []
	stack.append(v)
	while S do:
		v = S.pop(0)
		if not visited[v]:
			visited[v] = True;
			for w in G[v]:
				S.push(w) 

def bfs(G,v):
	global visited;
	queue = []
	queue.append(v)
	visited[v] = True
	while queue:
		v = queue.pop()
		for w in G[v]:
		    if not visited[w]:	
			visited[w] = True
			queue.append(w)
