#include <iostream>
#include <string>

template <typename T, typename V>
bool less_than(const T& a,const V& b){
    return a < b;
}
int main(){
    std::cout << std::boolalpha;
    std::cout << less_than(2, 3) << '\n';
    std::cout << less_than(2, 2.7) << '\n';
    std::cout << less_than(2.7, 2.2) << '\n';
    std::string word1 = "ABC", word2 = "XYZ";
    std::cout << less_than(word1, word2) << '\n';
    std::cout << less_than(word2, word1) << '\n';
}