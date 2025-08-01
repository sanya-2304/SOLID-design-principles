// Report Formatter Using OCP

#include<bits/stdc++.h>
using namespace std;

class Report {
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
    ~Report(){
    cout << "Destroying Report: " << title << endl;
}

};

// ❌ This violates OCP
// because every time we add a new format, we modify the class.
// class ReportPrinter {        
//     void print(int formatType) {
//         if (formatType == 1) { /* plain text */ }
//         else if (formatType == 2) { /* JSON */ }
//         else if (formatType == 3) { /* HTML */ }
//     }
// }


class ReportFormatter{
    public:
    virtual void format(Report* rep)=0;
    virtual ~ReportFormatter(){
    // cout << "Destroying ReportFormatter base class" << endl;
}

};

class PlainTextFormatter : public ReportFormatter{
    public:
    void format(Report* rep) override{
        cout<<"Printing report in plain text format: "<<rep->getTitle()<<endl;
    }
    ~PlainTextFormatter(){
    cout << "Destroying PlainTextFormatter" << endl;
}

};

class JSONFormatter  : public ReportFormatter{
    public:
    void format(Report* rep) override{
        cout<<"Printing report in json format: "<<rep->getTitle()<<endl;
    }
    ~JSONFormatter(){
    cout << "Destroying JSONFormatter" << endl;
}

};

class HTMLFormatter  : public ReportFormatter{
    public:
    void format(Report* rep) override{
        cout<<"Printing report in html format: "<<rep->getTitle()<<endl;
    }
      ~HTMLFormatter(){
    cout << "Destroying HTMLFormatter" << endl;
}
};

class ReportPrinter {
    private:
    ReportFormatter* rf;
    public:
    ReportPrinter(ReportFormatter * formatter){
        this->rf=formatter;
    }
    void print(Report* rep){
    if (rf != nullptr && rep != nullptr) {
        rf->format(rep);  
    }
    }
    ~ReportPrinter(){
    cout << "Destroying ReportPrinter" << endl;
}

};

int main(){
    Report* rep1=new Report("ocp report","abcdefghxyz");
    ReportFormatter* rf=new HTMLFormatter();
    ReportPrinter* repoprinting=new ReportPrinter(rf);
    repoprinting->print(rep1);
    cout<<"--------------"<<endl;
    rf=new JSONFormatter();
    repoprinting=new ReportPrinter(rf);
    repoprinting->print(rep1);
    cout<<"---------"<<endl;
    delete rf;
    delete rep1;
    delete repoprinting;
    return 0;
}