/*
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

/* Fun with pointers */

#include<stdio.h> /* printf */
#include<string.h> /* memset */

/* The sizeof operator is often used incorrectly with pointers.  Here
 * are some specific examples.
 */
void
arg_size_specified(int ptr[20])
{
    printf("Some would expect sizeof(ptr), the function argument defined by 'int ptr[20]' to be\n");
    printf("20*sizeof(int).  However, it is really: %lu\n", sizeof(ptr));
}

void
arg_ptr_no_size(int *ptr)
{
    printf("Of course, this is also true if the function argument is defined by 'int *ptr'.\n");
    printf("Again, instead of sizeof(int)*20 the size is: %lu\n", sizeof(ptr));
}


int
main(int argc, char** argv)
{
    int iarray[20];
    memset(iarray, 0, sizeof(iarray));
    printf("The size of iarray in main(...) is: %lu\n", sizeof(iarray));
    arg_size_specified(iarray);
    arg_ptr_no_size(iarray);
}
