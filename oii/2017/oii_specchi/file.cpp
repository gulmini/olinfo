#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stdio.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef set<ll> si;
typedef pair<int, bool> pb;

typedef enum {
	SOPRA = 0,
	DESTRA = 1,
	SOTTO = 2,
	SINISTRA = 3
} parete_t; // lato

vector<set<pb>> rows;
vector<set<pb>> cols;
int h, w;

typedef struct {
	parete_t lato;
	int posizione;
} foro_t; // posizione


void inizia(int height, int width) {
	int h = height;
	int w = width;
	rows.resize(h);
	cols.resize(w);
}

parete_t direction(int dir, bool s) {
	if (s) return parete_t(3 - dir);
	return parete_t((5 - dir) % 4);
}

void aggiungi(int i, int j, char diagonale) {
	bool diag = (diagonale == '\\');
	// cout << rows.size() << " " << cols.size();
	rows[i].insert(pb(j, diag));
	cols[j].insert(pb(i, diag));
}

foro_t calcola(foro_t ingresso) {
	// calcola il punto di uscita del raggio
	foro_t uscita;
	int dir = (ingresso.lato + 2) % 4;
	int x = 0, y = 0;
	pb specchio;
	if (dir % 2 == 0) x = ingresso.posizione;
	else 					y = ingresso.posizione;
	if (dir == 3) 		x = w+1;
	if (dir == 2)		y = h+1;

	cout << "dir " << dir << " x " << x << " y " << y << endl;
	for (auto s: cols) {
		cout << "[ ";
		for (auto p: s) {
			cout << p.first << " " << p.second << "  ";
		}
		cout << "]" << endl;
	}
	cout << endl;
	for (auto s: rows) {
		cout << "[ ";
		for (auto p: s) {
			cout << p.first << " " << p.second << "  ";
		}
		cout << "]" << endl;
	}
	
	while (true) {
		cout << "dir " << dir << " x " << x << " y " << y << endl;
		if (dir % 2 == 0) { // verticale
			cout << "important: x = " << x << endl;

			auto closest = lower_bound(cols[x].begin(), cols[x].end(), pb(y, false));
			if (dir == 2) closest++;

			cout << "bouncing on y = " << (*closest).first << endl;

			// cout << distance(cols[x].begin(), closest) << endl;

			if (cols[y].empty() or closest == cols[x].end() or --closest == cols[x].end()) { 
				uscita.posizione = x + 1;
				uscita.lato = parete_t(dir);
				return uscita;
			}
			closest++;

			x = (*closest).first;
			cout << "changed direction from " << dir << " to ";
			dir = direction(dir, (*closest).second); cout << dir << endl;

		}
		else { // orizzontale
			cout << "important: y = " << y << endl;
			auto closest = lower_bound(rows[y].begin(), rows[y].end(), pb(x, false));
			if (dir == 3) closest++;
			cout << "bouncing on x = " << (*closest).first << endl;

			if (rows[y].empty() or closest == rows[y].end() or --closest == rows[y].end()) {
				uscita.posizione = y + 1;
				uscita.lato = parete_t(dir);
				return uscita;
			}
			closest++;

			y = (*closest).first;
			cout << "changed direction from " << dir << " to ";
			dir = direction(dir, (*closest).second); cout << dir << endl;
		}
		cout << "ended cycle" << endl;
	}
}

int main() {
	int N, M, Q, riga, colonna, lato, posizione, i;
	char tipo;

	assert(3 == scanf("%d %d %d", &N, &M, &Q));
	inizia(N, M);

	for (i = 0; i < Q; i++) {
		assert(1 == scanf(" %c", &tipo));
		if (tipo == '?') {
			assert(2 == scanf("%d %d", &lato, &posizione));
			foro_t in = {(parete_t)lato, posizione};
			foro_t res = calcola(in);
			printf("%d %d\n", res.lato, res.posizione);
			// cout << "calcolato con successo" << endl;
		} else if (tipo == '/' || tipo == '\\') {
			assert(2 == scanf("%d %d", &riga, &colonna));
			aggiungi(riga, colonna, tipo);
		} else {
			fprintf(stderr, "Tipo di comando errato (validi: / \\ ?): %c (ascii %d)\n", tipo, (int)tipo);
			assert(0);
		}
	}
}
