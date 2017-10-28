/*
 *
 * State pattern is 
 *
 *
 */
#include<iostream>
#include "gumball_machine.h"
#include "state.h"

GumballMachine::GumballMachine(int count):count_(count)
{
    no_quarter_state_ = new NoQuarterState(*this);
    has_quarter_state_ = new HasQuarterState(*this);
    sold_state_ = new SoldState(*this);
    sold_out_state_ = new SoldOutState(*this);

    if (count_ > 0)
        current_state_ = no_quarter_state_;  
}


void GumballMachine::InsertQuarter()
{
    current_state_->InsertQuarter();
}

void GumballMachine::EjectsQuarter()
{
    current_state_->EjectsQuarter();
}

void GumballMachine::ReleaseBall()
{
    cout<<"A gumball comes rolling out the slot..."<<endl;
    if(count_ > 0)
        count_--;
}
