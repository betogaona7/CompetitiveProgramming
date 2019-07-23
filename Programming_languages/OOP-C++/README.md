# Classes and objects 
Classes can be defined as ```class``` or ```struct```. The only different is that members on ```struct``` are public by default. It is good practice to use struct when the structure will have only data memembes, and use class where there are also function members.

``` :: ```  scope resolution operator, means that setValue is member function of class1.
```c++ 
void class1::setValue(int & value){
    i = value; 
}
``` 
##### Programs are often divided in three parts:
```file.h```  are headers files. It contains the class definition. For example:
```c++
class class1{
    int i = 0;
    public: 
        void setVAlue(const int &);
        int getValue() const;
}
``` 

``` file.cpp ``` contains the implementation, the member functions. For example:
```c++ 
void class1::setValue(const int & value){
    i = value;
}
int class1::getValue() const{
    return i;
}
``` 
``` main.cpp ``` contains everything else. For example:
```c++ 
int main(){
    const int i = 47;
    class1 ob1;
    ob1.setValue(i);
    cout << "Value is: " << ob1.getValue() << endl;
    return 0;
}
``` 
##### Const-qualified object
You can have two different functions with exactly the same signature where the only difference is that one is const-qualified and one is not. The mutuable one will get called by mutable objects and the const-qualified ones  will get called by const-qualified objects. Example:

```c++
int class1::getValue(){
    puts("mutable getValue");
    return value;
}
int class1::getValue() const {
    puts("comst getVAlue");
    return value;
}
``` 
Thumb rule: const functions can always get called from mutable objects and from constant objects. Non-const functions may only be called by non-const objects.

##### Constructors and destructors
They create and destroy objects from a class. 
- implicit constructor: It is the default, meaning that you didn't define one.
- Copy constructor: It was defined by you.
```c++
Class class1{
    public: 
        class1(); // default constructor
        class1(const string & type, const string & name); // copy constructor
        ~classs1(); //destructor
}
```
``` : ``` is a special initializer that is used with constructors on classes. Example:
```c++
class1::class1():type("unknown"), name("unknown"){
    puts("Constructor with arguments");
}
``` 
Constructors with only one argument can perfom implicit conversion. This is that if it takes in as input an int, and you send it a char like 'x', it implicitly will convert the 'x' to the value of 120, which is the ASCCI value. To avoid this we can add the word ``` explicit ``` . Example:
```c++
class class1{
        public:
            explicit class1(const int & value);
}
``` 
##### Namespaces 
A tool to avoid name collisions. Typically they are defined on header files.
```c++
namespace bw{
    const std::string prefix = "(bw::string)";
    class string{
            std::string s = "";
        public:
            string (const std::string & s) : s(prefix + s){}
            const char * c_str() const {return s.c_str(); }
            operator std::string & () {return s;}
            operator const char * () const {return s.c_str();}
    }
}
``` 

##### Self referencing pointer 
Object member functions use```  this ```  to provide a pointer to the current object. Example:
```c++
class class1{
    public:
        int getValue() const;
}
int class1::getValue() const{
    printf("pointer addess &p\n", this);
}

int main(){
    class1 ob1; 
    ob1.setValue(65)
    printf("address of ob1 is %p\n", &ob1); // addr ... is 0x7ffe.. 
    printf(o1.getValue()); // pointe ... ess 0x7ffe..
}
``` 
It is very useful in some circunstances, like for example, when overloading an assignment operator, you wan to return a reference to the current object so that your assigments can be chained.
##### Allocating object memory 
Keywords ``` new ```  and ``` delete ```  are used to allocate and deallocate memory. Useful when you created an object and you wanto to use it beyond the lifetime of a function or a block, and destroy it later.
```c++ 
int main(){
    try{
        class1 *ob1 = new class1[10];
        cout << ob1 -> a() << endl;
        delete [] ob1;
    }catch(bad_alloc &ba){
        return 1;
    }
}
``` 

To do the same without a try-catch block. 
```c++
int main(){
    class1 *ob1 = new (nothrow) class1[10];
    if(ob1 == nullptr){
        puts("new ob1 error ");
        return 1;
    }
    cout << ob1 -> a() << endl;
    delete [] ob1;
}
``` 
##### Functors 
By overloading the function operator, you can create an object that operates as if it were a function. This can be a handy technique for circmstances where you need to keep state or other context information within you functions calls.
```c++
class MultyBy{
        int mult = 1;
        MultBy();
    public:
        MultiBy (int n) : mult(n) {}
        int operator () (int n) const {return mult * n;}
}
int main(){
    const MultyBy times10(10);
    cout << "times10(5) is: " << times10(5) << endl; // 50
    return 0;
}
``` 
# Class inheritance
Inheritance represents the ability to reuse code by deriving a class from a base class. 

