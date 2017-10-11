/*
 * Represent an operation to be performed on the elements of an object 
 * structure. Visitor lets you define a new operation without changing 
 * the classes of the elements on which it operates.
 *
 *
 */
#include <iostream>
using namespace std;


class Element{
public:
    virtual void Accept(Visitor* visitor) = 0;
    
pirvate:
    Visitor* visitor_;
};

class ConcreteElementA: public Element{
public:
    virtual void Accept(Visitor* visitor)
    {
        visitor->VisitElementA(this);
    }
};

class ConcreteElementB: public Element{
public:
    virtual void Accept(Visitor* visitor)
    {
        visitor->VisitElementB(this);
    }
};

class Visitor{
    virtual void VisitElementA(Element* element)
    {
    }
    virtual void VisitElementB(Element* element);
protected:
    Visitor()
    {
    }
};
