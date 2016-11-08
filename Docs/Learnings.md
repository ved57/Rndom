## How to convert integer to hex string?
```c++
int n = 5; //number to be converted
stringstream sstr;
sstr<<std::hex<<n; //alternatively we can use the std::oct
string num_str = sstr.str(); //to get the 
'''
