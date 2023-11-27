#include<iostream>
#include<assert.h>
using namespace std;

// create a class of Vector with capital V
class Vector {
    private:
        int capacity {};    // astual size
        int size {0};       // user zise
        int *array = nullptr ;
    
    public:
    // this fun calls (( constructor )) begin with name of the class without datatype
        Vector(int size): size(size){
            if(size < 0)
                size =1;
            capacity = size + 10; // for expanding size with capacity trick
            array=new int [size] {};
        }
    

    //this fun is (( called deconstructor )) begin with ~ 
        ~Vector(){
            delete[] array;
            array = nullptr;
        }

    // let build a set & get functions
        int get(int idx){
            assert(0 <= idx && idx < size); // to check if the idx in range
            return array[idx];
        }

        void set(int idx, int val){
            assert( 0 <= idx && idx < size);
            array[idx] = val;
        }

    // to print all items of vector
        void print(){
            for(int i=0; i < size; ++i)
                cout<<array[i]<<" ";
            cout<<"\n";
            }

    // to find a value in vector and return its index
        int find(int val){
            for(int i=0; i < size; ++i)
                if(array[i] == val)
                    return i;
            return -1; // for not found value
        }

    // creat a fun to add item to end of vector befor //! capacity Trick
    /*//*  void push_back(int value){
            int *array_02 = new int[size+1]; // 1. creat new array
            for(int i=0; i < size; ++i)      // 2. copy old element
                array_02[i] = array[i]; 
            array_02[size++] = value;        // 3. putting the new value 
            swap(array,array_02);            // 4. swapping the pointer form old arr to new one
            delete[] array_02;               // 5. delete the new array

        }
    */
    //? now to push_back new item we creat 2 fun 1. to push_back 2. to expand size
        void push_back(int value){
            if (size == capacity)
                expand_capacity();
            array[size++] = value;
        }

    // fun to expand the size of array
        void expand_capacity(){
            capacity*=2; // doubling the size of pointerd array
            cout<< "expand capacity to "<< capacity << "\n";
            int *array_02 = new int[capacity] {}; 
            for(int i=0; i < size; ++i)
                array_02[i] = array[i];  
            swap(array,array_02);
            delete[] array_02;
        }

    // bulit a fun insertion operation to insert item in any place
        void insert(int value, int idx){
            assert(idx < 0 && idx > size); // to check is idx valid

            if (size == capacity)  // check there is place to add item using capacity trick
               expand_capacity();

            for(int i = size-1; i >= idx; --i) // to shifting right
                array[i+1] = array[i];
            
            array[idx] = value; // putting the value
            ++ size;

            }
                

        

};


int main(){
    int n=4;
    Vector v(n);


    return 0;
}