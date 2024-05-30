#include<bits/stdc++.h>
using namespace std;

#define intll long long
#define endl '\n'
#define TEST_CASE false

template<typename T>
void PRINT(vector<T>& arr) {
	for (int i = 0; i < int(arr.size()); i++)
		cout << arr[i] << " \n"[i == int(arr.size()) - 1];
}

const int inf = int(1e9) + 10;

struct dsu {
	vector<int> nodes;
	int component;
	int N;

	dsu(int n) : N(n) {
		nodes = vector<int>(N + 1, -1);
		component = n;
	}

	// find parent or get representive component (uses path compression)
	int find_parent(int x) {
		return nodes[x] < 0 ? x : nodes[x] = find_parent(nodes[x]);
	}


	bool same_set(int a, int b) {
		return find_parent(a) == find_parent(b);
	}

	// comp(x)'s size
	int size(int x) {
		return -nodes[find_parent(x)];
	}

	// Component number
	int count() {
		return component;
	}

	// connects x and y
	bool unite(int x, int y) {  // union by size
		x = find_parent(x);
		y = find_parent(y);

		if (x == y) {
			return false;
		}
		if (nodes[x] > nodes[y]) {
			swap(x, y);
		}

		nodes[x] += nodes[y];
		nodes[y] = x;
		// weight[y] = min(weight[x], weight[y]);
		// weight[y] = min({weight[y], wx, wy});
		component--;
		return true;
	}

	vector<vector<int>> group() {
		vector<int> parent_buf(N + 1), group_size(N + 1);
		for (int i = 1; i <= N; i++) {
			parent_buf[i] = find_parent(i);
			group_size[parent_buf[i]]++;
		}
		vector<vector<int>> result(N + 1);
		for (int i = 1; i <= N; i++)
			result[i].reserve(group_size[i]);
		for (int i = 1; i <= N; i++)
			result[parent_buf[i]].push_back(i);
		result.erase(
		    remove_if(result.begin(), result.end(),
		[&](const vector<int> &v) { return v.empty(); }),
		result.end());
		return result;
	}
};


void solution() {

	int n, q;
	cin >> n >> q;

	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	// PRINT(arr);

	dsu d(n);
	while (q--) {
		int u, v;
		cin >> u >> v;
		d.unite(u, v);
	}

	for (int i = 1; i <= n; i++) {
		int p = d.find_parent(i);
		arr[p] = min(arr[i], arr[p]);
	}

	intll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += 1ll * (i == d.find_parent(i) ? arr[i] : 0);

	cout << ans << endl;
}

int32_t main() {

	ios::sync_with_stdio(false) ; cin.tie(0) ;

	int t_c = 1, tt_c = 1;
	if (TEST_CASE) cin >> t_c;

	while (t_c--) {
		// cout << "Case " << tt_c++ << ": ";
		solution();
		// if (t_c) cout << '\n';
	}

	return 0;
}