#include<iostream>

using namespace std;

class Visitor;
class Number
{
protected:
    string quienSoy;
public:
    string getQuienSoy(){ return quienSoy; }
    virtual void accept(Visitor*) = 0;
};

class Integer : public Number
{
public:
    Integer(){
        quienSoy = "Integer ";
    }
    static int countInts;
    void accept(Visitor*);
};
int Integer::countInts = 0;

class Double : public Number
{
public:
    Double(){
        quienSoy = "Double ";
    }
    static int countDouble;
    void accept(Visitor*);
};
int Double::countDouble = 0;


class Visitor
{
public:
    virtual void visit(Integer*) = 0;
    virtual void visit(Double*) = 0;

    template <class T>
    static T * getSingleton(){
        static T instance;
        return &instance;
      }
};

class PresentVisitor : public Visitor
{
public:
    void visit(Integer* i){
        cout << i->getQuienSoy();
    }
    void visit(Double* d){
        cout << d->getQuienSoy();
    }
};

class CountVisitor : public Visitor
{
public:
    void visit(Integer* i){
        cout << Integer::countInts << '\n';
    }
    void visit(Double* i){
        cout << Double::countDouble << '\n';
    }
};

class AddVisitor : public Visitor
{
public:
    void visit(Integer*){
        Integer::countInts++;
    }
    void visit(Double*){
        Double::countDouble++;
    }
};

void Double::accept(Visitor* v)
{
    v->visit(this);
}

void Integer::accept(Visitor* v)
{
    v->visit(this);
}

int main()
{
    AddVisitor* a = Visitor::getSingleton<AddVisitor>();
    AddVisitor* a2 = Visitor::getSingleton<AddVisitor>();
    CountVisitor* c = Visitor::getSingleton<CountVisitor>();
    CountVisitor* c2 = Visitor::getSingleton<CountVisitor>();
    PresentVisitor* p = Visitor::getSingleton<PresentVisitor>();
    PresentVisitor* p2 = Visitor::getSingleton<PresentVisitor>();
    std::cout << "Primera Instancia: " <<a << '\n';
    std::cout << "Segunda instancia: " <<a2 << "\n\n";
    std::cout << "Primera Instancia: " <<c << '\n';
    std::cout << "Segunda instancia: " <<c2 << "\n\n";
    std::cout << "Primera Instancia: " <<p << '\n';
    std::cout << "Segunda instancia: " <<p2 << "\n\n";

    Number* n[] ={new Integer, new Double};

    for(int i=0; i< 5; i++)
      for (int j = 0; j < 2; j++)
        n[j]->accept(a);

    n[0]->accept(p);
    n[0]->accept(c);
    cout << endl;
    n[1]->accept(p);
    n[1]->accept(c);
}
