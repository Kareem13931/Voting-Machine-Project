#include <stdio.h>
#include <stdlib.h>

#include "dio.h"

void BUTTON_direction(char portname,char pinnumber)
{

  DIO_set_direction_pin(portname,pinnumber,0);

}
char BUTTON_reed(char portname,char pinnumber)
{

   char x;
    x= DIO_READ_PIN(portname,pinnumber);
 return x;

}
