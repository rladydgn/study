#include <iostream>
using namespace std;

unsigned int heap[100002];

void hifi(int k, int size){
	int l = k*2;
	int r = k*2+1;
	unsigned int maxi = heap[k];
	int idx;
	
	if(l > size)
		return;
	
	if(heap[l] > maxi) {
		maxi = heap[l];
		idx = l;
	}
	
	if(r <= size) {
		if(heap[r] > maxi) {
			maxi = heap[r];
			idx = r;
		}
	}
		
	if(maxi != heap[k]) {
		heap[idx] = heap[k];
		heap[k] = maxi;
		hifi(idx, size);
	}
	return;
}

void checkHeap(int k) {
	if(k <= 1)
		return;
	if(heap[k] > heap[k/2]) {
		int tmp = heap[k/2];
		heap[k/2] = heap[k];
		heap[k] = tmp;
		checkHeap(k/2);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	int size = 0;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int m;
		cin >> m;
		
		if(m == 0 && size == 0)
			cout << 0 << "\n";
			
		else if(m == 0) {
			cout << heap[1] << "\n";
			heap[1] = heap[size];
			heap[size] = 0;
			hifi(1, --size);
		}
		
		else {
			heap[++size] = m;
			checkHeap(size);
		}
	}
	
}
