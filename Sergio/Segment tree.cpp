#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100000;
int input [N];

int n, m; // n = numbers in array, m = queries

struct seg_tree {
	seg_tree(){};

	ll tree [4*N]; 

	void build(int arr[], int v, int tl, int tr) {
		if (tl == tr){
			tree[v] = arr[tl];
		} else {
			int tm = (tl+tr)/2;
			build(arr, 2*v, tl, tm);
			build(arr, 2*v+1, tm+1, tr);
			tree[v] = tree[2*v] + tree[2*v+1];
		}
	}

	void update(int v, int tl, int tr, int index, int new_val) {
		if (tl == tr){
			tree[v] = new_val;
		} else {
			int tm = (tl+tr)/2;
			if (index <= tm) {
				update(2*v, tl, tm, index, new_val);
			} else {
				update(2*v+1, tm+1, tr, index, new_val);
			}
			tree[v] = tree[2*v] + tree[2*v+1];
		}
	}

	ll query(int v, int tl, int tr, int l, int r) {
		if (l > r) return 0;
		if (l == tl && r == tr){
			return tree[v];
		}
		int tm = (tl+tr)/2;
		return query(2*v, tl, tm, l, min(tm, r))
				+ query(2*v+1, tm+1, tr, max(l, tm+1), r);
	}
};

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	seg_tree tree1;

	tree1.build(input, 1, 0, n-1);

	for (int i = 0; i < m; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			// update
			int index, value;
			cin >> index >> value;
			tree1.update(1, 0, n-1, index, value);
		} else {
			// query
			int l, r;
			cin >> l >> r;
			r--; // asks for [l, r-1]
			ll ans = tree1.query(1, 0, n-1, l, r);
			cout << ans << endl;
		}
	}

}
