#include<stdio.h>
#include "io.h"
#include "laplace_fdm.h"
#include<math.h>
void main() {
int i=0;
int n[2];
double T[20][20],t[5],other[2];
char file_output[]="output.txt";
char file_input[]="input.txt";
get_data(file_input,n,t,other); //read the data
initialize_temp(T,n,t); //initialize the array with given boundary conditions	
solve_laplace(T,n,other[0],other[1]);//Solve 
write_data(file_output,T,n); //output file
return;
}
