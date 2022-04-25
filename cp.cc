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
#include <iostream>

void correlate(int ny, int nx, const float *data, float *result) {
    int m0= 4;
    int extra = m0 - nx % m0;
    double innersum;
    double x[m0];
    double outersum; 
    int new_nx = new_nx;
    int chunks = new_nx / m0;
    std::vector<double> tempmatrix((new_nx)*ny );

    double avg,sumofsquares; 
    for(int row = 0; row < ny; row++){
        avg = 0;
        sumofsquares = 0;
        for(int col = 0; col < nx; col++){
            avg = avg + (data[col + row*nx]);
        }
        avg = avg/nx;

        for(int col = 0; col < nx; col++){
            tempmatrix[col + row*(new_nx)] = data[col + row*nx]-avg;
            sumofsquares += tempmatrix[col + row*(new_nx)]*tempmatrix[col + row*(new_nx)];
        }
        
        //normalize the input rows so that each row has the arithmetic mean of 0
        for(int col = 0; col < nx; col++){
            tempmatrix[col + row*(new_nx)] = tempmatrix[col + row*(new_nx)]/sqrt(sumofsquares);
            
        }
        
        if( extra != 0){
            for(int m = 0; m < extra; m++ ){
                
                tempmatrix[nx + m + row*(new_nx)] = 0;
            }
            
        }

        

    }
    
    for(int row = 0; row < ny; row++){
        for(int col = 0; col <= row ; col++){
            outersum = 0;
            for(int j = 0; j < chunks; j++){
                innersum = 0; 
                for(int m = 0; m < m0; m++){
                    x[m] = tempmatrix[j*m0 + m + row*new_nx] * tempmatrix[j*m0 + m + col*new_nx];
                }
                
                for(int m = 0; m < m0; m++){
                    innersum += x[m];
                }
                outersum += innersum;
            }
            
            result[row + col*ny] = outersum;
        }

    }
    
    
   

}
          
        
