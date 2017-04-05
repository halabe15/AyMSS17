#include <iostream>
#include <vector>
#include <string>

class Server;
class Responsability {
private:
  Server* next;

protected:

  Server* getNext(){
    return next;
  }

  virtual int search(std::string dom) = 0;

public:
  void addNext(Server* next){
    this->next = next;
  }

};

class Server : public Responsability {
private:
  std::vector<std::string> domain;
  std::vector<std::string> ips;
  std::string name;
  std::string ip;

  int search(std::string dom) {
    for(int i=0;i<domain.size();i++)
      if(domain.at(i) == dom)
        return i+1;

    return 0;
  }

public:
  Server() = default;
  Server(std::string ip, std::string name) : ip(ip), name(name){}

  void addDomain(std::string d, std::string ip){
    domain.push_back(d);
    ips.push_back(ip);
  }

  std::string lookForDomain(std::string dom, Server* stopSearching){
    int i = search(dom);
    if(i != 0)
      return ips.at(i-1);
    else
      if(getNext() != stopSearching)
        return getNext()->lookForDomain(dom, stopSearching);
      else
        return "No se encontro el dominio";
  }

  void printAll(){
    for(int i=0;i<domain.size();i++){
      std::cout << domain.at(i) << " - ";
      std::cout << ips.at(i) << '\n';
    }
    std::cout  << '\n';
  }

};

int main(){
  Server* A = new Server("A.A.A.A", "A");
  Server* B = new Server("B.B.B.B", "B");
  Server* C = new Server("C.C.C.C", "C");
  Server* D = new Server("D.D.D.D", "D");
  Server* E = new Server("E.E.E.E", "E");

  A->addNext(B);
  B->addNext(C);
  C->addNext(D);
  D->addNext(E);
  E->addNext(A);

  A->addDomain("google.com", "134.12.29.83");
  A->addDomain("facebook.com", "210.92.182.132");

  B->addDomain("twitter.com", "123.121.36.97");
  B->addDomain("amazon.com", "64.211.245.65");

  C->addDomain("drive.google.com", "195.52.14.74");
  C->addDomain("draw.io", "205.150.11.3");

  D->addDomain("apple.com", "10.23.52.180");
  D->addDomain("microsoft.com", "62.31.27.230");

  E->addDomain("forbes.com", "140.197.31.8");
  E->addDomain("cplusplus.com", "18.31.142.230");

  // A->printAll();

  std::string domain;
  std::cout << "Dominio: ";

  while (std::cin >> domain)
     std::cout << A->lookForDomain(domain, A) << "\n\nDominio: ";

}
