#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}


int main(void) {
  srand(time(NULL));  
  struct timeval t1, t2;
  double elapsedTime;
  struct timeval t3, t4;
  double elapsedTime2;
  int number = 1000;
  int a[number];
  int b[number];

  for (int i = 0; i < number; i++){
    a[i] = rand(); 
    b[i] = rand();
  }
  gettimeofday(&t1, NULL);
  for (int i = 0; i < number; i++){
    a[i] = a[i] + b[i];
    delay(5);
    
  }
  gettimeofday(&t2, NULL);
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; 
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
  printf("%f ms.\n", elapsedTime);
  
  
  gettimeofday(&t3, NULL);
  for (int i = 0; i < number; i++){
    __builtin_prefetch (&a[i+4],1,1);
    __builtin_prefetch (&b[i+4],0,1);
    a[i] = a[i] + b[i];
    delay(5);
    
  }
  gettimeofday(&t4, NULL);
  elapsedTime2 = (t4.tv_sec - t3.tv_sec) * 1000.0; 
  elapsedTime2 += (t4.tv_usec - t3.tv_usec) / 1000.0;
  printf("%f ms.\n", elapsedTime2);
}