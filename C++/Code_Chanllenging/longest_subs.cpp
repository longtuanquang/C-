#include <string>
#include <iostream>
using namespace std;
const int MAX_ROWS = 10;
const int MAX_COLS = 10;

/* list s return the lenght of the longest subsequence */
int longest_sub(int *arr, int n){
	
	//int k = sizeof(arr)/sizeof(arr[0]); 
	// Declare a list to store the length of subsequence
	//printf("length of arr: %d\n", k);
	int lst_subs[n];
	lst_subs[0] = 1;
	int i;
	for (i = 1; i < n; i++){
		lst_subs[i] = 1;
		int j;
		for (j = 0; j < i; j++){
			if(arr[i] > arr[j] && lst_subs[i] < lst_subs[j] + 1){
				lst_subs[i] = lst_subs[j] + 1;
			}
		}
	}
	// Return max of length of subsequences
	int max_subs = 1;
	for (int i = 0; i < n; i++){
		if(lst_subs[i] > max_subs){
			max_subs = lst_subs[i];
		}
	}
	return max_subs;
}
int get_min(int arr[][MAX_COLS], int rows, int cols){
	int min = 100;
    for(int i = 0; i < rows; i ++){
        if (arr[i][0] < min){
            min = arr[i][0];
        }
    }
	return min;
}
int get_min_double_pointers(int (*p)[MAX_ROWS][MAX_COLS], int rows, int cols){
	
}

int main(){
	int lst_test1[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(lst_test1)/sizeof(lst_test1[0]); 
	printf("length of the longest subs is %d\n", longest_sub(lst_test1, n));


	int arr[MAX_ROWS][MAX_COLS] = {
		{-4,3},
		{-2,1},
		{1,0},
		{3,2}
	};

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 2; j++){
			cout << "arr[" << i << "][" << "]:";
			cout << arr[i][j] << endl;
		}
	}
	// Get min using 
	cout << get_min(arr, 4, 2);
	return 0;
}