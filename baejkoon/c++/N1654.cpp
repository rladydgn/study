#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int K, N;
	cin >> K >> N;
	int lan[K];
	
	for(int i=0; i<K; i++)
		cin >> lan[i];
		
	unsigned int min = 0;
	unsigned int max = 2147483647;
	unsigned int mid = (min+max)/2;
	unsigned int answer = 0;
	while(min <= max) {
		int len = 0;
		for(int i=0; i<K; i++) {
			len += lan[i]/mid;
		}
		if(len < N)
			max = mid-1;
		else {
			min = mid+1;
			answer = mid;
		}
			
		mid = (min+max)/2;
		//cout << min << " " << mid << " " << max << endl;
	}
	cout << answer;
}
