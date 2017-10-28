#include "state.h"
#include "gumball_machine.h"

int main()
{
    GumballMachine gumball(5);

    gumball.InsertQuarter();
    gumball.EjectsQuarter();
    gumball.TurnCrank();
    gumball.Dispense();

    return 0;

}
