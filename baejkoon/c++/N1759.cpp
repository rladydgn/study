#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int L, C;

// a는 자음, b는 모음 개수 
void func(char *c, int idx, int count, string s, int a, int b) {
	s += c[idx];
	count++;
	if(c[idx] == 'a' || c[idx] == 'e' || c[idx] == 'i' || c[idx] == 'o' || c[idx] == 'u')
		a++;
	else
		b++;
	if(count == L) {
		if(a>=1 && b>=2)
			cout << s << endl;
		return;
	}
	for(int i=idx+1; i<=C-(L-count); i++)
		func(c, i, count, s, a, b);
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> L >> C;
	char c[C];
	for(int i=0; i<C; i++)
		cin >> c[i];
	
	sort(c, c+C);
	for(int i=0; i<=C-L; i++) {
		func(c, i, 0, "", 0, 0);
	}
}
