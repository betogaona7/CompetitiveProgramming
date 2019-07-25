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
    cout << (int) v1.size() << emdñ;  // 10
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
    printv(v4) // ab ab ab ab ab
    
    return 0;
}
```
##### List
List is like a vector but optimized for rapid insert and delete operations. List don't support random access. ```#include <list>```
```c++
// Template function to print list
template <typename T>
void printl(list <T> &l){
    if(l.empty()) return;
    for(T &i : l) cout << i << " ";
    cout << endl;
}
int main(){
    list <int> l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printl(l1);
    
    // info
    cout << (int)l1.size() << endl; // 9
    cout << l1.front() << endl; //1
    cout << l1.back() << endl; // 9
    
    // Insert an element at the back
    l1.push_back(7);
    printl(l1); // 1 2 3 4 5 6 7 8 9 7
    
    // Need am iterator to insert and erase
    list<int>::iterator it1 = l1.begin();
    while((*++it1 != 5) && (it1 != l1.end()));
    if (it1 != l1.end()){
        l1.insert(it1, 112); // insert 112 before 5
    }
    printl(l1); // 1 2 3 4 112 5 6 7 8 9 7
    
    // Find elelemt value 7 and erase it 
    while((*++it1 != 7) && (it1 != l1.end()));
    if(it1 != l1.end()){
        l1.erase(it1);
    }
    printl(l1); // 1 2 3 4 112 5 6 8 9 7
    
    // Remove all element which value is 8
    l1.remove(8);
    printl(l1); // 1 2 3 4 112 5 6 9 7
    
    // Erase a range of values 
    auto it2 = it1 = l1.begin();
    while((*++it1 != 112) && (it1 != l1.end()));
    while((*++it2 != 9) && (it2 != l1.end()));
    if (it1 != l1.end() && it2 != l1.end()){
        l1.erase(it1, it2);
        printl(l1); // 1 2 3 4 9 7
    }
    return 0;
}
```
Excelent choice for situations where you don't need random access and you'll be inserting and removing a lot of elements.
##### Pair and tuple
They are used in places where you want to carry multiple. strongly typed values. In some cases they can be more convinient than a _struct_. ```#include <utility>```
```c++
// Template to print the pair
template <typename T1, typename T2> 
void printpair(pair<T1, T2> &p){
    cout << p.first << " : " << p.second << endl;
}
int main(){
    // initializer list
    pair<int, string> p1 = {47, "forty-seven"};
    // default constructor 
    pair<int, string> p2(72, "seventy-two");
    // from make_pair
    pair <int, string> p3;
    p3 = make_pair(7, "seven");
    printpair(p3); // 7 : seven
    
    // comparison operators (compares both values, but gives priority to 
    // the first one )
    cout << p1 == p2 << endl; // 0
    cout << p1 < p2 << endl; // 1
    cout << p1 < p3 << endl; // 0
    cout << p1 > p2 << endl; // 0
    cout << p2 > p3 << endl; // 1
    return 0;
}
```
Tuples can be many different sizes.
```c++
// print element of the tuple 
void print3tuple(T t){
    auto tsz = tuple_size<decltype(t)>::value;
    if(tsz != 3) return;
    cout << get<0>(t) << " : " << get<1>(t) << " : " << get<2>(t) << endl;
}
int main(){
    tuple<int, string, int> t1 = {47, "forty-seven", 1 };
    tuple<int, string, int> t2(73, "seventy-two", 2);
    auto t3 = make_tuple(7, "seven", 3);
    return 0;
}
```
##### Array
It is a fixed-size sequence container. The size of the array is defined when the array object is created, and it cannot change during the life if the array. Its elements are guaranteed to be stored in contigous memory locations.```#include <array>```
```c++
//print elements of the array
template <typename T, size_t N>
void printa(array<T, N> &a){
    for(T &i : a) cout << i << " ";
    cout << endl;
}
int main(){
    array<int, 5> a1 = {1, 2, 3, 4, 5};
    array <string, 5> a2;
    a2 = {"one", "two", "three"};
    printa(a2); // one two three
    
    // check size 
    cout << a1.size() << endl; // 5
    
    // access elements
    cout << a1[3] << endl; // 4
    cout << a1.at(3) << endl; // 4
    
    // direct access data
    int * ip1 = a1.data()
    for(size_t i = 0; i < a1.size(); ++i){
        cout << "element " << i << " is " << *ip1++ << endl;
    }
    return 0;
}
```
##### Deque 
It is  double-ended queue. It is optimized for rapid push and pop from its ends. It is most often uses as the default container for queues and stacks. ```#include <deque>```
```c++
// print deque 
template <typename T> 
void printdeq(T &d){
    if(d.empty()) return;
    for (auto v:d) cout << v << " ";
    cout << endl;
}
int main(){
    deque<string>d1 = {"one", "two", "three"};
    
    d1.push_back("four");
    d1.push_front();
    d1.push_back();;
    
    d1.pop_front();
    d1.pop_back();
    return 0;
}
```
##### Queue 
First in, first out. ```#include <queue>```. It uses an underlying container, the default is _deque_.

