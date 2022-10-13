#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, L, K;
	cin >> N >> L >> K;
	int arr[N+1];
	for(int i=1; i<=N; i++)
		cin >> arr[i];
		
	int mylab = arr[L];
	sort(arr+L, arr+N+1);
	int idx = 0;
	int answer = 0;
	
	if(mylab == arr[L])
		idx++;
	
	for(int i=L+1; i<=N; i++) {
		if(arr[i] < mylab)
			continue;
		else if(arr[i] == mylab)
			idx = 1;
		else if(arr[i] != arr[i-1] && arr[i] > mylab) {
			idx++;
		}
		if(idx > K) {
			answer = N-i+1;
			break;
		}
		// cout << idx << endl;
	}
	
	for(int i=1; i<L; i++) {
		if(arr[i] > mylab)
			answer++;
	}
	
	if(idx < K)
		cout << -1;
	else
		cout << answer;
}
