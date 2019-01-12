/*
 * Author : Didik Hadumi Setiaji
 * Project : Adaptive Neural Network
 *
 */

#include <stdio.h>
double fungsiaktifasi(double x){
 if (x < 0)
 return -1.0;
 else if (x >= -0.1 && x <= 0.1)
 return 0.0;
 else
 return 1.0;
}
int main()
{
 double b[2],w1[2],w2[2],y[2];
 int iterasi=0, n=0, konfirmasi=1;
 double t[4] = {1.0,-1.0,-1.0,-1.0};
 double x1[4] = {1.0,1.0,0.0,0.0};
 double x2[4] = {1.0,0.0,1.0,0.0};
 double a = 0.5;
 printf("%.1f\n",t[1]);
 w1[0] = 0.0;
 w2[0] = 0.0;
 b[0] = 0.0;
 y[0] = 0.0;
 printf("x1 x2 y  target\n");
 printf("1  1  1  1\n");
 printf("1  0  1  1\n");
 printf("0  1  1  1\n");
 printf("0  0  0 -1\n");
 //printf("Masukkan nilai a : ");
 //scanf("%lf",&a);
 while(konfirmasi!=4){
 iterasi = iterasi + 1;
 printf("%d\n",konfirmasi);
 printf("===============\n");
 printf("Iterasi ke %d\n",iterasi); 
 n=0;
 while(n<4){
 printf("\n");
 printf("Untuk data %d: (%.0f %.0f)\n",n+1,x1[n],x2[n]);
 y[1] = b[0] + w1[0]*x1[n]+w2[0]*x2[n]; 
 printf("didapat y = %.1f + (%.1f x %.1f) + (%.1f x %.1f)\n",
         b[0],w1[0],x1[n],w2[0],x2[n]);
 printf("y = %.1f\n",y[1]);
 printf("f(%.1f) = %.0f\n",y[1],fungsiaktifasi(y[1]));
 if(t[n] != fungsiaktifasi(y[1])){
 b[1] = b[0] + a*t[n];
 printf("nilai bias baru\n");
 printf("b = %.1f + (%.1f x %.1f)\n",b[0],a,t[n]);
 printf("  = %.1f\n",b[1]);
 w1[1] = w1[0] + a*x1[n]*t[n];
 printf("bobot baru w1\n");
 printf("w1 = %.1f + (%.1f x %.1f x %.1f)\n",w1[0],a,x1[n],t[n]);
 w2[1] = w2[0] + a*x2[n]*t[n];
 printf("bobot baru w2\n");
 printf("w2 = %.1f + (%.1f x %.1f x %.1f)\n",w2[0],a,x2[n],t[n]);
 }
 else {
 konfirmasi = konfirmasi + 1;
 }
 if (n == 0)
  konfirmasi = 1;
 y[0] = y[1];
 b[0] = b[1];
 w1[0] = w1[1];
 w2[0] = w2[1];
 n = n + 1;  
 }
 }
 printf("program selesai saat iterasi ke %d\n",iterasi);
 printf("bobot akhir w1 = %.1f\n",w1[0]);
 printf("bobot akhir w2 = %.1f\n",w2[0]);
 printf("bias akhir b = %.1f\n",b[0]);
}
