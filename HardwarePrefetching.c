#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>


int main(void){
    struct timeval t1, t2;
    double elapsedTime;
    gettimeofday(&t1, NULL);
    
    int N = 1000;
    int array[N*N];
    //Accesses an array sequentially in rowMajor 
    for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                array[i*N+j]+=j;
            }
        }
        
    gettimeofday(&t2, NULL);
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; 
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
    printf("%f ms.\n", elapsedTime);
    
    struct timeval t3, t4;
    double elapsedTime2;
    gettimeofday(&t3, NULL);
    
    //Accesses an array randomly (Strided) 
    for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++) {
                array[j * N + rand() % N]+=j;
            }
    }
    gettimeofday(&t4, NULL);
    elapsedTime2 = (t4.tv_sec - t3.tv_sec) * 1000.0; 
    elapsedTime2 += (t4.tv_usec - t3.tv_usec) / 1000.0;
    printf("%f ms.\n", elapsedTime2);
    
    
}