#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

char dt1a(double PL,double PW,double SW,double SL);
char dt1b(double PL, double PW, double SW, double SL);

double dt2a(double x1,double x2,double x3,int x4,int x5);
double dt2b(double x1,double x2,double x3,int x4,int x5);

void dt3a(int meal_dessert,int diet,int eating_habit,double body_mass_index,double hours);
void dt3b(int meal_dessert,int diet,int eating_habit,double body_mass_index,double hours);

#endif /* _UTIL_H_ */
