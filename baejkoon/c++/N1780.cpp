#include <iostream>
using namespace std;

int p[128][128];
int a=0, b=0;

void dq(int xStart, int xEnd, int yStart, int yEnd) {
	int tmp = p[yStart][xStart];
	//cout << xStart << " " << xEnd << " " << yStart << " " << yEnd << endl;
	for(int i=yStart; i<yEnd; i++) {
		for(int j=xStart; j<xEnd; j++) {
			if(p[i][j] != tmp) {
				dq(xStart, (xStart+xEnd)/2, yStart, (yStart+yEnd)/2);
				dq(xStart, (xStart+xEnd)/2, (yStart+yEnd)/2, yEnd);
				dq((xStart+xEnd)/2, xEnd, yStart, (yStart+yEnd)/2);
				dq((xStart+xEnd)/2, xEnd, (yStart+yEnd)/2, yEnd);
				return;
			}
		}
	}
	if(tmp == 0)
		a++;
	else
		b++;
	
	return;
}

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> p[i][j];
		}
	}

	dq(0, n, 0, n);
	
	cout << a << " " << b;
}
