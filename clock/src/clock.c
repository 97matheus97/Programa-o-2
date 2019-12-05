/*
 ============================================================================
 Name        : clock.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include  <stdio.h>
#include  <time.h>

 coletor não assinado volátil ;
int main(void)
{

  clock_t start =  clock ( ) ;

  for(size_t i = 0; i < 10000000;  ++ i )
      sink++ ;

  clock_t final =  relógio ( ) ;
  double cpu_time_used =  ((double )  (fim - início ))  / CLOCKS_PER_SEC ;

  printf ( "o loop for levou% f segundos para executar \ n" , cpu_time_used) ;
}