##### Member access specifiers
There are three different levels of memeber access, this levels determine what other objects will be able to access class members.
- ``` public ```  Members given public are available to all objects. (Base class, Derived class, Other objects).
- ``` protected ``` Available to members of the base class and any derived classes.
- ``` private ``` Only available to the base class.

##### Simple inheritance
It is simple a metter of creating a base class and then declaring the inheritance in your derived class definition. Example:
```c++ 
class Animal{
        string name;
        string type;
        string sound;
    protected:
        Animal (const string &n, const string &t, const string &s)
        : name(n), type(t), sound(s){}
}
class Dog : public Animal {
    public:
        Dog(string n) : Animal(n, "dog", "woof"){};
}
``` 
##### Accessing the base class
When creating a derived class, it is sometimes necessary to access member data and functions from the base class. For example:
```c++
class Animal{
        string name;
        string type;
        string sound;
    protected:
        Animal (const string &n, const string &t, const string &s)
        : name(n), type(t), sound(s){}
    public:
        const string &name() const {return name};
}
class Dog : public Animal {
    public:
        Dog(string n) : Animal(n, "dog", "woof"){};
        string latin() const { return Animal::name() + "-ay"; }
}
``` 
##### Friendship 
The ``` friend ``` qualifier allows you to grant private memembers access to other classes or functions. It should be used with a great deal of caution. Most of the time, it's best practice to access private members through the class interface methods because it defeats the purpose of encapsulation. 
```c++
class Animal{
        string name;
        string type;
        string sound;
        friend const string &get_animal_name(const Animal &);
}

const string &get_animal_name(const Animal &a){
    return a.name;
}
``` 
##### Multiple inheritance
It is a matter of listing more than one base class in the class definition. Ecample:
```c++
class BaseA{
    ...
}
class BaseB{
    ...
}
class MyClass: public BaseA, public  BaseB{
    ...
}
``` 
##### Polymorphism
Overload a function that is defined in a base class. ``` virtual ```   says the compiler that the memeber function may be overloaded.
```c++
class Animal{
        string sound;
    public: 
        virtual void speak() const;
        virtual ~Animal(){}
};
void Animal::speak() const {
    cout << "The animal says: " << sound << endl;
}
class Cat : public Animal{
    public:
        void speak() const {Animal::speak(); puts("purrrrr");}
}
``` 
# Smart pointers 
A smart pointer is a template class that uses operator overloads to provide the functionality of a pointer while providing improved memory management and safety. It is essentially a wrapper around a standard bare C language pointer. They are defined in the memory header: ```#include <memory> ```

##### Unique pointer 
It is a kind of smart pointer that cannot bec opied. There is only ever one copy of this pointer, so you cannot inadvertently make copies of it. and there is never any doubt about who owns it.
```c++
// Define unique pointer 
std::unique_ptr<int> a(new int(7);
auto b = std::make_unique<int>(1); // For c++ 17

// Reset pointer to another value
a.reset(new int(3);

// MOVE pointer a to c
auto c = std::move(a);

// Reset pointer to simply destroy it.
b.reset();

// Release simply releases the pointer from the control of the smart pointer.
// Now C is NULL, the object has not been destroyed.
c.release();
```
You cannot pass a unique pointer to a functions. (Use a reference instead). Example:
```c++
void f(std::unique_ptr<int> &p){
    disp(p);
}
```
This is necesary because a function call makes a copy of the object to pass it to the function.
##### Shared pointer
It works very much like a unique pointer with the distiction that you may make copies of a shared pointer. It provides a limited garbage collection facility for managing the number of pointer to the same object.
```c++
// Create pointer 
auto a = std::make_shared<int>(7); // recommended way
std::shared_ptr<int> b(new int(1);

// Free up pointer and create a new object at the same time
a.reset(new int(3);

// make a copy of b
auto c = b;
```
It is very efficient, easy to use, and it makes managing shared memory resources relatively simple.
##### Weak pointer 
It is a special case of a shared pointer. It is not counted in the shared pointers reference count. This is useful for cases where you may need a pointer that doesn't affect the lifetime of the resouce it points to.

