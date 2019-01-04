#include<stdio.h>
#include<graphics.h>
#include<math.h>

void DDA(int, int, int, int, int);
void rotate(int, int, int, int, int, int, float);
void triangle(int, int, int, int, int, int);

//Function for making a triangle.
void triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
   int counter=0;
   DDA(x1, y1, x2, y2,counter);
   counter++;
   DDA(x2, y2, x3, y3,counter);
   counter++;
   DDA(x3, y3, x1, y1,counter);
}

//Function to rotate the triangle.
void rotate(int x1, int y1, int x2, int y2, int x3, int y3, float angle)
{
    int a1, b1, a2, b2, a3, b3, Xcentroid = 390, Ycentroid = 248;


    angle = (angle * 3.14) / 180; //Angle is converted from degree to radian as trignometric fuctions uses radian for compution.

    a1 = Xcentroid + (x1 - Xcentroid)*cos(angle) - (y1 - Ycentroid)*sin(angle);
    b1 = Ycentroid + (x1 - Xcentroid)*sin(angle) + (y1 - Ycentroid)*cos(angle);
    a2 = Xcentroid + (x2 - Xcentroid)*cos(angle) - (y2 - Ycentroid)*sin(angle);
    b2 = Ycentroid + (x2 - Xcentroid)*sin(angle) + (y2 - Ycentroid)*cos(angle);
    a3 = Xcentroid + (x3 - Xcentroid)*cos(angle) - (y3 - Ycentroid)*sin(angle);
    b3 = Ycentroid + (x3 - Xcentroid)*sin(angle) + (y3 - Ycentroid)*cos(angle);
    triangle(a1, b1, a2, b2, a3, b3);
}


void DDA(int xa, int ya, int xb, int yb, int counter)
{
     int dx, dy, length, i;
    float Xinc, Yinc, x = xa, y = ya,m,n;
    dx = xb - xa;
    dy = yb - ya;
    if(abs(dx) < abs(dy))
        length = abs(dy);
    else
        length = abs(dx);
    Xinc = dx / (float)(length);
    Yinc = dy / (float)(length);
    m=round(x);
    n=round(y);
	//The First side of the Triangle is drwan using DDA algo with Red Color.
    if(counter==0)
    {
      putpixel(m,n, RED);
      for(i = 1; i <= length; i++)
      {
         x = x + Xinc;
         y = y + Yinc;
         m=round(x);
         n=round(y);
         putpixel(m, n, RED);
	
      }
    }
	//The Second side of the Triangle is drwan using DDA algo with Yellow Color.
    else if(counter==1) 
    {
      putpixel(m,n, YELLOW);
      for(i = 1; i <= length; i++)
      {
         x = x + Xinc;
         y = y + Yinc;
         m=round(x);
         n=round(y);
         putpixel(m, n, YELLOW);
	
      }
    }
	//The last side is drwan using DDA algo with Cyan Color.
    else
    {
      putpixel(m,n, CYAN);
      for(i = 1; i <= length; i++)
      {
         x = x + Xinc;
         y = y + Yinc;
         m=round(x);
         n=round(y);
         putpixel(m, n, CYAN);
	
      }
    }
}

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    initgraph(&gd, &gm, NULL);

    printf("The Equilateral Triangle's Coordinate is taken to be (390, 144), (300, 300) and (480, 300)\n\n");

    triangle(390, 144, 300, 300, 480, 300);
    delay(2000);
    printf("Using the above points, the Centroid point which divides the median of the triangle in 2:1 ratio is found to be (390, 248) \n\n \n");
    putpixel(390,248,WHITE); //The Centroid is plotted.
    delay(1000);


    printf("Rotating the given equilaterl triangle at an angle of 45 degrees along its centroid\n");

    rotate(390, 144, 300, 300,480, 300, -45); //Negative angle as the rotation is anti clockwise and the origin of the window starts from the top.
    delay(6000);
    return 0;
}
