#include <iostream>
#include <cmath>
#include<stdio.h>
using namespace std;

// Helper function to return the max of two integer
int max(int a, int b){
    return  (a > b) ? a : b;
}
unsigned knap_sack(int W, int wt[], int val[], int n){
    // Create an two-dimensional array to store the max value
    int K[n+1][W+1];
    for(int i = 0; i < n +1; i++){
        for(int w = 0; w < W; w++){
            if(i == 0 || w == 0){
                K[i][w] = 0;
            }
            else if ( wt[i-1] <= w){
                int temp1 = K[i-1][w-wt[i-1]] + val[i-1]; // include item i
                int temp2 = K[i-1][w]; // not include item i
                K[i][w] = max(temp1, temp2);
            } else
            {
                K[i][w] = K[i-1][w]; // not include item i
            }
            printf("K at i and w: %d ", K[i][w]);
            cout << endl;
            
        }
       
    }
    return K[n][W];
}
int main(){
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30}; 
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("Knapsack is: %d", knap_sack(W, wt, val, n));
    return 0;
}