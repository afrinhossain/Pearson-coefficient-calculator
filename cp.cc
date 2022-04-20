/*
This is the function you need to implement. Quick reference:
- input rows: 0 <= y < ny
- input columns: 0 <= x < nx
- element at row y and column x is stored in data[x + y*nx]
- correlation between rows i and row j has to be stored in result[i + j*ny]
- only parts with 0 <= j <= i < ny need to be filled
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>

void correlate(int ny, int nx, const float *data, float *result) {
    std::vector<double> tempmatrix(nx * ny);
    double avg,sumofsquares ; 
    
    for(int row = 0; row < ny; row++){
        avg = 0;
        sumofsquares = 0;
        for(int col = 0; col < nx; col++){
            avg = avg + double(data[col + row*nx]);
        }
        avg = avg/nx;

        for(int col = 0; col < nx; col++){
            tempmatrix[col + row*nx] = data[col + row*nx]-avg;
            sumofsquares = sumofsquares +double(tempmatrix[col + row*nx]*tempmatrix[col + row*nx]);
        }
        
        //normalize the input rows so that each row has the arithmetic mean of 0
        for(int col = 0; col < nx; col++){
            tempmatrix[col + row*nx] = tempmatrix[col + row*nx]/sqrt(sumofsquares);
        }
        

    }
    double x; 
    for(int row = 0; row < ny; row++){
        for(int col = 0; col < ny; col++){
            if(row <= col){
                x= 0;
                for(int k = 0; k < nx; k++){
                    //printf("row = %d, col = %d,k = %d\n ",row, col,k);
                    x =x +tempmatrix[k + row*nx]*tempmatrix[k + col*nx]; 
                    
                result[col + row*ny] = float(x); 
                }
            }
        }
    }
    
   //free(tempmatrix);

}






