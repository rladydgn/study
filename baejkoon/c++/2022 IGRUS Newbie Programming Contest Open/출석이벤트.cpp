#include <iostream>

using namespace std;

int main() {
	int n, p;
	cin >> n >> p;
	int answer = p;
	if(n >= 5)
		answer -= 500;
	if(n >= 10 && p-(p*(1.0/10)) < answer)
		answer = p-(p*(1.0/10));
	if(n >= 15 && p-2000 < answer)
		answer = p-2000;
	if(n >= 20 && p-(p*(2.5/10)) < answer)
		answer = p-(p*(2.5/10));
	
	if(answer<0)
		cout << 0;
	else
		cout << answer;
}
