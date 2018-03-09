# First example for data_structures

## After clone run de command:
```
$ g++ main.cpp -o hello_world -std=c++11 -Werror
```
### In my case i have this error output:

```
In file included from main.cpp:1:0:
myclass.hpp: In member function ‘void MyClass<T>::foo()’:
myclass.hpp:7:13: error: ‘cout’ was not declared in this scope
         std:cout<<"Hello_World!"<<std::endl;
             ^~~~
myclass.hpp:7:13: note: suggested alternative:
In file included from myclass.hpp:1:0,
                 from main.cpp:1:
/usr/include/c++/7/iostream:61:18: note:   ‘std::cout’
   extern ostream cout;  /// Linked to standard output
```


<a href="https://raw.githubusercontent.com/diogon01/C-plus-Languege/master/data_structures/media_sources/errorHeaderExample.png" 
target="_blank">
        <img src="https://raw.githubusercontent.com/diogon01/C-plus-Languege/master/data_structures/media_sources/errorHeaderExample.png" 
        alt="Error Header Example" width="50%" height="50%" />
</a>
