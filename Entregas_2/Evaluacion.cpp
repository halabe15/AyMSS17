/*

Evaluacion 2 Parcial

Isaac Halabe
A01021800

halabe15@gmail.com

*/

#include<iostream>

using namespace std;

class Printer;
class Document
{
protected:
    string subject;
public:
    string getSubject(){ return subject; }
    virtual void printOn(Printer*) = 0;
};

class Doc1 : public Document
{
public:
    Doc1(){
        subject = "Texto Simple ";
    }
    void printOn(Printer*);
};

class Doc2 : public Document
{
public:
    Doc2(){
        subject = "Texto con formato de Imagenes ";
    }
    void printOn(Printer*);
};

class Doc3 : public Document
{
public:
    Doc3(){
        subject = "Tarjetas de presentacion ";
    }
    void printOn(Printer*);
};

class Printer
{
public:

    virtual void visit(Doc1*) = 0;
    virtual void visit(Doc2*) = 0;
    virtual void visit(Doc3*) = 0;

    template <class T>
    static T * getSingleton(){
        static T instance;
        return &instance;
      }
};

class Print : public Printer
{
public:
    void visit(Doc1* d){
        cout << "Imprimiendo " << d->getSubject() ;
    }
    void visit(Doc2* d){
        cout << "Imprimiendo " << d->getSubject() ;
    }
    void visit(Doc3* d){
        cout << "Imprimiendo " << d->getSubject() ;
    }
};

class Laser : public Printer
{
public:
    void visit(Doc1*){
        std::cout << "Laser" << '\n';
    }
    void visit(Doc2*){
        std::cout << "Laser" << '\n';
    }
    void visit(Doc3*){
        std::cout << "Laser" << '\n';
    }
};

class Inyeccion : public Printer
{
public:
    void visit(Doc1*){
        std::cout << "Inyeccion" << '\n';
    }
    void visit(Doc2*){
        std::cout << "Inyeccion" << '\n';
    }
    void visit(Doc3*){
        std::cout << "Inyeccion" << '\n';
    }
};

class PDF : public Printer
{
public:
    void visit(Doc1*){
        std::cout << "PDF" << '\n';
    }
    void visit(Doc2*){
        std::cout << "PDF" << '\n';
    }
    void visit(Doc3*){
        std::cout << "PDF" << '\n';
    }
};

class Postscript : public Printer
{
public:
    void visit(Doc1*){
        std::cout << "Postscript" << '\n';
    }
    void visit(Doc2*){
        std::cout << "Postscript" << '\n';
    }
    void visit(Doc3*){
        std::cout << "Postscript" << '\n';
    }
};

class Portatil : public Printer
{
public:
    void visit(Doc1*){
        std::cout << "Portatil" << '\n';
    }
    void visit(Doc2*){
        std::cout << "Portatil" << '\n';
    }
    void visit(Doc3*){
        std::cout << "Portatil" << '\n';
    }
};

void Doc1::printOn(Printer* v)
{
  Print* a = Printer::getSingleton<Print>();
  a->visit(this);
  std::cout << " en ";
  v->visit(this);
}

void Doc2::printOn(Printer* v)
{
  Print* a = Printer::getSingleton<Print>();
  a->visit(this);
  std::cout << " en ";
  v->visit(this);
}

void Doc3::printOn(Printer* v)
{
  Print* a = Printer::getSingleton<Print>();
  a->visit(this);
  std::cout << " en ";
  v->visit(this);
}

class Main
{
public:
  void printAllDocuments(Document** d, int countDocs, Printer** p, int countPrinters){
    for(int i=0;i<countDocs;i++){
      for(int j=0;j<countPrinters;j++)
        d[i]->printOn(p[j]);
      std::cout << '\n';
    }
  }
};

int main()
{
    Main main;

    Printer **inst = Printer::getSingleton<Printer*>();
    Printer **inst2 = Printer::getSingleton<Printer*>();

    Document* d[] ={new Doc1, new Doc2, new Doc3};
    Printer* p[] ={new Laser, new Inyeccion, new PDF, new Postscript, new Portatil};

    std::cout << "Primera Instancia: " <<inst << '\n';
    std::cout << "Segunda instancia: " <<inst2 << "\n\n";

    int countDocs = sizeof(d)/sizeof(Document*);
    int countPrinters = sizeof(p)/sizeof(Printer*);

    main.printAllDocuments(d, countDocs, p, countPrinters);
}
