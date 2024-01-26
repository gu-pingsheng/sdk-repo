#include "eapp.h"
#include "print.h"
#include <stdlib.h>
#include <stdio.h>

int mem(unsigned long * args)
{
  char *ptr, *ptr2;
  int i;
  ptr = (char*)malloc(0x10000);
  ptr2 = (char*)malloc(0x10000);

  eapp_print("***************mem start123****************\n", i,ptr[i]);

  for(i = 0; i < 10; i++)
  {
    ptr[i] = i;
    eapp_print("ptr[%d] = %d\n", i, ptr[i]);
    eapp_print("ptr[%d]: %p\n", i, &ptr[i]);

  }
  for(i = 0; i < 10; i++)
  {
    ptr2[i] = i;
    eapp_print("prt[%d] = %d\n", i, ptr2[i]);
    eapp_print("ptr[%d]: %p\n", i, &ptr2[i]);
  }

  free(ptr2);
  ptr2 = (char*)malloc(0x100);
  free(ptr);
  free(ptr2);

  EAPP_RETURN(ptr);
}

int EAPP_ENTRY main(){
  unsigned long * args;
  EAPP_RESERVE_REG;
  mem(args);
}