```c++
// report queue 
template <typename T>
void report_queue(T &q){
    size_t sz = q.size();
    cout << "size: " << sz;
    if(sz) cout << " front: "<< q.front() << " back " << q.back();
    cout << endl;
}
int main(){
    // queue from a list 
    list<int> l1 = {1, 2, 3, 4, 5};
    queue<int, list<int>> qi(l1);
    report_queue(q1); // size: 5 front: 1 back: 5
    
    // pop all from q1
    while(!q1.empty()){
        cout << q1.front() << " "; 
        q1.pop();
    }
    cout << endl;
    
    // Default queue (deque)
    queue<string> q2;
    
    // push strings onto q2
    for(string s:{"one", "two", "three", "four", "five"}){
        q2.push(s);
    }
    return 0;
}
```
##### Stack
Last in, first out. Like the _queue_, its underlying container is a _deque_. ```#include <stack>```.
```c++
template <typename T>
void reportstk(T &stk){
    cout << "size: " << stk.size();
    if(stk.size()) cout << " top: "<< stk.top();
    cout << endl;
}
int main(){
    vector<int> v1 = {1, 2, 3, 4, 5};
    stack<int, vector<int>> stk1(v1);
    reportstl(stk1);
    
    stk1.push(6);
    stk1.pop();
    
    // pop all from stk1
    while(!stk1.empty()){
        cout << stk1.top() << " ";
        stk1.pop();
    }
    cout << endl;
    
    // create using default container (deque)
    stack <string> stk2;
    return 0;
}
```
##### Set
It holds a sorted set of elements. The _set_ class holds only unique elements where _multisets_ class allows duplicates. _unordered_set_doesn't sort elements and instead provides hashed keys for faster access. ```#include <set>```, ```#include <unordered_set>```.
```c++
// print elements of the set 
template <typename T>
void print_set(T &s){
    if(s.empty()) return;
    for(auto x:s) cout << x << " ";
    cout << endl;
}

int main(){
    set<string> set1 = {"one", "two", "three"};
    set1.insert("four");
    print_set(set1) // four one three two (alphabetical order)
    
    // find and erase aelement four
    set<string>::iterator it = set1.find("four");
    if(it != set1.end()){
        set1.erase(it);
    }else{
        cout << "Not found" << endl;
    }
    
    set1.insert("three") // Won't do anything because I already have a three
    
    // Check if inserting fails
    auto r = set1.insert("three");
    if(!r.second) cout << "Insert failed" << endl;
    
    // multiset 
    multiset <string> set2 = {"one", "two", "three"};
    set2.insert("three") // It inserts three again. Still ordened.
    
    // unordered set
    unordered_set<string> set3 = {"one", "two", "three"}; // saved in any order
    set3.insert("four");
    
    // find and erase element two
    auto it2 = set3.find("two");
    if(it2 != set3.end()){
        set2.erase(it2);
    }else{
        cout << "Not found" << endl;
    }
    return 0;
}
```

Sets are usefil in cases where you need an ordered set of objects that you can search, but you don't need random access. Or unoredered sets, with faster access using hash searches. Use multiset if you need duplicates.

