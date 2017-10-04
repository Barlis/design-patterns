/*
 * function:Observer Pattern by c++ 
 * author:
 * date: 04.oct.2017
 *
 */

#include<iostream>
#include<list>
using namespace std;

class Observer{
public:
    virtual void Update(int state) = 0;
    virtual void Display() = 0;
    virtual ~Observer()
    {
    }
};
class Subject{
public:
    virtual void RegisterObserver(Observer* observe) = 0;
    virtual void RemoveObserver(Observer* observer) = 0;
    virtual void NotifyObserver() = 0;
    virtual ~Subject()
    {
    }
};

class DogObserver: public Observer{
public:
    DogObserver(Subject& subject): subject_(subject)
    {
        subject_.RegisterObserver(this);
        state_ = -1;
    }
    virtual ~DogObserver()
    {
        subject_.RemoveObserver(this);
    }
    virtual void Update(int state)
    {
        state_ = state;
    }

    virtual void Display()
    {
        cout<<"DogObserver: I have been notified, state = "<<state_<<endl;
    }
private:
    Subject& subject_;
    int state_;
};

class CatObserver: public Observer{
public:
    CatObserver(Subject& subject): subject_(subject)
    {
        subject_.RegisterObserver(this);
        state_ = -1;
    }
    virtual ~CatObserver()
    {
        subject_.RemoveObserver(this);
    }
    virtual void Update(int state)
    {
        state_ = state;
    }
    virtual void Display()
    {
        cout<<"CatObserver: I have been notified, state ="<<state_<<endl;
    }
private:
    Subject& subject_;
    int state_;
};

class ConcreteSubject: public Subject{
public:

    ConcreteSubject()
    {
        observer_list.clear();
        state_ = 0;
    }

    virtual ~ConcreteSubject()
    {
    }
    virtual void RegisterObserver(Observer* observer)
    {
       observer_list.push_back(observer); 
    }
    virtual void RemoveObserver(Observer* observer)
    {
        std::list<Observer*>::iterator iter; 
        iter = std::find(observer_list.begin(), observer_list.end(), observer);
        if (iter != observer_list.end())
            observer_list.erase(iter);
        else
            cout<<"Can not find the element in the observer list"<<endl;
    }
    virtual void NotifyObserver()
    {
        std::list<Observer*>::iterator iter = observer_list.begin();
        for(; iter != observer_list.end(); ++iter)
            (*iter)->Update(state_);
    }
    void SetState(int state)
    {
        state_ = state;
    }
    int state()
    {
        return state_;
    }
    void StateChanged()
    {
        NotifyObserver();
    }
private:
    std::list<Observer*>observer_list;
    int state_; 
};

int main()
{
   ConcreteSubject subject; 
   DogObserver* dog = new DogObserver(subject);
   CatObserver* cat = new CatObserver(subject);

   subject.SetState(10);
   subject.StateChanged();
   dog->Display();
   cat->Display();

   subject.SetState(99);
   subject.StateChanged();
   dog->Display();
   cat->Display();
   
   return 0;
}
