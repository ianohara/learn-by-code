/* Copyright 2013, Ian O'Hara
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

#include<stdint.h>
#include<stdio.h>

/* This file explores enums in C.  */
typedef enum {
    SEQ_0=0x00,
    SEQ_1=0x01,
    SEQ_2=0x02,
    SEQ_3=0x03,
    SEQ_4=0x04,
    SEQ_5=0x05,
    SEQ_6=0x06,
} sequential_enum_t;

typedef enum {
    EVEN_0=0x00,
    EVEN_2=0x02,
    EVEN_4=0x04,
    EVEN_6=0x06
} even_enum_t;

/* Exploration 1: The stm32f4xxx libraries use this type of macro all over.
 *              I want to know if it is safe (ie: what happens if I pass in
 *              an enum value from a different enum but of the same numeric value?
 *
 *              Pretty sure only the values are checked...so this is a broken check.
 */
#define IS_SEQUENTIAL_ENUM(x) ( ( ((x) == SEQ_0) || ((x) == SEQ_1) || ((x) == SEQ_2) || \
                                  ((x) == SEQ_3) || ((x) == SEQ_4) || ((x) == SEQ_5) || \
                                  ((x) == SEQ_6)) )

int
main(void) {
    printf("Exploration 1: Macro that tests value for membership in enum\n");
    printf("  The following are all IS_SEQUENTIAL_ENUM(x) calls where x\n");
    printf("  *IS* a sequentian_enum_t.\n");
    printf("    SEQ_0 ");
    if (IS_SEQUENTIAL_ENUM(SEQ_0)) {
        printf("is a sequential enum.\n");
    } else {
        printf("is NOT a sequential enum.\n");
    }
    printf("  The following are all IS_SEQUENTIAL_ENUM(x) calls where x\n");
    printf("  *IS NOT* a sequential_enum_t.  They are even_enum_t.\n");
    printf("    EVEN_0 ");
    if (IS_SEQUENTIAL_ENUM(EVEN_0)) {
        printf("is a sequential_enum_t.\n");
    } else {
        printf("is NOT a sequential_enum_t.\n");
    }

    return 0;
}


