/*
 *
 *The Iterator Pattern Privides a way to access the element of an aggregate object
 * sequentially without exposing its underlying represention
 *
 *
 *
 * 
 */
#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;
//first define the menuItem class
class MenuItem{
public:
    MenuItem(string name, double price) : name_(name), price_(price)
    {

    }
    string getname()
    {
        return name_;
    }
    double getprice()
    {
        return price_;
    }
private:
    string name_;
    double price_;
};

class Iterator{
public:
    virtual bool HasNext() = 0;
    virtual MenuItem* Next() = 0;
};
class PancakeIterator: public Iterator{
public:
    PancakeIterator(std::vector<MenuItem*>item_vec):item_vec_(item_vec)
    {
        if (item_vec_.size() > 0)
            pos = 0;
        else
            pos = -1;
    }
    virtual bool HasNext()
    {
        if (pos < 0 || pos >= item_vec_.size())
            return false;
        else
            return true;
    }
    virtual MenuItem* Next()
    {
        return item_vec_[pos++];
    }
private:
    std::vector<MenuItem*>item_vec_;
    int pos;
};

class DinnerIterator: public Iterator{
public:
    DinnerIterator(std::list<MenuItem*>item_vec):item_vec_(item_vec)
    {
        iter_ = item_vec_.begin();
    }

    virtual bool HasNext()
    {
        if (iter_ == item_vec_.end())
            return false;
        else
            return true;
    }
    virtual MenuItem* Next()
    {
        return *iter_++;
    }
private:
    std::list<MenuItem*> item_vec_;
    std::list<MenuItem*>::iterator iter_;
};

class PancakeHouseMenu{
public:
    PancakeHouseMenu()
    {
        menu_items_.clear();
        AddItem("AppleCake", 10.00);
        AddItem("PearCake", 11.11);
        AddItem("OrangeCake", 22.22);
    }
    void AddItem(string name, double price)
    {
        MenuItem* item = new MenuItem(name, price);
        menu_items_.push_back(item);
    }

    std::vector<MenuItem*>& GetMenuItems()
    {
        std::vector<MenuItem*>::iterator iter = menu_items_.begin();
        for(; iter != menu_items_.end(); ++iter)
        {
            cout<<(*iter)->getname()<<"  " << (*iter)->getprice() <<endl;
        }

        return menu_items_;
    }
    Iterator* CreateIterator()
    {
        return new  PancakeIterator(menu_items_);
    }
private:
    std::vector<MenuItem*>menu_items_;

};

class DinnerMenu{
public:
    DinnerMenu()
    {
        menu_items_.clear();
        AddItem("FishVeg", 10.00);
        AddItem("MeatVeg", 11.11);
        AddItem("BeafVeg", 22.22);
    }
    void AddItem(string name, double price)
    {
        MenuItem* item = new MenuItem(name, price);
        menu_items_.push_back(item);
    }

    Iterator* CreateIterator()
    {
        return new  DinnerIterator(menu_items_);
    }
   
private:
    std::list<MenuItem*>menu_items_;

};


int main()
{


    PancakeHouseMenu pan_menu;
    Iterator* iter = pan_menu.CreateIterator(); 
    while (iter->HasNext())
    {
        MenuItem *menu_item = iter->Next();
        cout<<"Item name = "<< menu_item->getname() <<endl;
        cout<<"Item price= "<< menu_item->getprice() << endl;
    }

    DinnerMenu dinner_menu;
    iter = dinner_menu.CreateIterator(); 
    while (iter->HasNext())
    {
        MenuItem *menu_item = iter->Next();
        cout<<"Item name = "<< menu_item->getname() <<endl;
        cout<<"Item price= "<< menu_item->getprice() << endl;
    }
    
    return 0;
}
