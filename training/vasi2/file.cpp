#include <iostream>
#include <vector>
using namespace std;
const string quack = "quack";

int n, q;

struct Node {
	int nl = 1;
	int nr = 0;
	int val;
	Node *l = NULL;
	Node *r = NULL;
	Node(): val(0), nl(1), nr(0), l(NULL), r(NULL) {}
	Node(int val): val(val), nl(1), nr(0), l(NULL), r(NULL) {}
};

Node * root = NULL;
vector<int> v;
int sz = 0;
Node nodes[16500000];
Node * nodes_ptr = nodes;

inline void update_n(Node *&i);
inline bool balanced(Node *i);
Node * get_left_leaf(Node *i);
Node * insert(Node *&i, int k, int x);
Node * remove(Node *&i, int k);
int query(Node *i, int k);
void build(Node *&i, int l, int r);
void rebuild(Node *&i, int l, int r);
void traverse(Node *i);
void full_rebuild(Node *&i);
void clear(Node *&i);

Node * newnode(int x) {
	nodes_ptr->val = x;
	return nodes_ptr++;
}

Node * get_left_leaf(Node *i) {
	if (i->l) return get_left_leaf(i->l);
	return i;
}

inline void update_n(Node *&i) {
	i->nl = 1; i->nr = 0;
	if (i->l) i->nl += i->l->nl + i->l->nr;
	if (i->r) i->nr += i->r->nl + i->r->nr;
}

inline bool balanced(Node *i) {
	return (3*(i->nl-1) <= 2*(i->nl+i->nr) && 3*(i->nr) <= 2*(i->nl+i->nr));
}

Node * insert(Node *&i, int k, int x) {
	if (i == NULL) return i = newnode(x);
	if (k < i->nl) i->l = insert(i->l, k, x);
	else i->r = insert(i->r, k-i->nl, x);
	update_n(i);
	if (not balanced(i))
		full_rebuild(i);
	return i;
}

void clear(Node *&i) {
	if (i == NULL) return;
	if (i->l) clear(i->l);
	if (i->r) clear(i->r);
	i = NULL;
}

Node * remove(Node *&i, int k) {
	if (i == NULL) return NULL;
	if (k < i->nl-1) i->l = remove(i->l, k);
	else if (k > i->nl-1) i->r = remove(i->r, k-i->nl);
	else {
		if (not i->l and not i->r) {
			i = NULL;
			return NULL;
		}
		if (not i->l) {
			Node *tmp = i->r;
			if (i != root) i = NULL;
			else root = i->r;
			return tmp;
		}
		if (not i->r) {
			Node *tmp = i->l;
			if (i != root) i = NULL;
			else root = i->l;
			return tmp;
		}
		Node *tmp = get_left_leaf(i->r);
		i->val = tmp->val;
		i->r = remove(i->r, 0);
	}
	update_n(i);
	return i;
}

int query(Node *i, int k) {
	if (k < i->nl-1) return query(i->l, k);
	if (k > i->nl-1) return query(i->r, k-i->nl);
	return i->val;
}

void build(Node *&i, int l, int r) {
	if (l > r) return;
	int m = (l+r)/2;
	i = newnode(m);
	build(i->l, l, m-1);
	build(i->r, m+1, r);
	update_n(i);
}

void rebuild(Node *&i, int l, int r) {
	if (l > r) return;
	int m = (l+r)/2;
	i = newnode(v[m]);
	rebuild(i->l, l, m-1);
	rebuild(i->r, m+1, r);
	update_n(i);
}

void traverse(Node *i) {
	if (i == NULL) return;
	traverse(i->l);
	v.push_back(i->val);
	traverse(i->r);
}

void full_rebuild(Node *&i) {
	v.clear();
	traverse(i);
	clear(i);
	rebuild(i, 0, v.size()-1);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	char c; int a, b;

	build(root, 0, n-1);
	sz = n;

	while (q--) {
		cin >> c;
		if (c == 'c') {
			cin >> a;
			cout << query(root, a) << " ";
		}
		else {
			cin >> a >> b;
			int val = query(root, a);
			remove(root, a);
			insert(root, b, val);
		}
	}
}

