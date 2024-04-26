## Minh Nhat Nguyen
## Assignment 2 - Banker's Algorithm
## CS33211 - OPERATING SYSTEMS 
## Dr. Qiang Guan
## Kent State University
## 04/26/2024

<br><br>

### Description
"Banker's algorithm is a  deadlock avoidance algorithm developed by Edsger Dijkstra that tests for safety by simulating the allocation of predetermined maximum possible amounts of all resources, and then makes an "s-state" check to test for possible deadlock conditions for all other pending activities, before deciding whether allocation should be allowed to continue" (From Wikipedia).

In this implementation, I read the data from text files, and execute the algorithm all within a C++ file. The items read are integers, and there are 3 text files in total.

<br>

### How to run
This code will only run in a Linux or Unix environment. Once you have the code, navigate to the main folder that contains the Makefile and type
```
make all
```
All codes in the ```code``` folder will compile, including the shared buffer in the header. For more details please consult the documentation.

<br>

### Example
![image](https://github.com/DerrekNguyen/CS33211_Operating-Systems_Assignment-2/assets/143032197/23725078-56df-4471-af22-e493ccf072b2)


### Reference links
https://en.wikipedia.org/wiki/Banker%27s_algorithm
