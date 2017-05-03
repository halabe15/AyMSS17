/*

    INVALID FREES

    Destructor of Child is called twince (for a and b instances), but
    as default copy constructor is used, no new instance of p is creeated
    thus no delete is needed

    Solution:
    in destructor ask wheter the pointer is allocated, then free

    I performed it usig mcheck and mprobe, but those libraries are good onl for debugging
    purposes.

    //put the following function before main

        void no_op(enum mcheck_status status) {}

    // in main, the first line must be

        mcheck(&no_op);

    // in destructor of child

        ~Child()
        {
            if(mprobe(p) != MCHECK_FREE)
            {
                delete p;
                p = NULL;
            }
        }

    Listoooo

    The right way to do it is implementing copi constructor with deep copi then there are 2 instances of p and no double
    free is performed

*/

#include<iostream>

using namespace std;

class Child
{
public:
    int* p;
    Child()
    {
        p = new int;
    }
    ~Child()
    {
        delete p;
        p = NULL;
    }
};

int main()
{
    Child a;
    Child b = a;

    *(a.p) = 5;

    cout << *(b.p);

}
