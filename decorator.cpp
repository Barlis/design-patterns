/*
 * Attach additional responsibilities to an object dynamically. Decorators 
 * provide a flexible alternative to subclassing for extending functionality.
 * 1. more flexibility than static inheritance
 * 2. avoid featrue-laden classes high up in the hierarchy.
 *
 *
 */

#include<iostream>
using namespace std;

class VisualComponent{
public:
    virtual void Draw() = 0;
};

class TextView: public VisualComponent{
public:
    virtual void Draw()
    {
        cout<<"TextView: Draw the text"<<endl;
    }
};

class Decorator: public VisualComponent{
public:
    Decorator(VisualComponent& component):component_(component)
    {
    }
    virtual void Draw()
    {
        component_.Draw();
    }
private:
    VisualComponent& component_;
};

class ScrollDecorator: public Decorator{
public:
    ScrollDecorator(VisualComponent& component): Decorator(component)
    {
    }
    virtual void Draw()
    {
        Decorator::Draw();
        ScrollTo();
    }
    void ScrollTo()
    {
        cout<<"Add a scoll to the object"<<endl;
    }
};

class BoardDecorator: public Decorator{
public:
    BoardDecorator(VisualComponent& component):Decorator(component)
    {
    }
    virtual void Draw()
    {
        Decorator::Draw();
        DrawBoard();
    }
    void DrawBoard()
    {
        cout<<"Draw Boarder to the object"<<endl;
    }
};

int main()
{
    TextView text_view;
    Decorator* decorator = new BoardDecorator(text_view);
    Decorator* last_decorator = new ScrollDecorator(*decorator);
    last_decorator->Draw();
    return 0;
}
