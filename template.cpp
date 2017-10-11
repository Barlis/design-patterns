/*
 *
 * The Template Method defines the steps of an algorithm and allows subclasses
 * to provide the implementation for one or more steps.
 * defines the skeleton of an algorithm in a method, defering some steps in method.
 * it let subclasses redefine certains of algorithm without changes the algorithm structure.
 *
 *
 */
#include<iostream>
using namespace std;

class CaffeineBeverage{
public:
    void PrepareRecipe()
    {
        BoilWater();
        PourInCup();
        Brew();
        AddCondiments();
    }
    void BoilWater()
    {
        cout<<"BoilWater"<<endl;
    }
    void PourInCup()
    {
        cout<<"PourInCup"<<endl;
    }
    virtual void Brew() = 0;
    virtual void AddCondiments() = 0;
};

class Coffee: public CaffeineBeverage{
    virtual void Brew()
    {
        cout<<"brew coffee"<<endl;
    }
    virtual void AddCondiments()
    {
        cout<<"Add milk,sugar"<<endl;
    }
};

class Tea: public CaffeineBeverage{
    virtual void Brew()
    {
        cout<<"brew Tea"<<endl;
    }
    virtual void AddCondiments()
    {
        cout<<"Add something else"<<endl;
    }
};

int main()
{
    Tea tea;
    tea.PrepareRecipe();
    Coffee coffee;
    coffee.PrepareRecipe();
    return 0;
}
