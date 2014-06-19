#ifndef COMMON_H
#define COMMON_H

#define F_CPU 1000000  // 1 MHz, what is it really?

// AVR includes
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

//! Makro biti seadmiseks
#define setbit(ADDRESS, BIT) (ADDRESS |= (1 << BIT))
//! Makro biti nullimiseks
#define clearbit(ADDRESS, BIT) (ADDRESS &= ~(1 << BIT))
//! Makro biti vastupidiseks panemiseks
#define togglebit(ADDRESS, BIT) (ADDRESS ^= (1 << BIT))
//! Makro biti testimiseks
#define checkbit(ADDRESS, BIT) (ADDRESS & (1<<BIT))


#endif
