#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string s[n];
	
	for(int i=0; i<n; i++)
		cin >> s[i];
		
	string answer = "";
	int cnt = 0;
	// A C G T
	int dna[4] = {0, 0, 0, 0};
	// 각 문자열중 가장 많이 등장하는 수를 dna로 결정. 
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(s[j][i] == 'A')
				dna[0]++;
			else if(s[j][i] == 'C')
				dna[1]++;
			else if(s[j][i] == 'G')
				dna[2]++;
			else
				dna[3]++;
		}
		if(dna[0] >= dna[1] && dna[0] >= dna[2] && dna[0] >= dna[3]) {
			answer += "A";
			cnt += dna[1] + dna[2] + dna[3];
		}
		else if(dna[1] > dna[0] && dna[1] >= dna[2] && dna[1] >= dna[3]) {
			answer += "C";
			cnt += dna[0] + dna[2] + dna[3];
		}
		else if(dna[2] > dna[0] && dna[2] > dna[1] && dna[2] >= dna[3]) {
			answer += "G";
			cnt += dna[0] + dna[1] + dna[3];
		}
		else {
			answer += "T";
			cnt += dna[0] + dna[1] + dna[2];
		}
			
		for(int l=0; l<4; l++)
			dna[l] = 0;
	}
	
	cout << answer << "\n" << cnt;
}
