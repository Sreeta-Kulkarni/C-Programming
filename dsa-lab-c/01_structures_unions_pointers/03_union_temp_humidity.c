/*
 * Union storing Temperature or Humidity, shows memory sharing
 */

// 3. Create a union that stores either:
// • Temperature (float)
// • Humidity (int)
// Show how memory changes
#include <stdio.h>
union Data
{
float temp;
int hum;
};
int main()
{
union Data d;
d.temp = 36.5;
printf("Temp: %.2f\n", d.temp);
d.hum = 60;
printf("Humidity: %d\n", d.hum);
printf("Temp again: %.2f\n", d.temp);
return 0;
}
