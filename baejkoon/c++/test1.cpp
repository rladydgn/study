#include <iostream>


void swap(int *a, int *b)
{
	std::cout << a << std::endl;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
	int arr[] = {1, 2};
	swap(arr, arr+1);
	std::cout << arr[0] << arr[1];
}
