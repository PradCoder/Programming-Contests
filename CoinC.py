def solve(x):
	INF = 1 << 63 + (1 << 63 - 1)
	if (x< 0): return INF
	if( x == 0) return 0;
	int best = INF;
	for i in coins:
		best = min(best,solve(x-c) + 1);
	return best
