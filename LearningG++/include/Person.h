#ifndef PERSON_H_
#define PERSON_H_

class Person
{
public:
    Person(int age);
    ~Person();

    void printAge();
    void doSomething();

private:
    int age;
    int sex;
};



#endif
