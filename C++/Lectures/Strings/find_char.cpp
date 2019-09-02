#include <iostream>

bool find_char(const char* text, char ch){
    while( *text != '\0') {
        if( *text == ch){
            return true;
        } else{
            text++;
        }
    }
    return false;
}
int main(){
    const char* phrase = "this is a phrase!";
    // Try all characters a through d
    for(char ch = 'a'; ch <= 'd'; ch++){
        std::cout << '\'' << ch << '\''<< " is ";
        if (!find_char(phrase, ch))
            std::cout << "NOT ";
        std::cout << "in " << '\"' << phrase << '\"' << '\n';
    }
}