// Code imported from Replit

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num_o, num_d, Decimal_Converter(), divs, Divisor_Calculator(), decision = 1;
int error = 0;
int main(void) {
  while (decision == 1) {
    int r3, x2, num_oEC;
    printf("Please input a 4 digit octal number.\n");
    scanf("%d", &num_o);
    // Error checking input
    num_oEC = num_o; // the octal number input used in error checking algorithm
                     // is assigned to a seperate variable num_oEC as to not
                     // interfere with rest of the code.
    for (int x2 = 0; x2 < 4; ++x2) {
      r3 = num_oEC % 10;
      num_oEC = num_oEC / 10;
      if (r3 > 7) {
        printf("Input is not a 4 digit octal number: Please try again\n");
        error = 1; // prevents the code from running on an invalid number
        break;
      }
    }
    if ((floor((log10(num_o) + 1)) > 4) && error == 0)
    // second condition prevents doubling the error message
    {
      printf("Input is not a 4 digit octal number: Please try again\n");
      error = 1;
    }
    if (error == 0) {
      printf("The result of Octal to Decimal conversion of the number input "
             "is: %d\n",
             Decimal_Converter(num_o));
      // outputting result of calculations
      if (Divisor_Calculator(num_d) == 2) {
        printf("%d", num_o);
        printf(" is a prime number\n");
      } else {
        printf("%d", num_o);
        printf(" is not a prime number. It has %d", Divisor_Calculator(num_d));
        printf(" divisors\n");
      }
      printf("\nDo you want to input another number? If yes input (1). "
             "\nOtherwise input (0)\n");
      scanf("%d", &decision);
    }
    error = 0; // resets the variable for the next cycle
  }
}
int Decimal_Converter(num_o)
// function to convert the octal number into a decimal number
{
  int r;
  num_d = 0;
  for (int x = 0; x < 4; ++x) {
    r = num_o % 10;
    num_d = num_d + (pow(8, x) * r);
    num_o = num_o / 10;
  }
  return num_d;
}
int Divisor_Calculator(num_d)
// function to calculate the number of divisors in a given number
{
  int r2, divs = 0, i = 1;
  while (i <= num_d) {
    r2 = num_d % i;
    if (r2 == 0) {
      ++divs;
    }
    i++;
  }
  return divs;
}