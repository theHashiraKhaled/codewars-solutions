// https://www.codewars.com/kata/5262119038c0985a5b00029f

#include <stdbool.h>
/*
A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself. The first few prime numbers are {2, 3, 5, 7, 11, ….}

The idea to solve this problem is to iterate through all the numbers starting from 2 to sqrt(N) using a for loop and for every number check if it divides N. If we find any number that divides, we return false. If we did not find any number between 2 and sqrt(N) which divides N then it means that N is prime and we will return True. 
Why did we choose sqrt(N)? 
The reason is that the smallest and greater than one factor of a number cannot be more than the sqrt of N. And we stop as soon as we find a factor. For example, if N is 49, the smallest factor is 7. For 15, smallest factor is 3.
*/

bool is_prime(int n){
  int i, flag = 1;
    // Iterate from 2 to sqrt(n)
    for (i = 2; i <= sqrt(n); i++) {
 
        // If n is divisible by any number between
        // 2 and n/2, it is not prime
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }
 
    if (n <= 1)
        flag = 0;
 
    if (flag == 1) {
        return true;
    }
    else {
        return false;
    }
}
