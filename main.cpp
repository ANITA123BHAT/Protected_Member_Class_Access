/*       
 Type of inheritance in c++;
            ->public:
                ->most common;
                ->establishes 'is-a' reltionship btw derived and base classes;
            ->private and protected:
                ->eshtablishes "derived class has has-a base class "relationship
                ->"is implmented in terms of " relationship
                ->different from composition;

        The protected class member modifier:
        class Base{
            protected:
                ->accessible from the base class itself (Acessible to it's class)
                ->accessible from classesany derived that derived from base
                ->not accessible by objects base or derived;
                ->protected member are act lie a private mmeber so ther are not directly accessible from object of either the base or derived class;

        };     

        ->Access with "Public" inheritance:
            base class "public inheritance" access in deribved class:
            public :a                                       public:a public memebr of base is public in derived class
            protected b;                                    protected :b;
            private:c;                                      c =not acesible

        ->Access with "Protected" inheritance:
            Base class protected inheritance access in derived class
            public: a;                                      protected:a
            protected :b;                                   protected:b;
            private:c;                                       c=not access

        ->Access with "Private" inheritance;
            Base class "private" inheritance access in derived class
            public: a;                                      private:a
            protected :b;                                   private:b;
            private:c;                                      c=not access; 


How constructor works while inheritance?
->A derived class inherits from it's base class
->the base part of the derived class Must be initialized Before 
->When the derived object is created:
    base class constructor executes then 
    derived class constructor executes;


How destructor are involved?
    ->class destructor are invoked in the reverse order as constructors
    ->the derived part of the derived class Must be detsrouyed BEFORE the  base class destructor is invoked
    ->when a derived object is destroyed:
        1.derived class detsructor exedcutes then 
        2.base class destrcutor executes
        2. each destructor should free resources allocated in it's own constructors;

A derived class does NOT inherit;
    base class constructors;
    base calss destructor
    base class overloaded assignment operators
    base class friend functions;
However, the derived class constructor , destructor  and and overloaded assignment operator can  invoke the base class versions;

c++11 alows explicit inheritance of base "non-speccial" constructor with :
    ->using Base::Base; anywhere in the derived class declaration. 


*/

#include<iostream>
class Base{
    //note : "friend" of base have access to all
public:
    int a{0};
    void display(){
        std::cout<<a<<", "<<b<<","<<c<<std::endl;//member method has access to all
    }
protected:
    int b{0};
private:
    int c{0};
};
class Dervied :public Base{
//note: friends of derived have access to only what derived has access to 
    //a will be public;
    //b will be protected
    //c will benot accessible

public:
    void access_base_member(){
        a=100;//ok
        b=200;//ok
        //c=300 compiler error bcz private in child eventhough publicly derived
    }
};
int main(){
    std::cout<<"\nBase memeber access from base object========="<<std::endl;
    Base base;
    base.a=100;//OK
    //base.b=200;//compiler error both private and protected are same in main;
    //base.c=300;//compiler error
    std::cout<<"========Base member access from derived objects====="<<std::endl;
    Dervied d;
    d.a=100;
    // d.b=200;compiler error
    // d.c=300;compiler error
    return 0;
}