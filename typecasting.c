/* limits.h defines a lot of #define constants that give
 * the numerical limits (max, min) of the types on your
 * system.
 * TODO: Examples
 */
#include<limits.h>

/* stdint.h defines typedefs for your system that
 * correspond to integers of certain widths/signedness.
 * The required typedefs are:
 *   int8_t -> signed 8 bit integer
 *   int16_t -> signed 16 bit integer
 *   int32_t -> signed 32 bit integer
 *   uint8_t -> unsigned 8 bit integer
 *   uint16_t -> unsigned 16 bit integer
 *   uint32_t -> unsigned 32 bit integer
 * While these are the required, many others are probably defined.
 */
#include<stdint.h>

#include<stdio.h>

#define BYTE_DELIM "-"

/* Print out the binary representation (1,0) of a number of
 * bytes at the address pointed to by *pval
 *
 * This prints from left to right with MSB to LSB, respectively
 */
void
base2print(void *pval, size_t bytes)
{
    char this = '\0';
    unsigned int b;
    unsigned int bit;
    for (b = bytes-1; (b >= 0) && (b < bytes); b--)
    {
        for (bit = 7; (bit >= 0) && (bit <= 7); bit--)
        {
            this = (( ((uint8_t*)pval)[b] & (0x1 << bit)) >> bit) ? '1' : '0';
            printf("%c", this);
        }
        if (b != 0) printf(BYTE_DELIM);
    }
    printf("\n");
}

void
base2describe(char *name, void *pval, size_t bytes)
{
    char bquant[6] = "bytes";
    if (bytes == 1) bquant[4] = '\0';
    printf("Type %s of len %lu %s has the binary representation:\n  ",
            name, bytes, bquant);
    base2print(pval, bytes);
}

void
hline(size_t len)
{
    size_t i;
    for (i=0; i < len; i++)
    {
        printf("-");
    }
    printf("\n");
}

void
nl(void)
{
    printf("\n");
}

int
main(int argc, char *argv[])
{
    printf("Section 1: Representing decimal number 1\n");
    hline(80);
    uint8_t ui8 = 1;
    base2describe("uint8_t", (void*)&ui8, sizeof(ui8));

    uint16_t ui16 = 1;
    base2describe("uint16_t", (void*)&ui16, sizeof(ui16));

    int8_t i8 = 1;
    base2describe("int8_t", (void*)&i8, sizeof(i8));

    nl();
    printf("Section 2: Representing the integer -1\n");
    hline(80);
    ui8 = (uint8_t)(-1);
    base2describe("uint8_t", (void*)&ui8, sizeof(ui8));
    ui16 = (uint16_t)(-1);
    base2describe("uint16_t", (void*)&ui16, sizeof(ui16));
    i8 = (int8_t)(-1);
    base2describe("int8_t", (void*)&i8, sizeof(i8));


    nl();
    printf("Section 3: Floating point 1.0.\n");
    hline(80);
    float fl1 = 1.0;
    base2describe("float", (void*)&fl1, sizeof(fl1));

    double dbl1 = 1.0;
    base2describe("double", (void*)&dbl1, sizeof(dbl1));

    printf("Now, lets look at a struct of uint8_t, int8_t, uint16_t, int16_t, uint32_t, int32_t members.");
    struct increasing_ints {
        uint8_t ui8;
        int8_t i8;
        uint16_t ui16;
        int16_t i16;
        uint32_t ui32;
        int32_t i32;
    };

    struct increasing_ints increasing = {1, 1, 1, 1, 1, 1};
    base2describe("struct increasing_ints", (void*)&increasing, sizeof(increasing));




}
