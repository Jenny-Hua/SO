// // compile with $ gcc -Wall -g *.c -pthread -o program
// run with ./program
// check with valgrind --tool=helgrind ./program
// URL EJEMPLO: https://www.um.es/earlyadopters/actividades/a3/PCD_Activity3_Session1.pdf
// Anpother: https://www.delftstack.com/es/howto/c/pthread_join-return-value-in-c/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// Función Hola
void *hola(void *arg)
{
  char *msg = " Hola ";
  int i;
  for (i = 0; i < strlen(msg); i++)
  {
    printf(" %c ", msg[i]);
    fflush(stdout);
    usleep(1000000);
  }
  return NULL;
}

// Función Mundo
void *mundo(void *arg)
{
  char *msg = " mundo ";
  int i;
  for (i = 0; i < strlen(msg); i++)
  {
    printf(" %c ", msg[i]);
    fflush(stdout);
    usleep(1000000);
  }
  return NULL;
}

int main(int argc, char *argv[])
{
  pthread_t h1;
  pthread_t h2;
  pthread_create(&h1, NULL, hola, NULL);
  pthread_create(&h2, NULL, mundo, NULL);
  //
  pthread_join(h1, NULL) ;
  pthread_join(h2, NULL) ;
  printf("\n Fin \n ");
  return 0;
}