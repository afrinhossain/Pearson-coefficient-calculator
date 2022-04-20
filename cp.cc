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

//Using https://en.wikipedia.org/wiki/Pearson_correlation_coefficient

void correlate(int ny, int nx, const float *data, float *result) {
    double avgi = 0;
    double avgj = 0;
    double rij = 0;
    double ri = 0;
    double rj= 0;

    for(int j = 0; j <= ny ; j++){
        
        for(int i = 0; i < ny ; i++){
            
            if (i >= j ){
                //for both i and j  row first compute avg
                avgi = 0;
                avgj = 0;
                ri = 0;
                rj= 0;
                rij= 0;

                for (int col =0; col < nx; col++ ){
                    //printf("%f\n",data[col + i*nx]);
                    avgi = avgi + data[col + i*nx];
                    avgj = avgj + data[col + j*nx];
                }
                avgi = avgi/nx;
                avgj = avgj/nx;
                
               
                //compute the pearson correlation coefficient 
                for(int col =0; col < nx; col++ ){
                    rij = rij + ((data[col + i*nx]-avgi)*(data[col + j*nx]-avgj));
                    ri = ri + ((data[col + i*nx]-avgi)*(data[col + i*nx]-avgi));
                    rj = rj + ((data[col + j*nx]-avgj)*(data[col + j*nx]-avgj));
                    

                }
                 
                result[i + j*ny] = float(rij/(sqrt(ri)*sqrt(rj)));
            }
        }
        
}





}