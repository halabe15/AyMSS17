/*

    The problem is that function foo returns a reference to a local variable
    which is automatically deallocated when function returns
    
    This problem is not discovered with Valgrind, but is a serious problem

*/

int* foo(int& value)
{
    int val = value;
    return &val;
}

int main()
{
    int a = 5;
    int * p;
    int b = 10;
    
    p = foo(10);
    
    *p += 10;
}