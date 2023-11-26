#include<iostream>
#include<assert.h>
using namespace std;

// create a class of Vector with capital V
class Vector {
    private:
        int size {};
        int *array = nullptr ;
    
    public:
    // this fun calls (( constructor )) begin with name of the class without datatype
        Vector(int size): size(size){
            if(size < 0)
                size =1;
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
    // creat a fun to add item to end of vector
        void push_back(int value){
            int *array_02 = new int[size+1]; // 1. creat new array
            for(int i=0; i < size; ++i)      // 2. copy old element
                array_02[i] = array[i]; 
            array_02[size++] = value;        // 3. putting the new value 
            swap(array,array_02);            // 4. swapping the pointer form old arr to new one
            delete[] array_02;               // 5. delete the new array

        }

};


int main(){

    Vector v(10);

    return 0;
}