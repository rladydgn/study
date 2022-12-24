#include <iostream>

using namespace std;

int Y, M, D;

// 0 - 유효하지 않음, 1 - 올바른 날짜, 2 - 유통기한 초과 
int CheckValid(int y, int m, int d) {
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		if(d <= 31 && d > 0) {
			if(y > Y || (y == Y && m > M) || (y == Y && m == M && d >= D))
				return 1;
			return 2;
		}
	}
	else if(m == 4 || m == 6 || m == 9 || m == 11) {
		if(d <= 30 && d > 0) {
			if(y > Y || (y == Y && m > M) || (y == Y && m == M && d >= D))
				return 1;
			return 2;
		}
	}
	else if(m == 2 && y%4 == 0) {
		if(d <= 29 && d > 0) {
			if(y > Y || (y == Y && m > M) || (y == Y && m == M && d >= D))
				return 1;
			return 2;
		}
	}
	else if(m == 2) {
		if(d <= 28 && d > 0) {
			if(y > Y || (y == Y && m > M) || (y == Y && m == M && d >= D))
				return 1;
			return 2;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Y >> M >> D;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int arr[3];
		arr[0] = CheckValid(a, b, c);
		arr[1] = CheckValid(c, b, a);
		arr[2] = CheckValid(b, c, a);
		
		// cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
		if(arr[0] == 1 && arr[1] == 0 && arr[2] == 0) {
			cout << "safe";
		}
		else if(arr[0] == 0 && arr[1] == 1 && arr[2] == 0) {
			cout << "safe";
		}
		else if(arr[0] == 0 && arr[1] == 0 && arr[2] == 1) {
			cout << "safe";
		}
		else if(arr[0] == 1 && arr[1] == 1 && arr[2] == 0) {
			cout << "safe";
		}
		else if(arr[0] == 1 && arr[1] == 0 && arr[2] == 1) {
			cout << "safe";
		}
		else if(arr[0] == 0 && arr[1] == 1 && arr[2] == 1) {
			cout << "safe";
		}
		else if(arr[0] == 1 && arr[1] == 1 && arr[2] == 1) {
			cout << "safe";
		}
		else if(!arr[0] && !arr[1] && !arr[2]) {
			cout << "invalid";
		}
		else {
			cout << "unsafe";
		}
		cout << "\n";
	}
	return 0;
}
