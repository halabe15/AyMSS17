/* 

    Memory leak
    
    Dinamically allocated mem for newMem, was never freed
    
*/

int* foo(int value)
{
    int* newMem = new int(value);
    return newMem;
}

int main()
{
    foo(10);
}