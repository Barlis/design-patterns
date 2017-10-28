/*
 *
 * State pattern is 
 *
 *
 */
#ifndef GUMBALL_MACHINE_H_
#define GUMBALL_MACHINE_H_
#include<iostream>

class State;
class HasQuarterState;
class NoQuarterState;
class SoldState;
class SoldOutState;
using namespace std;
class GumballMachine{
public:
    GumballMachine(int count);
    State* GetNoQuarterState()
    {
        return no_quarter_state_;
    }
    State* GetHasQuarterState()
    {
        return has_quarter_state_;
    }
    State* GetSoldState()
    {
        return sold_state_;
    }
    State* GetSoldOutState()
    {
        return sold_out_state_;
    }
    void SetState(State* state)
    {
        current_state_ = state;
    }

    void TurnCrank()
    {
      current_state_->TurnCrank();
      current_state_->Dispense();
    }
    void InsertQuarter();

    void EjectsQuarter();

    void ReleaseBall();
private:
    State* no_quarter_state_;
    State* has_quarter_state_;
    State* sold_state_;
    State* sold_out_state_;
    State* current_state_;
    int count_;
};
#endif
