#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

using Matrix = std::vector<std::vector<double> >; // define type alias, in C, we use typedef

// Allow users entering the elements of Matrix
void populate_matrix(Matrix& m){
    std::cout << "Enter the " << m.size() << " rows of the matrix.\n";
    for(unsigned row = 0; row < m.size(); row++){
        std::cout << "Row #" << row << " (enter " << m[row].size() << " values):";
          for(double& d: m[row]) {
              std::cin >> d;
          }
    }
}

void print_matrix(const Matrix& m){
    for(auto row: m){
        for(double elem: row){
             std::cout << std::setw(5) << elem;
        }
         std::cout << '\n';
    }
}

int main() {
    int rows, columns;
    std::cout << "How many rows? ";
    std::cin >> rows;
    std::cout << "How many columns? ";
    std::cin >> columns;
    // Declare the 2D vector
    Matrix mat(rows, std::vector<double>(columns)); // Populate the vector
    populate_matrix(mat);
    // Print the vector
    print_matrix(mat);
}