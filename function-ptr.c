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

/* Fun with function pointers. */

#include<stdlib.h> /* For rand */
#include<stdio.h>  /* prinft */
#include<time.h>   /* time to seed random number generator */

typedef void (*fnp_void)(void);
typedef int (*fnp_int)(int);

int
seed_rand(void) {
    srand(time(NULL));
    return 1;
}

void
print_rand(void) {
    printf("Printing a random number in print_rand: %f\n", rand()/(double)RAND_MAX);
}

void
print_1(void) {
    printf("Printing 1 in print_1: 1\n");
}

int
main(int argc, char** argv) {
    seed_rand();
    fnp_void print_something = print_rand;
    print_something();
    print_something = print_1;
    print_something();
    return 0;
}

