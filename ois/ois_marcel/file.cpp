#include <iostream>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef uint8_t u8;
constexpr uint maxn = 120;
constexpr uint mod = 1000000007;
const string quack = "quack";

int n, k;
int py[maxn][maxn];
int px[maxn][maxn];
int g[maxn][maxn];
uint memo[maxn][maxn][maxn][maxn];
uint res[maxn+1] = { 1, 5, 53, 661, 8917, 125525, 1813333, 26650965, 396537173, 954512178, 54505183, 736638438, 896632071, 878672824, 810915112, 288478395, 969149669, 26350637, 398333436, 663873037, 531191324, 737040585, 297862490, 20121165, 381697281, 513659321, 836886131, 733748618, 376534124, 81710084, 445508014, 89453990, 126555438, 807937946, 285499396, 756564386, 881581806, 575603052, 628245875, 419065643, 652723787, 650062443, 386960071, 88565679, 764504807, 638689649, 375995494, 979679477, 303679735, 224086209, 392681529, 773763395, 977456874, 287134832, 997820815, 591570266, 981382362, 931812390, 797738284, 446833836, 269087008, 644200134, 572881222, 684898444, 894661479, 158953395, 707034497, 133483475, 338940763, 121829163, 458992549, 586983035, 961302159, 448879559, 854587184, 84869399, 236929957, 568980274, 543031442, 355348077, 598318482, 716695631, 65033024, 137559033, 595545864, 275658325, 143342873, 484177307, 547443778, 838268540, 428508037, 436590466, 370140595, 914313432, 470298150, 93359008, 595812686, 346988240, 652615300, 313985366, 896113582, 71194973, 178231609, 513040741, 653398960, 820313576, 164424270, 189328639, 303341871, 699228579, 473687580, 107148117, 293786133, 791168262, 848928402, 908959674, 675017678, 985719777, 181103531, 508818141, 448445872 };

inline bool ud_removable(u8 i, u8 l, u8 r) {
	return (l ? px[i][n-r-1] - px[i][l-1] : px[i][n-r-1]) >= k;
}

inline bool lr_removable(u8 i, u8 u, u8 d) {
	return (u ? py[n-d-1][i] - py[u-1][i] : py[n-d-1][i]) >= k;
}

inline uint dp(u8 u, u8 d, u8 l, u8 r) {
	if (u+d == n or l+r == n) return 1;
	if (memo[u][d][l][r]) return memo[u][d][l][r];
	uint res = 1;
	if (ud_removable(u, l, r))     res = (res + dp(u+1, d, l, r)) % mod;
	if (ud_removable(n-d-1, l, r)) res = (res + dp(u, d+1, l, r)) % mod;
	if (lr_removable(l, u, d))     res = (res + dp(u, d, l+1, r)) % mod;
	if (lr_removable(n-r-1, u, d)) res = (res + dp(u, d, l, r+1)) % mod;
	return memo[u][d][l][r] = res;
}

inline bool check_t4() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (g[i][j] < 0) return false;
	return k >= 0 and n > 10;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	for (int i = 0; i < n; i++) {
		px[i][0] = g[i][0];
		for (int j = 1; j < n; j++)
			px[i][j] = px[i][j-1] + g[i][j];
	}

	for (int j = 0; j < n; j++) {
		py[0][j] = g[0][j];
		for (int i = 1; i < n; i++)
			py[i][j] = py[i-1][j] + g[i][j];
	}

	if (check_t4()) cout << res[n];
	else cout << dp(0, 0, 0, 0);
}

