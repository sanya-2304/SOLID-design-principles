// Employee Payment System

#include<bits/stdc++.h>
using namespace std;

class Trainee {
    public:
    virtual void progress()=0;

};

class Employee :public Trainee{
    public:
    virtual void calculatePay()=0;
};


class FullTimeEmployee: public Employee{
public:
    void calculatePay() override{
    cout<<"FullTimeEmployee gets MONTHLY salary."<<endl;
    };
    void progress() override {
        cout << "FullTimeEmployee is progressing in full-time role." << endl;
    }
};

class Contractor: public Employee{
public:
    void calculatePay() override{
    cout<<"Contractor gets PROJECT based cost."<<endl;
    }
    void progress() override {
        cout << "Contractor is progressing on project basis." << endl;
    }
    
};

class PartTimeEmployee: public Employee{
public:
    void calculatePay() override{
    cout<<"PartTimeEmployee gets HOURLY salary."<<endl;
    }
    void progress() override {
        cout << "PartTimeEmployee is learning and working part-time." << endl;
    }
};
class Intern: public Trainee{
public:
    void progress() override{
        //  throw runtime_error("Interns are unpaid. Cannot calculate pay.");
        //  Intern breaks LSP by not behaving like a proper Employee.   
         cout<<"Interns are unpaid. Cannot calculate pay."<<endl;
    }
};

class  Apprentice: public Trainee{
    public :
    void progress() override{
        cout<<"Apprentice log learning phase vich hain."<<endl;
    }
};

int main(){
     vector<Employee*> employees;
     employees.push_back(new FullTimeEmployee());
    employees.push_back(new Contractor());
    employees.push_back(new PartTimeEmployee());
    //   employees.push_back(new Intern());

     vector<Trainee*> trainees;
    trainees.push_back(new Intern());
trainees.push_back(new Apprentice());
      cout << "Calculating Pay for all employees: "<<endl;
      for(auto emp: employees){
        try{
            emp->calculatePay();
        }catch(exception &e){
            cerr<<"Error: "<<endl;
            cerr<<e.what()<<endl;
        }
      }
       // Clean up
    for (auto emp : employees) {
        delete emp;
    }

     cout << "\nProgress of trainees:\n";
    for (auto trainee : trainees) {
            trainee->progress();  // Intern will throw here
    }
    for (auto trainee : trainees) delete trainee;
    return 0;
}