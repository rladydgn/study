#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int* ptr = (int*)malloc(sizeof(int));
    ptr[0] = 1;
    cout << *ptr << " " << ptr << endl;
    free(ptr);
    cout << *ptr << " " << ptr;
}