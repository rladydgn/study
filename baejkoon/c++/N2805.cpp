#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, m;
	cin >> n >> m;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
		
	long long int min_ = 0;
	long long int max_ = 1000000000;
	// m미터보다 길 경우 저장용 
	long long int answer = 0;
	
	while(min_ <= max_) {
		long long int middle = (min_ + max_) / 2;
		long long int sum = 0;
		for(int i=0; i<n; i++) {
			if(arr[i] - middle > 0) {
				sum += arr[i] - middle;
			}
		}
		if(sum == m) {
			cout << middle;
			return 0;
		}
		if(sum < m) {
			max_ = middle - 1;
		}
		else if(sum > m) {
			answer = middle;
			min_ = middle + 1;
		}
	}
	cout << answer;
	
	return 0;
}
