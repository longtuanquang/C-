#include <iostream>
using namespace std;
int get_min_x(int **arr, int rows, int cols){
    int min = -10;
    for(int i = 0; i < rows; i ++){
        if (*arr[i][0] < min){
            min = *arr[i][0]
        }
    }
}
int get_max_x(int **arr){

}
int min_total_distance(int **arr,int rows, int cols){

}


int main(){
	int arr[4][2] = {
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
	return 0;

}