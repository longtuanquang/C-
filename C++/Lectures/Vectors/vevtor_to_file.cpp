
 #include <iostream>
 #include <fstream>
 #include <string>
 #include <vector>
 using namespace std;
  /*
  *  print_vector(v)
  *    Prints the contents of vector v.
  *    v is a vector holding integers.
  */
 void print_vector(const std::vector<int>& vec) {
     std::cout << "{";
     int len = vec.size();
     if (len > 0) {
        for(int i=0; i<len-1; i++)
            std::cout << vec[i] << ","; // Comma after elements
        std::cout << vec[len - 1]; // No comma after last element 
        }
        std::cout << "}\n";
 }
 /*
  save_vector(filename, v)
  Write the contents of vector v.
  filename is name of text file created.
  */
 void save_vector(const string& filename, const vector<int>& vec){
     // Open a text file for writting
     std::ofstream out(filename);
     if(out.good()){// Make sure the file was opened properly
        int n = vec.size();
        for(int i=0; i < n; i++){
            out << vec[i] << " "; // Space deliminated
        out << '\n';
        }
     } else{
         std::cout << "Unable to save the file\n";
     }
 }
/*
 *  load_vector(filename, v)
 *    Reads the contents of vector v from text file
 *    filename.  v's contents are replaced by the file's
 *    contents.  If the file cannot be found, the vector v
* is empty.
 *    v is a vector holding integers.
 */

void load_vector(const string& filename, std::vector<int> vec){
    // Open a text file for reading
    std::ifstream in(filename);
    if(in.good()){
        vec.clear();
        int value;
        while(in >> value)
            vec.push_back(value);
    } else{
        std::cout << "Unable to load the file\n";
    }
}
int main(){
    int arr[4] = {10, 20, 30, 40};
    vector<int> v2(begin(arr),end(arr));
    print_vector(v2);
}