##### Map
It provides a sorted set of key-value pairs. ```#include <map>```.
```c++
// print pair
tempĺate <typename T1, typename T2>
void print_pair(pair<T1, T2> &p){
    cout << p.first << " : " << p.second << endl;
}
// print the elements of the map
template <typename T> 
void print_map(T &m){
    if(m.empty()) return;
    for(auto x : m)  print_pair(x);
    cout << endl;
}
int main(){
    map<string,string> mapstr = {{"George", "Father"},
                                 {"Ellen", "Mother"},
                                 {"Ruth", "Daughter"}};
    cout << "size " << mapstr.size() << endl;
    cout << "George " << mapstr["George"] << endl;
    cout << "Ellen" << mapstr.at("Ellen") << endl;
    cout << "Spike" << mapstr.find("Spike")->second << endl;
    
    mapstr.insert({"Luke", "Neighbor"}); 
    
    // insert duplicate 
    auto rp = mapstr.insert({"Luke", "Neighbor"});
    if(rp.second){
        cout << "inserted" << endl;
    }else{
        cout << "Instert failed" << endl;
    }
    
    // find and erase
    auto it = mapstr.find("Spike");
    if(it != mapstr.end()){
        mapstr.erase(it);
    }
   return 0; 
}
```
_map_ doesn't accept duplicates. _multimap_ does.
# STL Iterators 
An iterator is an STL object that can iterate through the elements of a container. It acts a lot like a pointer. It can be incremented and de-referenced as if it were a pointer.```#include <iterator>```. Example:
```c++
int main(){
    vector <int> v1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int>::iteratpr it1 // iterator object
    
    vector <int>::iterator ibegin = v1.begin();
    // auto ibegin = v1.begin();
    vector<int>::iterator iend = v1.end();
    
    for(it1 = ibegin; it1 < iend; ++it1){
        cout << *it1 << " "
    }
    cout << endl;
    return 0;
}
```
##### Input iterator
It is the simplest and most limited form of iterator. It may be used to read values of an object once and then increment. It cannot write. cannot decrease, and cannot read a value twice.  _isotream_ uses an input operator for _cin_.
```c++
int main(){
    double d1 =, d2 = 0;
    cout << "Two numeric values: " << flush;
    cin.clear();
    istream_iterator<double> eos;      //default constructor is end-of-stream
    istream_iterator<double> iit(cin); //stdin interator
    
    if(iit == eos){
        cout << "No values" << endl;
        return 0;
    }else {
        d1 = *iit++;
    }
    if(iit == eos){
        cout << "No second value" << endl;
        return 0;
    }else{
        d2 = *iit;
    }
    cin.clear();
    cout << d1 << " * " << d2 << " = " << d1*d2 << endl;
    return 0;
}
```
##### Output iterator
It is the complement of the input operator. It may be used to write a value once and then increment.
```c++
int main(){
    ostream_iterator<int> output(cout, " ");
    for(int i : {3, 197, 42}){
        *output++ = i;
    }
    cout << endl;
    return 0;
}
```
##### Forward iterator
It is like a combination of input and output iterators with a few other capabilities. The _forward_list_ is a sinle linked list type. 
```c++
#include <forward_list>
int main(){
    forward_list<int> fl1 = {1, 2, 3, 4, 5};
    forward_list<int>::iterator it1; // forward iterator
    
    for(it1 = fl1.begin(); it1 != fl1.end(); ++it1){
        cout << *it1 << " ";
    }
    cout << endl;
}
```
##### Bidirectional iterator 
It may be used to access the sequence of a container in either direction. _set_ uses this iterator. 
```c++
int main(){
    set<int> set1 = {1, 2, 3, 4, 5};
    set<int> :: iterator it1 // iterator object
    
    // iterate forward 
    for(it1 = set1.begin(); it1 != set1.end(); ++it1){
        cout << *it1 << " ";
    }
    cout << endl;
    
    // iterate backward 
    for(it1 = set1.end(); it1 != set1.begin();){
        cout << *--it1 << " ";
    }
    cout << endl;
    
    // range-based for loop
    for(int i : set1){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
```
##### Random access iterator
It is the most complete of all. It may be used to access any element at any position in a container. It offers all of the functionality of a C pointer.
```c++
int main(){
    vector <int> v1 = {1, 2, 3, 4, 5};
    vector<int>::iterator it1;
    
    // iterate forward 
    for(it1 = v1.begin(); it1 != v1.end(); ++it1){
        cout << *it1 << " ";
    }
    cout << endl;
    
    // iterate backward 
    for(it1 = v1.end(); it1 != v1.begin();){
        cout << *--it1 << " ";
    }
    cout << endl;
    
    it1 = v1.begin() + 5
    cout << "Element begin + 5" <<  *it1 << endl;
    cout << "Element [5]" << v1[5] << endl;
    
    it1 = v1.end() - 3;
    cout << "Element end -3 " << *it1 << endl;
    
    return 0;
}
```
# Transformations
```#include <algorithm>```
##### Transform function
It is used to run bulk transformations on elements in a container.```transform``` takes four arguments: 
- Starting point iterator, it is an input operator.
- Input operator for the endpoint of the source container.
- Begin point of the destination container. It is an otput operator.
- An object operator. It is a unary function, so it's a pointer to either a function or object functor that takes one argument.
```c++
template <typename T>
class accum { // accumulates value
        T _acc = 0;
        accum(){}
    public: 
        accum(T n) : _acc(n){}
        T operator()(T y){_acc += y; return _acc;}
};
template <typename T>
void disp_v (vector<T> &v){
    if(!v.size()) return;
    for(T e: v){cout << e << " "; }
    cout << endl;
}

int main(){
    accum <int> x(7);
    cout << x(7) << endl; // 14
    vector<int> v1 = {1, 2, 3, 4, 5};
    disp_v(v1); // 1 2 3 4 5
    
    vector<int> v2(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), x);
    disp_v(v2); // 15 17 20 24 29
    return 0;
}
```

