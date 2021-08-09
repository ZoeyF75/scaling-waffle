#include <iostream>
// using std::string;
using namespace std;

bool digitCheck(string s) {
  return std::any_of(s.begin(), s.end(), ::isdigit);
}

class iEmployee { //interface
  virtual void AskForPromotion() = 0; //pure, virtual function or abstract function
};


class Employee:iEmployee {
  private: //not required as its priv by default
  string Name; //attributes
  string Company;
  int Age;

  public:
  void setName(string name) {
    if (!digitCheck(name)) {
       Name = name;
    }
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
    if (age >= 18) {
      Age = age;
    }
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

  void AskForPromotion() {
    if (Age > 30) {
      cout << Name << " got promoted!" << endl;
    } else {
      cout << Name << " got promoted to customer." << endl;
    }
  }

};

int main ()
{
  Employee employee1 = Employee("Saldina", "YT-CodeBeauty", 25);
  employee1.IntroduceYourself();

  Employee employee2 = Employee("John", "Amazon", 35);
  employee2.IntroduceYourself();

  employee2.setAge(17);
  employee2.setName("A3g");

  employee1.AskForPromotion();
  employee2.AskForPromotion();

  cout << employee2.getName() << " is " << employee2.getAge() << " years old." << endl;
  return 0;
}