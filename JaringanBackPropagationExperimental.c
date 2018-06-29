#include <stdio.h>

struct ball {
	int size;
	double value[];
};
struct weight {
	double **value;
};
struct ball x,y,z;
struct weight v,w;
int main()
{
	int i,j,k;
	printf("[y1] [y2] ... [yn]\n");
	printf("w11 w12 w22 ... wnm\n");
	printf("[z1] [z2] ... [zn]\n");
	printf("v11 v12 v22 ... vnm\n");
	printf("Berapa jumlah y : ");
	scanf("%d",&y.size);
	printf("Berapa jumlah z : ");
	scanf("%d",&z.size);
	printf("Berapa jumlah x : ");
	scanf("%d",&x.size);
	printf("%d\n",x.size);
	for(i=0;i<y.size;i++){
		printf("Berapa nilai y%d : ",i+1);
		scanf("%d",&y.value[i]);
	}
	for(j=0;j<z.size;j++){
		printf("Berapa nilai z%d : ",j+1);
		scanf("%d",&z.value[j]);
	}
	for(k=0;k<x.size;k++){
		printf("Berapa nilai x%d : ",k+1);
		scanf("%d",&x.value[k]);
	}
	
	for(i=0;i<y.size;i++){
		for(j=0;j<z.size;j++){
			printf("Berapa nilai w%d%d : ",i+1,j+1);
			scanf("%d",&w.value[i][j]);
		}
	}
	for(j=0;j<z.size;j++){
		for(k=0;k<x.size;k++){
			printf("Berapa nilai v%d%d : ",j+1,k+1);
			scanf("%d",&v.value[j][k]);
		}
	}	
}
