//  Scenario: Report Generation System
#include<bits/stdc++.h>
using namespace std;

class Report{
    // responsible for holding report data
    private:
    string title;
    string content;
    public:
    Report(string title, string content){
        this->title=title;
        this->content=content;
        cout<<"Report being generated for you..."<<endl;
    }
    string getTitle(){
        return title;
    }
    string getContent(){
        return content;
    }
};

class ReportPrinter{
// only handle the printing logic
    private:
     Report* repo1;
    public:
    ReportPrinter(Report* repo1){
        this->repo1=repo1;
    }
    void print(){
        cout<<"Printing the results.."<<endl;
        cout<<"report title: "<<repo1->getTitle()<<endl;
        cout<<"report content: "<<repo1->getContent()<<endl;
    }

};

class ReportSaver {
// handle saving the report to a file or database
private:
Report* repo1;
public:
ReportSaver(Report* repo1){
    this->repo1=repo1;
};
void saveToDB(){
    cout<<"Saving report to the database.";
}
};


int main(){
    Report* repo=new Report("summary of project", "aeneneeeeeqeanasmqwnijnnnnnndwiuqnwdkq");
    ReportPrinter* printRepo=new ReportPrinter(repo);
    printRepo->print();
    ReportSaver* saving=new ReportSaver(repo);
    saving->saveToDB();
    return 0;
}