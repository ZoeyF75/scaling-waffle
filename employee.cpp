#include <iostream>
using std::string;
// using namespace std;

class Employee {
  public:
  string Name; //attributes
  string Company;
  int Age;
};

int main ()
{
  Employee employee1;
  employee1.Name = "Saldina";
  employee1.Company = "YT-CodeBeauty";
  employee1.Age = 25;
  return 0;
}