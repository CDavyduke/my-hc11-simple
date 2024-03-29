/* Small test/example program
   Copyright (C) 1999, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.
   Written by Stephane Carrez (stcarrez@nerim.fr)	

This file is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file with other programs, and to distribute
those programs without any restriction coming from the use of this
file.  (The General Public License restrictions do apply in other
respects; for example, they cover modification of the file, and
distribution when not linked into another program.)

This file is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/*! @page simple Very simple hello world program.

   The \c simple example is a basic \b hello program that prints
   the message several times on the serial line.

  @htmlonly
  Source file: <a href="simple_8c-source.html">simple.c</a>
  @endhtmlonly

 */

#include <sys/sio.h>
#include <sys/interrupts.h>

/* Prints "Hello %d\n" on the serial device.  */
static void
print_hello (unsigned i)
{
  char buf[15];
  char* p;
  unsigned char c;
  unsigned int value;
  
  p = &buf[15];
  *--p = 0;
  value = i;
  
  do {
    c = value % 10;
    value = value / 10;
    *--p = c + '0';
  } while (value != 0);
  
  serial_print ("Hello ");
  serial_print (p);
  serial_print ("\n");
}

int
main ()
{
  unsigned i;

  serial_init ();
  for (i = 0; i < 1000; i++)
    {
      print_hello (i);
    }
  return 0;
}
