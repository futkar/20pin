#include<stdio.h>

/* Hashmap is a DS that allows kay-value mappings to be stored.

* Biggest benefit is that lookup is O(1) which means that lookup is constant time irrespective 
* of how big the hashmap grows.

* If does require a good hash funcion that takes the key as input and converts it into a unique hash.
* This part is slightly tricky because hash function output should be unique and hence avoid collisions.This
* By collision we mean that no two key values should result in same hash. Because in that case, two 
* different keys would map to the same value, and this means overwritten value everytime this happens.differen.
*/

/*
  So for a layman, writing hello worls style hashmap, what would be the bare minimum needs ?
  Can we use an array to store values, somehow consider array index as the key ? Well why not. 
  Let's try
*/

struct HashMap{
   
 int ds [10]; 
  /*
    Obviously this is hello world style program, and so our hashmap is limited to size 10 for now
    */
 /*
  As far as I remember, no matter how smart the program gets, if we're making use of arrays to 
  hold the hashmap, size cannot be dynamic.
  TODO: to refactor this program to use a DS that lets our Hashmap's size to be dynamic.
  */
  
};

//initialize hashmap();
struct HashMap hm;
  /* I literally had to google how to create and initialize a structure, 
  * it has been a while since I wrote any C code. I almost did hm = new HashMap() and then remembered
  * that we're not in C++ land yet. 
  
  But well, the above statement does it, it initializes that hashmap and since every memeber inside
  a structure is public by default, we can just manipulate (read or write) array from here, the main() function*/

int hashFunciton(){
  
  return 0;
}

int get(int key){
  return hm.ds[key];
  
}
void put(int key, int value){
  hm.ds[key]=value; 
}  

//size of hashmap  
int size(){
  
  /*
  Now I cannot equate the size of the array to the size of hashmap. I have to assume that
  let's say, a value of 0 means that the hashmap is empty at that array location. So hey, I needs
  to initialize my array (the hashmap DS) to zero at the very beginning. 
  */
  return 0;
  
}
 
//This is such a wasteful function, but well we have to assume zero state of the hashmap
void initialize(){
  
  int i;
  for(i=0;i<10;i++){
    hm.ds[i]=0;
    
  }
}

void main(){
  
  printf("Hello world! - Hashmap");
  initialize();
  
  put(0,1984);
  /*
  I almost called this as hm.put(0,1984) and then had to google again, if functions were allowed
  inside a structure. And turns out that they're not. That sucks. But this also means that there 
  almost is no room for this program to be any fancy because of my choice of a limiting DS, C structure,
  and so this program's fate is bound to remain in the 'hello world' territory for eternity.
  */
  put(1,1947);
  put(2,2012);
  //hm.put(0,1984); //would have been a collision, because, look at the key passed.
  
  printf("\nHashmap value for key 0: %d",get(0));
  printf("\nHashmap value for key 1: %d",get(1));
  printf("\nHashmap value for key 2: %d",get(2));
  
  printf("\nHashmap value for key 3: %d",get(3));
  /*
  Thank god I initialized my hashmap (array) to a zero state (value zero), otherwise this key would have
  yielded a garbage value!
  */
 
}
/*
So there it is, ladies and gentleman, a hello-world style hashmap (which is noting but a glorified array! 
but at least I wrote a C program after such long and this indeed serves as a hashmap tutorial ;) ).   
*/


/*
Errors seen: 

1. Well it had almost been 6 years since I last wrote any C code and I forgot that the sequence of 
declarations is also important in C. We cannot use something before it is declared. I have my 
'struct HashMap hm' declaration after the functions get(), put() etc. which were making use of the 
hm structure. And C didn't like it. So I had to take the declaration all the way to the top.

2. C also didn't let me declare int i inside of the for loop. I had to take the declaration of i 
outside and before the loop started. 




*/