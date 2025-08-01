// Employee Payment System

#include<bits/stdc++.h>
using namespace std;

class Employee {
    public:
    virtual void calculatePay()=0;
};


class FullTimeEmployee: public Employee{
public:
    void calculatePay() override{
    cout<<"FullTimeEmployee gets MONTHLY salary."<<endl;
    };
};

class Contractor: public Employee{
public:
    void calculatePay() override{
    cout<<"Contractor gets PROJECT based cost."<<endl;
    };
};

class PartTimeEmployee: public Employee{
public:
    void calculatePay() override{
    cout<<"PartTimeEmployee gets HOURLY salary."<<endl;
    };
};

int main(){
     vector<Employee*> employees;
     employees.push_back(new FullTimeEmployee());
    employees.push_back(new Contractor());
    employees.push_back(new PartTimeEmployee());
      cout << "Calculating Pay for all employees: "<<endl;
      for(auto emp: employees){
        emp->calculatePay();
      }
       // Clean up
    for (auto emp : employees) {
        delete emp;
    }
    return 0;
}