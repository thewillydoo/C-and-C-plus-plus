
#ifndef LAB04_BUFFER_H
#define LAB04_BUFFER_H

#define BUFFER_SIZE 64

// this function fills input buffer using values
// obtained with the function get_value()
int reading();


// this function transfers data between two buffers
// it is used to transfer data from input buffer to local buffer
void transferringTOlocal(int*);



// this function performs processing of data in local buffer
// and put results back into local buffer
void processing(int*);

// this function transfers data between two buffers
// it is used to transfer data from local buffer to output buffer
void transferringFROMlocal(int*);

// this function submit the results stored
// in output buffer for validation
void submitting();

#endif //LAB04_BUFFER_H


