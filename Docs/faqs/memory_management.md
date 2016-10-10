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
