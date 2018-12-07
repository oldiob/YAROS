/*
 * Copyright (C) Olivier Dion <olivier.dion@polymtl.ca>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


/*
 * USART driver for the atmega324pa
 */

#include <avr/io.h>

#include "YAROS/msg.h"

#include "devices/usart.h"


static inline void __attribute__((always_inline))
__enable_reception()
{
    UCSR0B |= _BV(RXEN0);
}

static inline void __attribute__((always_inline))
__disable_reception()
{
    UCSR0B &= ~_BV(RXEN0);
}

static inline void __attribute__((always_inline))
__wait_for_send()
{
    while (!(UCSR0A & _BV(UDRE0)))
        ;
}

static inline void __attribute__((always_inline))
__wait_for_recv()
{
    while (!(UCSR0A & _BV(RXC0)))
        ;
}


void
init_usart(void)
{
    UBRR0H = 0x0;
    UBRR0L = 0xCF;

    (void)UCSR0A;

    /* Receiver and Transmitter */
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);

    /* 8 bits no parity; stop is 1 bit */
    (void)UCSR0C;
}



ssize_t
write_usart(int minor, const void *buff, size_t len)
{
    for (size_t i=0; i < len; ++i) {
        __wait_for_send();
        UDR0 = ((char*)buff)[i];
    }

    return len;
}


ssize_t
read_usart(int minor, void *buff, size_t len)
{
    for (size_t i=0;  i<len; ++i) {
        __wait_for_recv();
        ((char*)buff)[i] = UDR0;
    }

    return len;
}
