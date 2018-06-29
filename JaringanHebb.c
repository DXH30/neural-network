#include <stdio.h>

int main()
{
	int i,j,k;
	int x1[4] = {1,1,0,0};
	int x2[4] = {1,0,1,0};
	int b[4] = {1,1,1,1};
	int t[4] = {1,0,0,0};
	int *y = t;
	int w1[4] = {0,0,0,0};
	int w2[4] = {0,0,0,0};
	int dw1[4] = {0,0,0,0};
	int nw1[4] = {0,0,0,0};
	int dw2[4] = {0,0,0,0};
	int nw2[4] = {0,0,0,0};
	int db[4] = {0,0,0,0};
	int nb[4] = {0,0,0,0};
	int n = sizeof(x1)/sizeof(x1[0]);
	printf("Penerapan logika Jaringan Hebb pada gerbang AND\n");
	printf("x1\tx2\tb\tt\n");
	for(i=0;i<n;i++)
	{
	printf("%d\t%d\t%d\t%d\n",x1[i],x2[i],b[i],t[i]);
	}
	printf("Setelah di hitung\n");
	printf("x1\tx2\tb\tt\ty\tdw1\tdw2\tdb\tw1\tw2\tb\n");
	for(i=0;i<n;i++)
	{	
	dw1[i] = x1[i]*t[i];
	dw2[i] = x2[i]*t[i];
	nw1[i] = w1[i]+dw1[i];
	nw2[i] = w2[i]+dw2[i];
	nb[i] = b[i]+db[i];
	db[i] = t[i];
	w1[i] = nw1[i];
	w2[i] = nw2[i];
	b[i] = nb[i];
	printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",x1[i],x2[i],b[i],t[i],y[i],dw1[i],dw2[i],db[i],w1[i],w2[i],b[i]);
	}
}

