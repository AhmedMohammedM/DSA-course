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
    // worst case time complixity O(n), space complixity O(1)
        void insert(int value, int idx){
            assert(0 <= idx && idx < size); // to check is idx valid
            
            if (size == capacity)  // check there is place to add item using capacity trick
               expand_capacity();

            for(int i = size-1; i >= idx; --i) // to shifting right
                array[i+1] = array[i];
            
            array[idx] = value; // putting the value
            ++ size; // this step to increse the size after adding item

            }
                
    //* Vector Homework_ 5 Medium Challenges
    // problem 1: Right rotation
        void right_rotation(){
            if (size <= 1)  // if the size of vector <= 1 no need to rotation
                return;

            int last_item = array[size-1]; // copy the last element of vector
            for (int i = size-2; i >= 0; --i)  // right shifting 
                array[i+1] = array[i];
            array[0] = last_item;  // put last element at first postion in the vector
        }

    // problem 2: Left rotation
        void left_rotation(){
            if(size <=1)
                return;
            
            int first_item = array[0];
            for(int i=1; i < size; ++i)
                array[i-1] = array[i];
            array[size-1] = first_item;
        }

    // Problem 3: Right rotation with steps
    // method one reuse the fun right_rotation n times

        /*void right_rotate(int stepNumber){

            stepNumber %=  size; // to minimize the time of rotation

            while(stepNumber){
                right_rotation();
                -- stepNumber;
            }

        }
*/
    // second method time O(n), space O(n)
    /*  1. create new array
        2. copy element starting with size-times to end
        3. copy element starting at 0 location ending size - times 
        4. swaping between the arrays
        5. delete the the temprary one
    */
        void right_rotate(int stepNumber){

            stepNumber %=   size; // to minimize the time of rotation
            int *array2 = new int [size];
            for(int i =  size - stepNumber , j = 0 ; i<size ; i++,j++)
                array2[j] = array[i];
            for(int i = 0 , j = stepNumber ; i < size - stepNumber ; i++, j++ )
                array2[j] = array[i];
            swap(array,array2);
            delete[] array2;
        }

    // Problem 4: Deleting a position & returns the deleted value
        int pop(int idx){
            assert(0 <= idx && idx < size); // to check is idx valid
            int value = array[idx];
            for(int i = idx; i < size; ++i) // to left shift items from idx to end of array 
                array[i] = array[i+1];
            --size; // minimize the size

            return value;
        }

    // Problem 5: Improved search - each time you find the value, you shift it one step to the left
    // time O(n), space O(1)
        int find_transposition(int value){
            
            for(int i = 0; i < size; ++i){
                if (array[i] == value){
                    if (i == 0)
                        return 0;

                    swap(array[i],array[i-1]);
                    return i-1;
                }
            }
            return -1 ;
        }
};


int main(){
    int n=4;
    Vector v(n);
    for(int i = 0; i < n; ++i)
        v.set(i,i);
    v.push_back(23);
    v.print();
    cout<< v.pop(2)<<"\n";
    v.print();
    v.find_transposition(23);
    v.print();
    return 0;
}