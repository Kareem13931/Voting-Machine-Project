#ifndef DIO_H_INCLUDED
#define DIO_H_INCLUDED
void DIO_set_direction_pin(char portname,char pinnumber , char direction );
void DIO_WRITE_PIN(char portname,char pinnumber , char outputvalue );
void DIO_TOGGLE_PIN(char portname, char pinnumber);
char DIO_READ_PIN(char portname, char pinnumber );
void DIO_direction_port( char portname, char direction);
void DIO_write_port( char portname, char portvalue);
void DIO_TOGGLE_port(char portname);
char DIO_read_port( char portname);
void DIO_connectpullup(char portname ,char pinnumber, char connect_pullup);
void write_low_nibble( char portname, char value);
void write_hight_nibble( char portname, char value);


#endif // DIO_H_INCLUDED
