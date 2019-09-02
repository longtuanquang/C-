#include <iostream>
#include <vector>
#include "tester.h"
#include<numeric>
using namespace std;

// sort has a bug (it does not do anything)
void sort(const std::vector<int>& vec){

}

// sum has a bug (misses first element)
 int sum(const std::vector<int>& vec) {
     int total = 0;
     for (size_t i = 1; i < vec.size(); i++)
         total += vec[i];
     return total;
 }

 int main(){
     Tester t; // Declare a test object
     // Some test case for sort
     int arr[3] = {3,4,2};
     std::vector<int> v(begin(arr),end(arr));
     int expected_arr[3] = {2,3,4};
     vector<int> expected_v(begin(expected_arr),end(expected_arr));

     sort(v);
     t.check_equals("Sort test #1: ", expected_v, v); 
     //v = {2, 3, 4};
     //sort(v);
     //t.check_equals("Sort test #2: ",{2,3,4}, v);
     // Some test case for sum
     int arr_sum[3] = {1,3,4};
     vector<int> v_sum(begin(arr_sum),end(arr_sum));
     int sum = accumulate(v_sum.begin(), v_sum.end(),0);
     t.check_equals("Test sum #1: ",sum, 8);
 }