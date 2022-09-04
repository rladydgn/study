#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		int tree[tmp+1];
		
		for(int j=0; j<=tmp; j++)
			tree[j] = 0;
			
		for(int j=0; j<tmp-1; j++) {
			int a, b;
			cin >> a >> b;
			tree[b] = a;
		}
		
		
		vector<int> f1, f2;
		int a, b;
		cin >> a >> b;
		
		f1.push_back(a);
		while(true) {
			int k = tree[a];
			a = k;
			if(k==0)
				break;
			f1.push_back(k);
		}
		
		f2.push_back(b);
		while(true) {
			int k = tree[b];
			b = k;
			if(k==0)
				break;
			f2.push_back(k);
		}
		
		int tf = 0;
		for(int j=0; j<f1.size(); j++) {
			for(int k=0; k<f2.size(); k++) {
				if(f1[j] == f2[k]) {
					cout << f1[j] << "\n";
					tf = 1;
					break;
				}
			}
			if(tf)
				break;
		}
	}
}