A weak pointer is typically created from a shared pointer. Example:
```c++
// Create shared pointer
auto a = std::make_shared<int>(7);

// Make several copies
auto c1 = a;
auto c2 = a;
auto c3 = a; //Here, reference count is 4

// Create weak pointer
auto w1 = std::weak_ptr<int>(a);
```
A typical use case if when you want to prevent a circular reference. For example a _manager_ object may point to the _employee_ it manages while the _employee_ object may also point back up to the _manager_ it reports to. These objects now keep each other alive because they refer to each other. So you cannot destroy either _manager_ nor _employee_.
##### Custom deleter
Sometimes when destroying a smart pointer, you may need to do more than just destroy the managed object. For these circumstances, you may define a custom deleter.
```c++
// Define pointer function to destroy
void deleter(const int *o){
    cout << "Deleter: ";
    if(o){
        cout << o->value();
        delete o;
    } else{
        cout << "NULL";
    }
    fflush(stdout);
}
// Create a shared pointer and specify a custom deleter
std::shared_ptr<int> a(new int(7), deleter);
```
# Move semantics
It moves data to a new object instead of copying it. This saves a lot of memory and time resources. This is accomplish by using an _rvalue reference_. They are found in ```#include <utility>```

##### Lvalue and rvalue
In simple terms, any expression that can appear on the left side of an assignment is an _lvalue_. Likewise, an expression that can ONLY appear on the right side of an assigment is an _rvalue_. Example ```a = b;``` a is the _lvalue_ and b is the _rvalue_. 
- _lvalue reference_ ```int &x``` 
- _rvalue reference_```int &&x```

```c++
int main(){
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {6, 7, 8, 9, 10};
    
    display(v1);
    display(v2);
    
    auto v3 = std::move(v1);
    
    display(v1); // It display NULL
    display(v2);
    display(v3); // It display v1 content
}
```
##### Move constructor 
In order to take advantage of move semantics in your own class, you will need to create  a move constructor. Example:
```c++
class classA{
    public:
        classA(ClassA &&) noexcept;
}
classA::classA(classA &&rhs) noexcept{
    message("Move constructor");
    x = std::move(rhs.x); 
    rhs.reset();
}
int main(){
    classA a = 1;
    classA b = 5;
    classA c = std::move(a);
}
```
##### Swap and copy
Add it on an operator, this will be more efficient.
```c++
class classA{
    public:
        void swap(classA &){}
}
classA & classA::operator = (classA rhs){
    message("Copy and swap");
    swap(rhs);
    return *this;
}
void classA::swap(classA & o){
    std::swap(x, o.x);
}
```
##### Rule of five
A generally accepted rule in C++ is that if you define any of these five members functions in your class you will need to define all five.
```c++
- ~Class(); // destructor
- Class(Class &); // Copy constructor
- Class & operator = (Class &); // Copy assigment 
- Class(Class &&); // Move constuctor
- Class & operator = (Class &&); // Move assigment
```
# Lambda functions 
They are anonymous functions (functions without a name) with the ability to refer to identifiers outside of its own scope.
```c++
int main(){
    char lastc = 0;
    char s[] = "big light in sky slated to appear in east";
    transform(s, s+strnlen(s, MAX_LENGTH), s, [&lastc](const char &c) -> char{
        const char r = (lastc == ' ' || ñastc == 0) ? toupper(c) : tolower(c);
        lastc = c; 
        return r;
    });
    puts(s);
    return 0;
}
```
``` [&lastc] ``` - this is called the capture. In this case is capturing a reference to the _lastc_ variable. That means that the lambda function can use this variable as a reference.  
``` (const char &c)```- This is the parameter list, sames as a normal function.
```->``` Function return operator. In this example, it says that the function return a character.
```{ .. }``` - Body of the function.

Lambda are used for circuntances where you would otherwise use a _functor_ or _function pointer_ but you don't really need to reuse the code.

##### Captures 
Lambda functions have several options for capturing variables outside the lambda scope.
- _[var]_ Capture _var_ by value.
- _[&var]_ Capture _var_ by reference.
- _[=]_ Capture all variables by value.
- _[&]_ Capture all variables by reference.
- _[&, var]_ Capture all by reference, except capture _var_ by value.
- _[&var, var2]_ Capture _var_ by reference, and _var2_ by value.

