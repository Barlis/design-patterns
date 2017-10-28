/*
 *
 * State pattern allow an object to alert it's behavior
 * when its internal state changes.
 * The object will appear to changes its class.
 *
 *
 */
#ifndef STATE_H_
#define STATE_H_
#include<iostream>
using namespace std;

class GumballMachine;

class State{
    virtual void InsertQuarter() = 0;
    virtual void EjectsQuarter() = 0;
    virtual void TurnCrank() = 0;
    virtual void Dispense() = 0;
};


class NoQuarterState: public State{
public:
    NoQuarterState(GumballMachine& gumball_machine);
    virtual void InsertQuarter();
    virtual void EjectsQuarter()
    {
        cout<<"You haven't quarter"<<endl;
    }
    virtual void TurnCrank()
    {
        cout<<"You should insert an quarter"<<endl;
    }
    virtual void Dispense()
    {
        cout<<"You must turn crank before dispense"<<endl;
    }

private:
    GumballMachine& gumball_machine_;
};

class HasQuarterState: public State{
public:
    HasQuarterState(GumballMachine& gumball_machine):gumball_machine_(gumball_machine)
    {
    }
    virtual void InsertQuarter()
    {
        cout<<"Already have a quarter"<<endl;
    }
    virtual void EjectsQuarter()
    {
        cout<<"Ejected a  quarter"<<endl;
        gumball_machine_.SetState(gumball_machine_.GetNoQuarterState());
    }
    virtual void TurnCrank()
    {
        cout<<"You should insert an quarter"<<endl;
        gumball_machine_.SetState(gumball_machine_.GetSoldState());
    }
    virtual void Dispense()
    {
        cout<<"You must turn crank before dispense"<<endl;
    }
private:
    GumballMachine& gumball_machine_;
};

class SoldState: public State{
public:
    SoldState(GumballMachine& gumball_machine):gumball_machine_(gumball_machine)
    {
    }
    virtual void InsertQuarter()
    {
        cout<<"Already have a quarter"<<endl;
    }
    virtual void EjectsQuarter()
    {
        cout<<"You have inserted quarter, and can't ejects"<<endl;
    }
    virtual void TurnCrank()
    {
        cout<<"Turning twice don't get you another gumball"<<endl;
    }
    virtual void Dispense()
    {
        cout<<"A gumball comes rolling out the slot"<<endl;
        gumball_machine_.ReleaseBall();
        gumball_machine_.SetState(gumball_machine_.GetNoQuarterState());
    }
private:
    GumballMachine& gumball_machine_;
};

class SoldOutState: public State{
public:
    SoldOutState(GumballMachine& gumball_machine):gumball_machine_(gumball_machine)
    {
    }
    virtual void InsertQuarter()
    {
        cout<<"You can't insert another quarter"<<endl;
    }
    virtual void EjectsQuarter()
    {
        cout<<"You can't eject, you haven't inserted a quarter yet"<<endl;
    }
    virtual void TurnCrank()
    {
        cout<<"You turned, but there are not gumball"<<endl;
    }
    virtual void Dispense()
    {
        cout<<"No Gumball in the machine"<<endl;
    }
private:
    GumballMachine& gumball_machine_;
};
#endif