##### Lambda transformation
You may also use a lambda function in place of the functor in your transformation.
```c++
template <typename T>
void disp_v (vector<T> &v){
    if(!v.size()) return;
    for(T e: v){cout << e << " "; }
    cout << endl;
}

int main(){
    int accum = 14;
    auto x = [accum](int d) mutable -> int{return accum += d };
    
    vector<int> v1 = {1, 2, 3, 4, 5};
    disp_v(v1); // 1 2 3 4 5
    
    vector<int> v2(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), x);
    disp_v(v2); // 15 17 20 24 29
    
    vector<string> v3 = {"one", "two", "three", "four","five"};
    vector <size_t>v4(v3.size())
    transform(v3.begin(), v3.end(), v4.begin(), [](string &s)-> size_t {
        return s.size();}); 
    disp_v(v4); // 3 3 5 4 4 
    return 0;
}
```
##### Transforming strings
It is a special case, because strings are not containers.
```c++
int main(){
    string s1 = "This is an string";
    
    string s2(s1.size(), '_');
    transform(s1.begin(), s1.end(), s2.begin(), ::toupper);
    cout << s2 << endl; // THIS IS AN STRING
    return 0;
}
```
##### Binary transformation
The _transform_ functiuon has another form which uses a binary operator. It takes two operands and allows the results to be sent to a third container.
```c++
template <typename T>
class embiggen{
        T _accum = 1;
    public:
        T operator() (const T &n1, const T &n2){ return _accum = n1*n2* _accum; }
};
int main(){
    vector <long> v1 = {1, 2, 3, 4, 5};
    vector <long> v2 = {5, 10, 15, 20, 25 };
    vector <long> v3(v1.size(), 0);
    embiggen<long> fbig;
    
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), fbig);
    disp_v(v1); // 1 2 3 4 5 
    disp_v(v2); // 5 10 15 20 25
    disp_v(v3); // 5 100 4500 360000 45000000
}
```
# Functors
A _functor_ is simple a class with an operator overload for the function called ```operator```.
##### Arithmetic functors.
They are standard template functor defined in ```#include <functional>```
```c++
int main(){
    vector <long> v1 = {26, 52, 79, 114, 183};
    vector <long> v2 = {1, 2, 3, 4, 5};
    vector <long> v3(v1.size(), 0);
   
    plus<long> f; / this is the functor
    // minus, divides, multiplies, modulus, negate
    
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), f);
    disp_v(v3); // 27 54 82 118 188
    return 0;
}
```
##### Relational functors
```c++
template <typename T>
void disp_v(vector<T> &v){
    if(!v.size()) return;
    if(typeid(T) == typeid(bool)){
        for(bool e:v){cout << (e ? "T" : "F") << " ";}
    }else{
        for(T e : v){ cout << e << " "; }
    }
    cout << endl;
}
int main(){
    vector <long> v1 = {26, 52, 79, 114, 183};
    vector <long> v2 = {52, 2, 72, 114, 5};
    vector <long> v3(v1.size());
   
    greater<long> f; / this is the functor
    // less, greater_equal, less_equal, equal_to, not_equl_to
    
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), f);
    disp_v(v3); // F T T F T
    return 0;
}
```
##### Logical functors
Useful for simple applications.
```c++
int main(){
    vector<bool> v1 = {1, 0, 1, 0, 1, 0};
    vector<bool> v2 = {1, 1, 1, 1, 0, 0};
    vector<bool> v3(v1.size(), 0);
    
    logical_and<bool> f;
    // logical_or, logical_not
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), f);
    disp_v(v3); // 1 0 1 0 0 0
}
```