##### Polymorphic lambdas 
It is possible to construct a minimally polymorphic lambda function. Example:
```c++
int main(){
    double n = 42; 
    auto fp = [](const auto &n) -> auto {return n*4;};
    auto x = fp(n);
    cout << "Value of x: " << x << " Type of x " << typeid(x).name();
    return 0;
}
```
# The C Preprocessor
It provides a number of essential capabilities for both the C and C++ languages.
##### Macros as constants 
One common use for the preprocessor is to define constants. In fact, the preprocessor cannot define constants or any other C++ language object, but it does have a feature that is commonly used  for this purpose: Macro.
```c++
#DEFINE ONE 1 // Don't use a semicolon here. 
              // This is not a real constant, it is a macro.
#DEFINE HELLO "Hello world!"
int main(){
    cout << "One is " << ONE << endl;
    return 0;
}
```
Every occurrence of the word ONE will be replaced with the literal one. IT could be problematic. The literal value is not type, it's a literal value. You can tun into namespace collisions and make debugging very challenging.
##### Including files
Typiucally you will have one or more ```#include```directives at the top of each file. This is the most common or the most visible use of the preprocessor. The pre-processor replaces the include directive with the contents of their respective included header files; Then passes that combined filte to the compiler.
```c++
#include <stdio>
#include "myfile.h"
```
##### Conditional compilation 
The C pre-processor provides a number of directiver for conditional compilation: `#if`, `#ifdef`, `#ifndef`, `else`, `elif`, `endif`. And this two special cases: `#if defined (MARCO)`, `if !defined(MACRO)`-
```c++
#ifndef CONDITIONAL_H_
#define CONDITIONAL_H_

#ifdef NUMBER
#undef NUMBER
#endif

#ifdef FOO
# define NUMBER 47
#else
# define NUMBER 3
#endif

#endif /* CONDITIONAL_H_ */
//--- New program that includes the previous file ---
int main(){
    cout << NUMBER << endl; // Will print 3 because we didn't define FOO
}
```
##### Macros 
The C pre-processor provides a powerful and flexible macro system. 
```c++
#define TIMES(a, b) (a * b)
#define MAX(a, b)(a > b ? a : b)
int main(){
    int bob = 5; 
    int fred = 7;
    cout << "Macro returns: " << TIMES(5, 25) << endl; // Macr--- ns 125
    cout << "Max between fred and bob is " << MAX(bob, fred) << endl; // 7
    return 0;
}
```
##### Include guard
When a header file is included by other header files, there is a possibility that a particular header file could be included more than once and this can create errors, for that reason we need an _include guard_. 
```c++
#ifndef __INCLUDE_MYCLASS // Check is my class is defined
#define __INCLUDE_MYCLASS // if no it includes the entire file
...
#endif // __INCLUDE_MYCLASS
```
# Templates 
IT is essentially a compiler abstraction that allows you to write generic code that applies to various types or classes without concern for the details of the type.
```c++
template <typename T>  
T maxof (const T Ta, const T &b){
    return (a > b ? a : b);
}
int main(){
    int a = 7;
    int b = 9; 
    cout << "Max is " << maxof<int>(a, b) << endl; // Max is 9
    return 0;
}
```
When a ```template``` is called, the compiler creates a specialization. The specialization is effectively a compy of the function specifically for a given set of types. So, in our example the next function is created in compile time (invisible to the programmer).
```c++
int maxof(const int &a, const int &b){
    return (a > b ? a:b);
}
```
The specializations ensure that the templates are type safe, but this also imposes overhead.
##### Template variables
C++ 14 provides a new template implementation for strongly typed variables.
```c++
template <typename T>
T pi = T(3.14159265358979L);

int main (){
    cout.precision(20);
    cout << pi<double> << endl;
    return 0;
}
```
Template classes and template class implementation in a same file to avoid a linking error. 
# STL containers 
STL containers share a number of common features in order to make them convenient and easy to use. The point of STL containers is to make common data structures available to any compatible type or class. 
##### Vector 
It holds objects in a strict sequential order. ```#include <vector>```
```c++
// Template to print elements of a vector
template <typename T> 
void printv(vector<T> &v){
    if(v.empty()) return;
    for(T &i : v) cout << i << " ";
    cout << endl;
}
int main(){
    vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printv(v1); // 1 2 3 4 5 6 7 8 9
    
    // info 
    cout << (int) v1.size() << endl;  // 10
    cout << v1.front() << endl; // 0
    cout << v1.back() << endl; // 9
    
    // index
    cout << v1[5] << endl; //4
    cout << v1.at(3) << endl; // 2
    
    // insert 
    v1.insert(v1.begin()+5, 42); // insert 42 at begin+5
    v1.push_back(42); // insert at the end
    
    // erase
    v1.erase(v1.begin()+5); // Erase at begin+5
    v1.pop_back(); // Erase at the end
    
    // filled with strings 
    vector <string> v2(5, "ab");
    printv(v2); // ab ab ab ab ab
    
    // Vector copied from vector 
    vector<string> v3(v2);
    printv(v3); // ab ab ab ab ab
    
    // Vector 4 moved from vector 3
    vector<string> v4(std::move(v3);
    printv(v4); // ab ab ab ab ab
    
    return 0;
}
```