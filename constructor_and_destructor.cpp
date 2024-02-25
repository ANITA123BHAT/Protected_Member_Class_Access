#include<iostream>
class Base{
private:
    int value;
public:
    Base():value{0}{
        std::cout<<"Base no-args constrcutor"<<std::endl;
    }
    Base(int x):value{x}{
        std::cout<<"Base(int) overloaded constructor:"<<x<<std::endl;
    }
    ~Base(){
        std::cout<<"Base destructor"<<std::endl;
    }
};

class Dervied:public Base{
    //using Base::Base;
        /*this will allow us to inherit the non -special constructor from my base class
        //thisis a non-special constructor
        //but here base class arg constructor get called but noy dervied class int parameter constrcutor
        //bcz it is inherited explicitly here double value not initialixzed with value 200
        //this is the issue with automatically inheriting the non special constructor;
    */

private:
    int doubled_value;
public:
    Dervied():doubled_value{0}{
        std::cout<<"derived no-arg constrcutor\n"<<std::endl;
    }
    Dervied(int x):doubled_value{x*2}{

        std::cout<<"derved constrcutor with parameter: "<<x<<std::endl;
    }
    ~Dervied(){
        std::cout<<"Derived detsructor"<<std::endl;
    }
};
int main(){
    Base b;//only defaukt constrctor called
    std::cout<<"\n";
    Base b1{100};
    //only parametrized constructor
    std::cout<<"\n";
    Dervied d;
    std::cout<<"\n";
    /*
    Base no-args constrcutor
    derived no=arg constrcutor

    Derived detsructor
    Base destructor
    */
    Dervied d1(200);
    std::cout<<"\n";
}