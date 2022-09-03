#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int n;
int usable_number[10];
int answer = 9999999;

int pow(int a, int b) {
	int tmp = 1;
	for(int i=1; i<b; i++)
		tmp *= 10;
		
	return tmp*a;
}

void Dfs(int idx, int now) {
	if(idx == 7)
		return;
	
	// ���� ���ڿ��� ���� ���� ���� ���� Ƚ�� 
	int q = idx + abs(n-now);
	if (answer > q) {
		// cout << q << " " << now << endl;
		answer = q;
	}
	else if(now > q)
		return;

	// �� �ڸ��� �÷����� Ȯ�� 
	for(int i=0; i<10; i++) {
		if(usable_number[i] == 0)
			Dfs(idx+1, i*pow(10, idx)+now);
	}
}

int main() {
	cin >> n;
	
	int k;
	cin >> k;
	
	for(int i=0; i<k; i++) {
		int tmp;
		cin >> tmp;
		usable_number[tmp] = 1;
	}
	
	for(int i=0; i<10; i++) {
		if(usable_number[i] == 0)
			Dfs(1, i);
	}
	
	if(abs(n-100) < answer)
		answer = abs(n-100);
		
	cout << answer;
}
