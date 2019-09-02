#include <iostream>
#include <cmath>
#include "tester.h"
#include <vector>
using namespace std;

Tester::Tester(): error_count(0), total_count(0) {
     std::cout << "+---------------------------------------\n";
     std::cout << "|  Testing \n";
     std::cout << "+---------------------------------------\n";
}

bool Tester::equals(double d1, double d2,double tolerance) const{
    return d1 == d2 || abs(d1 - d2) < tolerance;
}

// Prints the contents of a vector of integers
void Tester::print_vector(const std::vector<int>& vec){
    std::cout << '{';
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << ', ';
    }
    std::cout << '}';
}
// Compare integer outcomes
void Tester::check_equals(const std::string& msg, int expected, int actual){
    std::cout << "[" << msg << "] ";
    total_count++; // Count this test
    if(expected == actual)
        std::cout << "OK\n";
    else{
        error_count++;
        std::cout << "Failed";
    
    }
}

//Compare double_precision 
void Tester::check_equals(const std::string& msg, double expected, double actual, double tolerance){
    std::cout << "[" << msg << "] ";
    total_count++; // Count this test
    if (equals(expected, actual, tolerance))
        std::cout << "OK\n";
    else {
        error_count++; // Count this failed test 
        std::cout << "*** Failed! Expected: " << expected
                << ", actual: " << actual << '\n';
    }
}
// Compare vector outcome
void Tester::check_equals(const std::string& msg, const std::vector<int>& expected, const std::vector<int>& actual){
    std::cout << "[" << msg << "] ";
    total_count++; // Count this test
    if (expected == actual)
         std::cout << "OK\n";
    else {
        error_count++; // Count this failed test 
        std::cout << "*** Failed! Expected: "; print_vector(expected);
        std::cout << " Actual: "; print_vector(actual);
        std::cout << '\n';
     }
}
// Display final test statistics
 void Tester::report_results() const {
     std::cout << "+--------------------------------------\n";
     std::cout << "| " << total_count << " tests run, "
               << total_count - error_count << " passed, "
               << error_count << " failed\n";
     std::cout << "+--------------------------------------\n";
}
