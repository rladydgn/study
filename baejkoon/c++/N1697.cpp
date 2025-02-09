#include <iostream>
using namespace std;

int a[100001];

void dp(int N, int K, int count) {
	cout << "N: " << N << " count: " << count << endl;
	if(N == K) {
		if(count<a[N])
			a[N] = count;
		//cout << count << endl;
		return;
	}
	if(N > 100000 || N < 0)
		return;
		
	if(a[K]<=count || a[N]<= count)
		return;
	
	a[N] = count;
	count++;
	if(N>K) {
		dp(N-1, K, count);
	}
	else if(N==0) {
		dp(N+1, K, count);
	}
	else {
		dp(N-1, K, count);
		dp(N+1, K, count);
		dp(N*2, K, count);
	}
} 

int main() {
	int N, K;
	cin >> N >> K;
	for(int i=0; i<100001; i++) {
		a[i] = 999999;
	}
	dp(N, K, 0);
	cout << a[K];
}
