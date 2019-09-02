#include <iostream>
#include <vector>
#include <string.h> 
#include <sstream>
using namespace std;

// public, private, protected inheritance

/* Access control
1. None of the derived classes can access members that is private in B
2. D_pub inherits public members in B as public and protected members in B as protected
3. D_priv inherits public members and protected members in B as private
4. D_prot inherits public members and protected members in B as protected
*/


class B{
    public:
        void f_pub(){ cout << "f_pub is called.\n";}
    protected:
        void f_prot(){cout << "f_prot is called \n";}
    private:
        void f_priv(){cout << "f_priv is called \n";}


};
class D_pub: public B {
    public:
        void f(){
            f_pub(); //Ok. D_pub's public function
            f_prot(); //Ok.
            f_priv(); // Not ok 
        }
};
class D_prot: protected B {
    public:
    //using B::f_pub;
        void f(){
            f_pub(); //Ok. become D_pub's protected function
            f_prot(); //Ok.become D_pub's protected function
            f_priv(); // Not ok 
        }
};
class D_priv: private B {
    public:
        void f(){
            f_pub(); //Ok. become D_pub's private function
            f_prot(); //Ok.become D_pub's private function
            f_priv(); // Not ok 
        }
};
int main(){
    D_pub d1;
    d1.f_pub(); // Ok
    D_prot d2;
    d2.f_pub(); // Error because
    B* pB = &d1; // ok . casting D_pub* to B*
    pB = &d2; // d2 has-a-relation

}

/*
Casting:
1. Anyone can cast a D_pub* to B*. D_pub is a special kind of B
2. D_priv's members and friends can cast D_priv* to B*
3. D_prot's memebers, friends, and child can cast D_prot* to B*
 */
/*
CONCLUSION:
public inheritance: IS-A RELATIONSHIP, e.g d_pub is a kind of B
private inheritance: HAS-A RELATIONSHIP, e.g 
 */