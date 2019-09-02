#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

int get_X_min(int arr[][MAX_COLS], int rows, int cols){
	int min = std::numeric_limits<int>::max();
    for(int i = 0; i < rows; i ++){
        if (arr[i][0] < min){
            min = arr[i][0];
        }
    }
	return min;
}
int get_X_max(int arr[][MAX_COLS], int rows, int cols){
	int max = -std::numeric_limits<int>::max();
    for(int i = 0; i < rows; i ++){
        if (arr[i][0] > max){
            max = arr[i][0];
        }
    }
	return max;
}
int get_Y_min(int arr[][MAX_COLS], int rows, int cols){
	int min = std::numeric_limits<int>::max();
    for(int i = 0; i < rows; i ++){
        if (arr[i][1] < min){
            min = arr[i][1];
        }
    }
	return min;
}
int get_Y_max(int arr[][MAX_COLS], int rows, int cols){
	int max = -std::numeric_limits<int>::max();
    for(int i = 0; i < rows; i ++){
        if (arr[i][1] > max){
            max = arr[i][1];
        }
    }
	return max;
}
int total_dist(int arr[][MAX_COLS], int rows, int cols, int X_meeting,int Y_meeting){
    int sum = 0;
    for(int i = 0; i < rows; i++){
        cout << "arr[i][0]: " << arr[i][0] << " arr[i][1]: " << arr[i][1] ; 
        cout << " sum is: " << abs(arr[i][0] - X_meeting) + abs(arr[i][1] - Y_meeting) << endl;
        sum += abs(arr[i][0] - X_meeting) + abs(arr[i][1] - Y_meeting);
        
    }
    return sum;
}

int get_min_double_pointers(int (*arr)[MAX_ROWS][MAX_COLS], int rows, int cols){
	int min = std::numeric_limits<int>::max();
    for(int i = 0; i < rows; i ++){
        if ((*arr)[i][0] < min){
            min = (*arr)[i][0];
        }
    }
	return min;
}

int main(){
	int arr[MAX_ROWS][MAX_COLS] = {
		{-4,3},
		{-2,1},
		{1,0},
		{3,2}
	};
    int ninf = - std::numeric_limits<int>::max();
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 2; j++){
			cout << "arr[" << i << "][" << "]:";
			cout << arr[i][j] << endl;
		}
	}
	// Get X_min  
    int X_min = get_X_min(arr, 4, 2);
	cout << "Get X_min : " << X_min << endl;
    // Get X_max 
    int X_max = get_X_max(arr, 4, 2);
    cout << "Get X_max: " << X_max << endl;

   // Get Y_min 
    int Y_min = get_Y_min(arr, 4, 2);
    cout << "Get Y_min: " << Y_min << endl;

    // Get Y_max 
    int Y_max = get_Y_max(arr,4,2);
    cout << "Get Y_max: " << Y_max << endl;

    //Build an double array from with rows = Y_max - Y_min + 1, cols = X_max - X_min + 1 
    int grid[Y_max-Y_min + 1][X_max-X_min + 1];
    for(int i = Y_min; i < Y_max + 1; i++){
        for(int j = X_min; j < X_max + 1; j++){
            grid[i][j] = total_dist(arr, 4, 2, i, j);
            cout << "At " << i << "and " << j << "total distance is: " << grid[i][j] << endl;
        }
    }

    //int (*p)[MAX_ROWS][MAX_COLS] = &arr;
    //cout << "Get min with 2nd method: " << get_min_double_pointers(p, 4, 2);

	return 0;
}