#include <iostream>
using namespace std;

int p[2187][2187];
int a, b, c;

void dc(int start_row, int start_col, int end_row, int end_col) {
	int k = (end_row-start_row) / 3;
	int t = p[start_row][start_col];
	for(int i=start_row; i<end_row; i++) {
		for(int j=start_col; j<end_col; j++) {
			if(t != p[i][j]) {
				for(int r=0; r<3; r++) {
					for(int c=0; c<3; c++) {
						dc(start_row + r * k, start_col + c * k, start_row + (r+1) * k, start_col + (c+1) * k);
					}
				}
				return;
			}
		}
	}
	if(t==-1) a++;
	if(t==0) b++;
	if(t==1) c++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			cin >> p[i][j];
	}
	dc(0, 0, n, n);

	cout << a << "\n" << b << "\n" << c;
	return 0;
}
