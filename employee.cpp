#include <iostream>
// using std::string;
using namespace std;

class Employee {
  private: //not required as its priv by default
  string Name; //attributes
  string Company;
  int Age;

  public:
  void setName(string name) {
    Name = name;
  }

  string getName() {
    return Name;
  }

  void setCompany(string company) {
    Company = company;
  }

  string getCompany() {
    return Company;
  }

  void setAge(int age) {
    Age = age;
  }

  int getAge() {
    return Age;
  }

  void IntroduceYourself() {
    cout<<"Name - " << Name << endl;
    cout<<"Company - " << Company << endl;
    cout<<"Age - " << Age << endl;
  }

  //constructor
  Employee(string name, string company, int age) {
    Name = name;
    Company = company;
    Age = age;
  }
};

int main ()
{
  Employee employee1 = Employee("Saldina", "YT-CodeBeauty", 25);
  employee1.IntroduceYourself();

  Employee employee2 = Employee("John", "Amazon", 35);
  employee2.IntroduceYourself();

  return 0;
}