#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int values[8001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	
	double sum = 0;
	int total_numbers = 0;
	int many = 0;
	
	int max_ = -9999;
	int min_ = 9999;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;

		values[4000+tmp]++;
		
		if(values[4000+tmp] > many)
			many = values[4000+tmp];
			
		sum += tmp;
		
		if(max_ < tmp)
			max_ = tmp;
		if(min_ > tmp)
			min_ = tmp;
	}
	
	int avg = round(sum/n);
	cout << avg << "\n";
	
	set<int> s;
	int cnt = 0, tf = 0;
	for(int i=0; i<8001; i++) {
		if(values[i] == many)
			s.insert(i-4000);
			
		if(values[i] > 0)
			cnt += values[i];
			
		if(!tf && cnt >= n/2+1) {
			cout << i - 4000 << "\n";
			tf = 1;
		}
	}
	
	auto iter = s.begin();
	if(s.size() != 1)
		iter++;
	cout << *iter << "\n";
	cout << max_-min_;
}
