#include <stdint.h>
#include <math.h>
//  Accepts the ages of 8 great-grandparents and predicts the age of death of the grandchild according to the formula in the description.
//  arg0         = (uint64_t) An age.
//  arg1         = (uint64_t) An age.
//  arg2         = (uint64_t) An age.
//  arg3         = (uint64_t) An age.
//  arg4         = (uint64_t) An age.
//  arg5         = (uint64_t) An age.
//  arg6         = (uint64_t) An age.
//  arg7         = (uint64_t) An age.
//  return value = (uint64_t) The predicted age of death.
uint64_t predict_age(uint64_t age1, uint64_t age2, uint64_t age3, uint64_t age4, uint64_t age5, uint64_t age6, uint64_t age7, uint64_t age8)
{  
  return (int) (sqrt(age1 * age1 
                   + age2 * age2 
                   + age3 * age3 
                   + age4 * age4
                   + age5 * age5
                   + age6 * age6
                   + age7 * age7
                   + age8 * age8) / 2);
}
