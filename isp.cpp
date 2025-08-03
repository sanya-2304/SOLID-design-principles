// Scenario: Smart Home Devices System
#include<bits/stdc++.h>
using namespace std;
// class SmartDevice {
// public:
//     virtual void turnON()=0;
//     virtual void turnOFF()=0;
//     virtual void playMusic()=0;
//     virtual void openDoor()=0;
//     virtual void setTemperature()=0;
// };
// this one big fat interface kinda violates isp principle as :
//  SmartSpeaker — can turnOn(), turnOff(), and playMusic().
//  SmartThermostat — can turnOn(), turnOff(), and setTemperature().
//  SmartDoorLock — can turnOn(), turnOff(), and openDoor().

// so create separate interfaces to keep clients independent

class SmartDevice {
    public:
     virtual void turnOn()=0;
     virtual void turnOff()=0;
     ~ SmartDevice(){}
};
class temp{
    public:
     virtual void setTemperature()=0;
     ~ temp(){}
};

class music{
    public:
    virtual void playMusic()=0;
    ~ music(){}
};
class door{
    public:
    virtual void openDoor()=0;
       ~ door(){} 
};
class SmartSpeaker: public SmartDevice ,public music {
    public:
    void turnOn() override{
        cout<<"SmartSpeaker turned on."<<endl;
    }
    void turnOff() override{
        cout<<"SmartSpeaker turned off."<<endl;
    }
    
    void playMusic() override{
        cout<<"SmartSpeaker playMusic."<<endl;
    }
    ~ SmartSpeaker(){
        cout<<"SmartSpeaker deleted."<<endl;
    }
};
class SmartDoorLock : public SmartDevice ,public door {
    public:
    void turnOn() override{
        cout<<"SmartDoorLock  turned on."<<endl;
    }
    void turnOff() override{
        cout<<"SmartDoorLock  turned off."<<endl;
    }
    void openDoor() override{
        cout<<"SmartDoorLock  openDoor."<<endl;
    }
     ~ SmartDoorLock(){
        cout<<"SmartDoorLock deleted."<<endl;
    }

};
class SmartThermostat : public SmartDevice ,public temp {
    public:
    void turnOn() override{
        cout<<"SmartThermostat  turned on."<<endl;
    }
    void turnOff() override{
        cout<<"SmartThermostat  turned off."<<endl;
    }
    void setTemperature() override{
        cout<<"SmartThermostat  setTemperature."<<endl;
    }
     ~ SmartThermostat(){
        cout<<"SmartThermostat deleted."<<endl;
    }
};
int main(){
    vector<SmartDevice*> smartDevices;
    vector<music*> musicDevices;
    vector<temp*> tempDevices;
    vector<door*> doorDevices;
    SmartSpeaker* speaker = new SmartSpeaker();
    SmartThermostat* thermostat = new SmartThermostat();
    SmartDoorLock* doorLock = new SmartDoorLock();
     smartDevices.push_back(speaker);
    smartDevices.push_back(thermostat);
    smartDevices.push_back(doorLock);
     cout << "\n--- Turning ON all devices ---\n";
    for (auto device : smartDevices) device->turnOn();
    musicDevices.push_back(speaker);
    tempDevices.push_back(thermostat);
    doorDevices.push_back(doorLock);
     cout << "\n--- Playing Music ---\n";
    for (auto m : musicDevices) m->playMusic();
     cout << "\n--- Setting Temperature ---\n";
    for (auto t : tempDevices) t->setTemperature();
    cout << "\n--- Opening Doors ---\n";
    for (auto d : doorDevices) d->openDoor();
    cout << "\n--- Turning OFF all devices ---\n";
    for (auto device : smartDevices) device->turnOff();
    cout << "\n--- Cleaning up all devices ---\n";
     delete speaker;
    delete thermostat;
    delete doorLock;
    return 0;
}