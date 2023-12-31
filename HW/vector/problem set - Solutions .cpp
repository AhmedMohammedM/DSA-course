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