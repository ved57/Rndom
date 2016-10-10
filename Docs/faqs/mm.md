### 1) How does implementation of new call look like?
```c++
//Concise:
Fred *p = new Fred();

//Expanded:
Fred *temp;
try{
  temp = new (sizeof Fred);
  p = new (temp) Fred();
}
catch(...){
  delete temp;
  p = nullptr;
}  
```

### 2) How does implementation of delete call look like?
```c++
//Concise:
delete p;
Expanded:
if (p){
  p->~Fred();
}
```

### 3) Why is the size of an empty class not zero?
To ensure that the addresses of two different objects will be different. For the same reason, new always returns pointers to distinct objects.


### 4) What is the use of placement new?
To place an object at a particular location in memory. The syntax is same as new operator except we have to use 
new *(ptr_to_place)* Constructor().
``` c++
//Example:
void someCode()
{
  char memory[sizeof(Fred)];     // Line #1
  void* place = memory;          // Line #2
  Fred* f = new(place) Fred();   // Line #3 (see "DANGER" below)
  // The pointers f and place will be equal
  // ...
}
```

