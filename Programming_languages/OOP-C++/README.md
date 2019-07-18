# Classes and objects 
Classes can be defined as ```class``` or ```struct```. The only different is that members on ```struct``` are public by default. It is good practice to use struct when the structure will have only data memembes, and use class where there are also function members.

``` :: ```  scope resolution operator, means that setValue is member function of class1.
``` 
void class1::setValue(int & value){
    i = value; 
}
``` 
##### Programs are often divided in three parts:
```file.h```  are headers files. It contains the class definition. For example:
``` 
class class1{
    int i = 0;
    public: 
        void setVAlue(const int &);
        int getValue() const;
}
``` 

``` file.cpp ``` contains the implementation, the member functions. For example:
``` 
void class1::setValue(const int & value){
    i = value;
}
int class1::getValue() const{
    return i;
}
``` 
``` main.cpp ``` contains everything else. For example:
``` 
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

``` 
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
``` 
Class class1{
    public: 
        class1(); // default constructor
        class1(const string & type, const string & name); // copy constructor
        ~classs1(); //destructor
}
```
``` : ``` is a special initializer that is used with constructors on classes. Example:
``` 
class1::class1():type("unknown"), name("unknown"){
    puts("Constructor with arguments");
}
``` 
Constructors with only one argument can perfom implicit conversion. This is that if it takes in as input an int, and you send it a char like 'x', it implicitly will convert the 'x' to the value of 120, which is the ASCCI value. To avoid this we can add the word ``` explicit ``` . Example:
``` 
class class1{
        public:
            explicit class1(const int & value);
}
``` 

##### Namespaces 
A tool to avoid name collisions. Typically they are defined on header files.
``` 
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
``` 
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
``` 
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
``` 
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
``` 
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