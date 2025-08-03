    // Scenario: Notification System 

    #include<bits/stdc++.h>
    using namespace std;

    class NotifSender{
        public:
        virtual void notify()=0;
        virtual ~NotifSender(){}
    };

    class EmailService: public NotifSender{
        public:
        void notify() override{
            cout<<"Notification on the email recieved."<<endl;
        }
        ~EmailService(){
            cout<<"Deleteing EmailService "<<endl;
        }
    };
    class SMsService: public NotifSender{
        public:
        void notify() override{
            cout<<"Notification on the sms recieved."<<endl;
        }
        ~SMsService(){
            cout<<"Deleteing SMsService "<<endl;
        }
    };
    class WhatsAppService: public NotifSender{
        public:
        void notify() override{
            cout<<"Notification on the WhatsApp recieved."<<endl;
        }
        ~WhatsAppService(){
            cout<<"Deleteing WhatsAppService "<<endl;
        }
    };


    class NotificationService{
        // High-Level Module Depends on Abstraction, Not Details
        private:
        NotifSender* nfs;
    public:
        NotificationService(NotifSender* nfs){
            this->nfs=nfs;
        }
        void notifyDisplay(){
            nfs->notify();
        }
        ~NotificationService(){
            cout<<"Deleteing NotificationService "<<endl;
        }
    };


    int main(){
        vector<NotifSender*>NotifSender;
        NotifSender.push_back(new EmailService());
        NotifSender.push_back(new SMsService());
        NotifSender.push_back(new WhatsAppService());

        for(auto serv:NotifSender){
             NotificationService* ns = new NotificationService(serv);
             ns->notifyDisplay();
             delete ns;
             cout<<"----------"<<endl;
        }
          for (int i = 0; i < NotifSender.size(); ++i) {
        delete NotifSender[i];
    }
        return 0;
    }