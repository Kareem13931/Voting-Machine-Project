
#include <stdio.h>
#include "dio.h"
#include <avr/io.h>
void DIO_set_direction_pin(char portname,char pinnumber , char direction )
{

switch(portname)
       {
    case 'A':
    case 'a':
       if (direction==1)
        {
           DDRA|=(1<<pinnumber);
        }
       else
        {
           DDRA&=(~(1<<pinnumber));
        }
        break;

    case 'B':
    case 'b':
        if (direction==1)
        {
            DDRB|=(1<<pinnumber);
        }
       else
        {
            DDRB&=(~(1<<pinnumber));
        }
        break;

    case 'C':
    case 'c':
        if (direction==1)
        {
            DDRC|=(1<<pinnumber);
        }
       else
        {
            DDRC&=(~(1<<pinnumber));
        }
        break;

    case 'D':
    case 'd':
        if (direction==1)
        {
            DDRD|=(1<<pinnumber);
        }
       else
        {
            DDRD&=(~(1<<pinnumber));
        }
        break;
       }
}

void DIO_WRITE_PIN(char portname,char pinnumber , char outputvalue )
{

  switch(portname)
       {
    case 'A':
    case 'a':
       if (outputvalue==1)
        {
           PORTA|=(1<<pinnumber);
        }
       else
        {
           PORTA&=(~(1<<pinnumber));
        }
        break;

    case 'B':
    case 'b':
        if (outputvalue==1)
        {
            PORTB|=(1<<pinnumber);
        }
       else
        {
            PORTB&=(~(1<<pinnumber));
        }
        break;

    case 'C':
    case 'c':
        if (outputvalue==1)
        {
            PORTC|=(1<<pinnumber);
        }
       else
        {
            PORTC&=(~(1<<pinnumber));
        }
        break;

    case 'D':
    case 'd':
        if (outputvalue==1)
        {
            PORTD|=(1<<pinnumber);
        }
       else
        {
            PORTD&=(~(1<<pinnumber));
        }
        break;
       }
}
void DIO_TOGGLE_PIN(char portname, char pinnumber)
{
     switch(portname)
       {
    case 'A':
    case 'a':
      PORTA^=(1<<pinnumber);
    break;

    case 'B':
    case 'b':
      PORTB^=(1<<pinnumber);
    break;
    case 'C':
    case 'c':
      PORTC^=(1<<pinnumber);
    break;
    case 'D':
    case 'd':
       PORTD^=(1<<pinnumber);
    break;
       }

}
char DIO_READ_PIN(char portname, char pinnumber )
{
    char readpin=0;
     switch(portname)
       {
    case 'A':
    case 'a':
      readpin=((PINA&(1<<pinnumber))>>pinnumber);
    break;

    case 'B':
    case 'b':
      readpin=((PINB&(1<<pinnumber))>>pinnumber);
    break;
    case 'C':
    case 'c':
      readpin=((PINC&(1<<pinnumber))>>pinnumber);
    break;
    case 'D':
    case 'd':
      readpin=((PIND&(1<<pinnumber))>>pinnumber);
    break;

    }
       return readpin;
}
void DIO_direction_port( char portname, char direction)
{
	switch(portname)
	{
		case 'A' :
		DDRA=direction; //set the direction of port A
		break ;
		case 'B':
		DDRB=direction; //set the direction of port B
		break ;
		case 'C' :
		DDRC=direction; //set the direction of port C
		break ;
		case 'D':
		DDRD=direction; //set the direction of port D
		break ;

	}

  }
void DIO_write_port( char portname, char portvalue)
{
	switch(portname)
	{
		case 'A' :
		PORTA=portvalue; //Write the given value to the port A
		break ;
		case 'B':
		PORTB=portvalue; //Write the given value to the port B
		break ;
		case 'C' :
		PORTC=portvalue; //Write the given value to the port C
		break ;
		case 'D':
		PORTD=portvalue; //Write the given value to the port D
		break ;

	}
}
void DIO_TOGGLE_port(char portname)
{
	switch(portname)
	{
		case 'A' :
        case 'a' :

		    PORTA^=0Xff;
		break ;
		case 'B':
        case 'b' :

		    PORTB^=0Xff;
		break ;
		case 'C' :
        case 'c' :

		    PORTC^=0Xff;
		break ;
		case 'D':
        case 'd' :

		    PORTD^=0Xff;
		break ;

	}
}
 char DIO_read_port( char portname)
{
	 char readport=0;
	switch(portname)
	{
		case 'A' :
		case 'a' :
		readport=PINA; // read the value of port A
		break ;
		case 'B' :
		case 'b' :
		readport=PINB; // read the value of port B
		break ;
		case 'C' :
		case 'c' :
		readport=PINC; // read the value of port C
		break ;
		case 'D' :
		case 'd' :
		readport=PIND; // read the value of port D
		break ;
	}
	return readport;
}
	void DIO_connectpullup(char portname ,char pinnumber, char connect_pullup)
{
	switch(portname)
       {
    case 'A':
    case 'a':
       if (connect_pullup==1)
        {
           PORTA|=(1<<pinnumber);
        }
       else
        {
           PORTA&=(~(1<<pinnumber));
        }
        break;

    case 'B':
    case 'b':
        if (connect_pullup==1)
        {
            PORTB|=(1<<pinnumber);
        }
       else
        {
            PORTB&=(~(1<<pinnumber));
        }
        break;

    case 'C':
    case 'c':
        if (connect_pullup==1)
        {
            PORTC|=(1<<pinnumber);
        }
       else
        {
            PORTC&=(~(1<<pinnumber));
        }
        break;

    case 'D':
    case 'd':
        if (connect_pullup==1)
        {
            PORTD|=(1<<pinnumber);
        }
       else
        {
            PORTD&=(~(1<<pinnumber));
        }
        break;
       }
	}
void write_low_nibble( char portname, char value)
{
    DIO_WRITE_PIN(portname,0,((value&(1<<0))>>0)) ;
    DIO_WRITE_PIN(portname,1,((value&(1<<1))>>1)) ;
    DIO_WRITE_PIN(portname,2,((value&(1<<2))>>2)) ;
    DIO_WRITE_PIN(portname,3,((value&(1<<3))>>3)) ;

}

void write_hight_nibble( char portname, char value)
{
    DIO_WRITE_PIN(portname,4,((value&(1<<4))>>4));
    DIO_WRITE_PIN(portname,5,((value&(1<<5))>>5));
    DIO_WRITE_PIN(portname,6,((value&(1<<6))>>6));
    DIO_WRITE_PIN(portname,7,((value&(1<<7))>>7));

}
