class Object
{
public:
    int* value;
    Object(){value = new int;}
    ~Object()
    {
        delete value;
    }
};

int main()
{
    Object** array = new Object*[10];
    array[0] = new Object;
 
    delete [] array;
}