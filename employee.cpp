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
  //attributes
  string Company;
  int Age;

  protected:
  string Name;

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

  virtual void Work() {
    cout << Name << " is checking email, task backlog, performing tasks..." << endl;
  }

};

class Developer: public Employee {
  private:
    string FavProgrammingLanguage;
  
  public:
  void setFPL(string fpl) {
    FavProgrammingLanguage = fpl;
  }

  string getFPL() {
    return FavProgrammingLanguage;
  }

  Developer(string name, string company, int age, string fpl): Employee(name, company, age)
  {
    setFPL(fpl);
  }

  void FixBug() {
    cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;
  }

  void Work() {
    cout << Name << " is writing " << FavProgrammingLanguage << " code." << endl;
  }
};

class Teacher: public Employee {
  private:
  string Subject;

  public:
  void setSubject(string subject){
    Subject = subject;
  }

  string getSubject() {
    return Subject;
  }

  void PrepareLesson() {
    cout << Name << " is preparing " << Subject << " lesson " << endl;
  }

  Teacher(string name, string company, int age, string subject): Employee(name, company, age)
  {
    setSubject(subject);
  }

  void Work() {
    cout << Name << " is teaching " << Subject << "." << endl;
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

  Developer d = Developer("Zoey", "noCompany:(", 21, "C++");
  d.FixBug();
  d.AskForPromotion();

  Teacher t = Teacher("Jack", "Cool School", 35, "History");
  t.PrepareLesson();
  t.AskForPromotion();

  d.Work();
  t.Work();

  Employee* e1 = &d; //base class pointer
  Employee* e2 = &t;

  e1->Work();
  e2->Work();

  return 0;
}