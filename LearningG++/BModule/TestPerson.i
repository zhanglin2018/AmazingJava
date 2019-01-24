# 1 "TestPerson.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "TestPerson.cpp"
# 1 "/home/linzhang/AmazingJava/LearningG++/include/Person.h" 1 3



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
# 2 "TestPerson.cpp" 2

int main(int argc, char** argv){
    Person person(10);
    person.printAge();
    person.doSomething();
    return 0;
}
