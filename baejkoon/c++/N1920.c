#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

# define MAX_SIZE 100001
int sorted[MAX_SIZE];

void quicksort(int *number,int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(void) {

    int i,num, num2;
    int array[100001], array2[100001];
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d", &array[i]);
    }
    quicksort(array, 0, num-1);
    scanf("%d", &num2);
    for (i = 0; i < num2; i++) {
        scanf("%d", &array2[i]);
    }
    int left = 0;
    int right = num - 1;
    i = 0;
    for(int i=0; i<num2; i++) {
		int min = 0;
		int max = num-1;
		while(1) {
			int idx = (min+max)/2;
			//cout << "idx :" << idx << " min :" << min << " max :" << max << endl;
			if(array2[i] == array[idx]) {
				printf("1\n");
				break;
			}
			else if(array2[i] > array[idx])
				min = idx+1;
			else
				max = idx-1;

			if(min>max) {
				printf("0\n");
				break;
			}
		}
	}
    return 0;
}
