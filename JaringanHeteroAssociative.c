#include <stdio.h>
int main()
{
	int s[4][4] = {{1,1,-1,-1},{-1,1,-1,-1},{-1,-1,-1,1},{-1,-1,1,1}};
	int t[2][4] = {{1,1,-1,-1},{-1,-1,1,1}};
	int y_in[2],y1,y2;
	int i,j,k;
	int kesalahan = 0;
	printf("Misalkan sebuah jaringan HM dilatih untuk menyimpan pola dari vektor input s = (s1,s2,s3,s4) dan vektor output t=(t1,t2) yaitu :\n");
	printf("s1\ts2\ts3\ts4\tt1\tt2\n");		
	for(i = 0;i < 4; i++) {
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",s[0][i],s[1][i],s[2][i],s[3][i],t[0][i],t[1][i]);
	}
	printf("Langkah 0 : semua bobot diberi nilai 0\n");
	int wn[4][2] = {{0,0},{0,0},{0,0},{0,0}};
	int w[4][2] = {{0,0},{0,0},{0,0},{0,0}};
	do {
	for(i = 0;i < 2; i++) {
		for(j = 0;j < 4;j++){
			int x[4] = {s[j][0],s[j][1],s[j][2],s[j][3]};
			int y[2] = {t[0][j],t[1][j]};
			printf("Langkah 1 : untuk pasangan yang ke %d s : t(%d,%d,%d,%d) (%d,%d)\n",j+1,x[0],x[1],x[2],x[3],y[0],y[1]);
			printf("Langkah 2 : x1 = %d ; x2 = %d ; x3 = %d ; x4 = %d\n",x[0],x[1],x[2],x[3]);
			printf("Langkah 3 : y1 = %d ; y2 = %d\n",y[0],y[1]);
			printf("Langkah 4 : \n");
			for(k = 0;k < 4;k++){
				wn[k][i] = w[k][i] + x[k]*y[i];
				printf("w%d%d(baru) = w%d%d(lama) + x%dy%d = %d + %d = %d\n",k+1,i+1,k+1,i+1,k+1,i+1,w[k][i],x[k]*y[i],wn[k][i]);
				w[k][i] = wn[k][i];
			}
		}
	}
	printf("matriks yang didapat :\n");
	for(j = 0;j < 4;j++) {
		for (k = 0;k < 2;k++)
			printf("%d ",w[j][k]);
		printf("\n");
	}
	for(i = 0;i < 4;i++) {
		int x[4] = {s[i][0],s[i][1],s[i][2],s[i][3]};
		printf("Langkah 1 : pola input ke %d, lakukan langkah 2 - 4\n",i+1);
		printf("Langkah 2 : x = (%d,%d,%d,%d)\n",x[0],x[1],x[2],x[3]);
		printf("Langkah 3 : \n");
		for(k = 0;k < 2;k++){
			printf("y_in%d = x1w1%d+x2w2%d+x3w3%d+x4w4%d\n",k+1,k+1,k+1,k+1,k+1);
			y_in[k] = x[0]*w[0][k]+x[1]*w[1][k]+x[2]*w[2][k]+x[3]*w[3][k];
			printf("      = %d(%d) + %d(%d) + %d(%d) + %d(%d) = %d\n",x[0],w[0][k],x[1],w[1][k],x[2],w[2][k],x[3],w[3][k],y_in[k]);
		}
		printf("Langkah 4 : \n");
		y1 = f(y_in[0]);
		y2 = f(y_in[1]);
		printf("y1 = f(y_in1) = f(%d) = %d\n",y_in[0],y1);
		printf("y2 = f(y_in2) = f(%d) = %d\n",y_in[1],y2);
		if (y1 == t[0][i] && y2 == t[1][i])
			printf("(ini menunjukkan input yang benar untuk input ke %d)\n",i+1);
		else {
			printf("(ini menunjukkan input yang salah untuk input ke %d)\n",i+1);
			kesalahan = kesalahan + 1;
		}
	}
	} while (kesalahan > 0);
}

int f(int yin){
	if (yin > 0)
		return 1;
	else
		return -1;
}
