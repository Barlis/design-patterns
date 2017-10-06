/*
 * Encapsulate a request as an object, thereby letting you parameterize 
 * clients with different requests, queue or log requests, and support
 * undoable operations.
 *
 * time: 2017/10/06
 *
 *
 */

#include<iostream>
using namespace std;

class Device{
public:
    virtual void On() = 0;
    virtual void Off() = 0;
    virtual void VolumeUp() = 0;
    virtual void VolumeDown() = 0;
};

// Television is a reciever which undstand how to respone to the request.
// reciever has the knowledge required to carry out the request.
class Television: public Device{
public:
    Television()
    {
        volume = 0;
    }
    virtual void On()
    {
        cout<<"TV on"<<endl;
    }
    virtual void Off()
    {
        cout<<"TV off"<<endl;
    }
    virtual void VolumeUp()
    {
        volume++;
        cout<<"Volume up, volume ="<<volume<<endl;
    }
    virtual void VolumeDown()
    {
        volume--;
        cout<<"Volume Down, volum ="<<volume<<endl;
    }
private:
    int volume;
};

// The Command just have one interface Execute.
// All kinds of command must implement the Command, and concrete command can 
// store the object which is a receiver.
class Command{
public:
    virtual void Execute() = 0;
};

//Concrete Command Object that send the request to the reciver
class TurnTVOn: public Command{
public:
    TurnTVOn(Device& device):device_(device)
    {
    }
    virtual void Execute()
    {
        device_.On();
    }
private:
    Device& device_;
};

class TurnTVOff: public Command{
public:
    TurnTVOff(Device& device):device_(device)
    {
    }
    virtual void Execute()
    {
        device_.Off();
    }
private:
    Device& device_;
};

// who is the invoker?
class DeviceButton{
public:
    DeviceButton(Command& command):command_(command)
    {
    }
    void Press()
    {
        command_.Execute();
    }
private:
    Command& command_;
};

int main()
{
    Device* device = new Television();
    Command* cmd = new TurnTVOn(*device);
    DeviceButton* dev_button = new DeviceButton(*cmd);
    dev_button->Press();

    cmd = new TurnTVOff(*device);
    dev_button = new DeviceButton(*cmd);
    dev_button->Press();
    return 0;
}
