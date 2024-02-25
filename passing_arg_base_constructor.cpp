/*
How to invoke base class constructor and pass at=rguments from the erived class
Passing arguments to base class constructors.
    ->the base part of derived clas must be initialized first;

Passing arguments to base class constructors;
    class Base{
        Base();
        Base(int );
        ...
    };
    Detvied ::Derived(int x):Base(x),{Optional initializer for derived}{
        .//code;
    }
Note:
    this code executes after both base and derived parts of the derived object has been initialized;
    if we don't explicitly invoke the base overloaded constructors;the no args conctructor will be invoked automatically ;
    since base must be initilaized;

*/

#include<iostream>
class Base{
private:
    int value;
public:
    Base():value{0}{
        std::cout<<"base no-args constructor"<<std::endl;
    }
    Base(int x):value{x}{
        std::cout<<"Base(int) overloaded constructor: "<<x<<std::endl;
    }
    ~Base(){
        std::cout<<"Base destrcutor"<<std::endl;
    }
};
class Derived :public Base{
private:
    int doubled_value;
public:
//explicitly calling base class no arg constructor and int constrcutor of base class
/*
before the body of the derived constructor is initiliazed / before the derived class object get initialized base class constructor get initialized explicitly..
for both no-arg and (int)-arg constructor

*/
    Derived(): Base {},doubled_value{0}{
        std::cout<<"derived no args constructor"<<std::endl;
    }
    Derived(int x):Base(x),doubled_value(x*2){
        std::cout<<"Derived (int) constructor: "<<x<<std::endl;
    }
    ~Derived(){
        std::cout<<"Dervied detsructor"<<std::endl;
    }
};

int main(){

    Derived d;
    std::cout<<"\n";
    Derived d1(100);
    std::cout<<"\n";
    return 0;
}