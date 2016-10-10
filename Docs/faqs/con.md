### 1) Is the default constructor for Fred always Fred::Fred()? 
No. 
Rule for default constructor is that it should be callable without arguments. So a default parameterized constructor could act as default constructor.
https://isocpp.org/wiki/faq/ctors#default-ctor

### 2) How to create array of objects using non-default constructor?

``` c++
class Fred {
public:
  Fred(int i, int j);      // Assume there is no default constructor
  // ...
};
int main()
{
  Fred a[10];              // ERROR: Fred doesn't have a default constructor
  Fred* p = new Fred[10];  // ERROR: Fred doesn't have a default constructor
  Fred a[10](5,7);              // ERROR: Fred doesn't have a default constructor
  Fred* p = new Fred[10](5,7);  // ERROR: Fred doesn't have a default constructor
  //BEST SOLUTION
  std::vector<Fred> a(10, Fred(5,7));  // The 10 Fred objects in std::vector a will be initialized with Fred(5,7)
  //HACK/UGLY/YET_VALID solution
  Fred a[10] = {
    Fred(5,7), Fred(5,7), Fred(5,7), Fred(5,7), Fred(5,7),  // The 10 Fred objects are
    Fred(5,7), Fred(5,7), Fred(5,7), Fred(5,7), Fred(5,7)   // initialized using Fred(5,7)
  };  
}
```

### 3) Why to use initializer-list in constructors?
__Performance__
Avoids creation of a temporary object and then assigning to the data member.
__Invalid Usage__
non-static reference and non-static const members can be initialized only in init list.

