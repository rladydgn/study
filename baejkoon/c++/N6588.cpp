#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int prime[1000001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> vPrime;

    for(int i=2; i<=1000; i++) {
        int k = 2;
        if(prime[i] == 0) {
            while(i*k <= 1000000) {
                prime[i*k] = 1;
                k++;
            }
        }
    }

    for(int i=2; i<1000001; i++) {
        if(prime[i] == 0)
            vPrime.push_back(i);
    }

    int n;
    cin >> n;
    while(n != 0) {
        for(int i=0; i<vPrime.size(); i++) {
            if(vPrime[i] > n/2) {
                cout << "Goldbach's conjecture is wrong." << "\n";
                break;
            }
            if(prime[n-vPrime[i]] == 0) {
                cout << n << " = " << vPrime[i] << " + " << n-vPrime[i] << "\n";
                break;
            }
        }
        cin >> n;
    }
    return 0;
}