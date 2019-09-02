#ifndef TESTER_H
#define TESTER_H
#include <vector>
#include <string>

using namespace std;


class Tester {
    int error_count; // Number of errors detected
    int total_count; // Numnber of tests executed
    // Determines if double-precision floating-point
    // values d1 and d2 are 'equal'
    // Return true id their difference is less than tolerance
    bool equals(double d1, double d2, double tolerance) const;

    // Display vector a in human-readable form
    void print_vector(const std::vector<int>& a);
    
    public:
    // Initilizes a Tester object
    Tester();

    //Determines if an expected integer result (expected)
    // matches the actual result (actual). msg is the message
    // that describes the test.
    void check_equals(const std::string& msg, int expected, int actual);

    //Determines if an expected double result (expected)
    // matches the actual result (actual). msg is the message
    // that describes the test.
    void check_equals(const std::string& msg, double expected, double actual, double tolerance);

    // Compare two strings
    void check_equals(const std::string& msg, const vector<int>& vec1, const vector<int>& vec2);

    void report_results() const;

};
#endif;



