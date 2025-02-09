#include <iostream>
#include <string>
#include <deque>
using namespace std;

// 굳이 deque 안쓰고 그냥 앞뒤 인덱스를 늘려주는 방식으로 해결가능함. 
deque<int> Get_array(string s) {
	deque<int> arr;
	
	string tmp = "";
	
	// [] 인 경우 
	if(s.size() == 2)
		return arr;
	
	for(unsigned int i=0; i<s.size(); i++) {
		if(s[i] == ',') {
			arr.push_back(stoi(tmp));
			tmp = "";
		}
		else if(s[i] >= '0' && s[i] <= '9')
			tmp += s[i]; 
	}
	if(!tmp.empty())
		arr.push_back(stoi(tmp));
	
	// cout << "arr" << arr.size() << endl;
	return arr;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	
	for(int i=0; i<T; i++) {
		string func, tmp;
		int cnt;
		cin >> func >> cnt;
		cin >> tmp;
		deque<int> arr = Get_array(tmp);
		
		bool tf = false;
		bool check = false;
		for(unsigned int j=0; j<func.size(); j++) {
			if(func[j] == 'R') {
				tf = !tf;
			}
			
			else {
				if(arr.empty()) {
					cout << "error" << "\n";
					check = true;
					break;
				}
				else if(tf) {
					arr.pop_back();
				}
				else {
					arr.pop_front();
				}
			}
		}
		
		string answer = "[";
		if(!arr.empty()) {
			if(tf) {
				for(int j=arr.size()-1; j>=0; j--) {
					answer += to_string(arr[j]) + ",";
				}
			}
			else {
				for(int j=0; j<arr.size(); j++) {
					answer += to_string(arr[j]) + ",";
				}
			}
			answer[answer.size()-1] = ']';
			cout << answer << "\n";
		}
		
		if(arr.empty() && !check)
			cout << "[]" << "\n";
	}
}
