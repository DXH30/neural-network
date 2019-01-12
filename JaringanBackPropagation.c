/*
 * Author   : Didik Hadumi Setiaji
 * Project  : Back Propagation Network
 */
#include <stdio.h>
#include <math.h>
#define JUMLAHX 3
#define JUMLAHY 3
#define JUMLAHZ 3

double f(int f_in){
	if(f_in > 0.0)
		return 1.0;
	else
		return 0.1;
}
double sigmoidbiner(int y_in){
	return 1/(1+exp(-y_in));
}
double sigmoidbinerx(int y_in){
	double a = 1/(1+exp(-y_in));
	return a*(1-a);
}


int main()
{
	int i,j,k,puas = 0;
	char menu;
	double v[JUMLAHZ][JUMLAHX],w[JUMLAHY][JUMLAHZ];
	double x[JUMLAHX] = {1.0, 1.0, 0.0};
	double y[JUMLAHY];
	double t[JUMLAHY] = {1.0, 1.0, 1.0};
	double y_in[JUMLAHY];
	double z[JUMLAHZ];
	double z_in[JUMLAHZ];
	double ey[JUMLAHY];
	double ez[JUMLAHZ];
	double alpha = 0.3;
	double dw[JUMLAHY][JUMLAHZ];
	double dnw[JUMLAHY][JUMLAHZ];
	double nw[JUMLAHY][JUMLAHZ];
	double dv[JUMLAHZ][JUMLAHX];
	double dnv[JUMLAHZ][JUMLAHX];
	double nv[JUMLAHZ][JUMLAHX];
	w[0][0] = 0.100000000000000000000000000000000000000000000;
	w[0][1] = 0.200000000000000000000000000000000000000000000;
	w[0][2] = 0.300000000000000000000000000000000000000000000;
	w[1][0] = 0.400000000000000000000000000000000000000000000;
	w[1][1] = 0.000000000000000000000000000000000000000000000;
	w[1][2] = 1.000000000000000000000000000000000000000000000;
	w[2][0] = 0.500000000000000000000000000000000000000000000;
	w[2][1] = 0.500000000000000000000000000000000000000000000;
	w[2][2] = 0.900000000000000000000000000000000000000000000;
	v[0][0] = 0.500000000000000000000000000000000000000000000;
	v[0][1] = 0.000000000000000000000000000000000000000000000;
	v[0][2] = 0.000000000000000000000000000000000000000000000;
	v[1][0] = 0.300000000000000000000000000000000000000000000;
	v[1][1] = 0.500000000000000000000000000000000000000000000;
	v[1][2] = 0.900000000000000000000000000000000000000000000;
	v[2][0] = 1.000000000000000000000000000000000000000000000;
	v[2][1] = 0.400000000000000000000000000000000000000000000;
	v[2][2] = 0.500000000000000000000000000000000000000000000;
	while(puas == 0){
	for(i=0;i<JUMLAHZ;i++){
		z_in[i] = x[0]*w[0][i] + x[1]*w[1][i] + x[2]*w[2][i];
		printf("z_in%.4f = x1*w1%.4f + x2*w2%.4f + x3*w3%.4f + x4*w4%.4f\n",i+1,i+1,i+1,i+1,i+1);
		printf("z_in%.4f = %.4f(%.4f) + %.4f(%.4f) + %.4f(%.4f) + %.4f(%.4f) = %.4f\n",i+1,x[0],w[0][i],x[1],w[1][i],x[2],w[2][i],z_in[i]);
		printf("z%d = f(z_in%d) = f(%.4f) = %.4f\n",i+1,i+1,z_in[i],z[i]);
		z[i] = f(z_in[i]); 
	}
	for(j=0;j<JUMLAHY;j++){
		y_in[i] = x[0]*v[0][i] + x[1]*v[1][i] + x[2]*v[2][i];
		printf("y_in%.4f = x1*v1%.4f + x2*v2%.4f + x3*v3%.4f + x4*v4%.4f\n",i+1,i+1,i+1,i+1,i+1);
		printf("y_in%.4f = %.4f(%.4f) + %.4f(%.4f) + %.4f(%.4f) + %.4f(%.4f) = %.4f\n",i+1,x[0],v[0][i],x[1],v[1][i],x[2],v[2][i],y_in[i]);
		printf("y%d = f(y_in%d) = f(%.4f) = %.4f\n",i+1,i+1,y_in[i],y[i]);
		y[j] = f(y_in[j]);
	}
	//Perambatan-balik galat
	for(j=0;j<JUMLAHY;j++){
		printf("e%d=(t%d-y%d)f'(y_in%d)\n",j+1,j+1,j+1,j+1);
		ey[j] = (t[j]-y[j])*sigmoidbinerx(y_in[j]);
		printf("e%d=(%.4f-%.4f)f'(%.4f)=%.4f\n",j+1,t[j],y[j],y_in[j],ey[j]);
	}
	for(j=0;j<JUMLAHZ;j++){
		printf("e%d=(t%d-z%d)f'(z_in%d)\n",j+1,j+1,j+1,j+1);
		ez[j] = (t[j]-z[j])*sigmoidbinerx(z_in[j]);
		printf("e%d=(%.4f-%.4f)f'(%.4f)=%.4f\n",j+1,t[j],z[j],z_in[j],ez[j]);
	}

	printf("Koreksi Bobot \n");
	for(j=0;j<JUMLAHZ;j++){
		for(k=0;k<JUMLAHY;k++){
			w[j][k] = nw[j][k];
			dw[j][k] = alpha*ey[k]*z[j];
			printf("dw%d%d = a*e%d*z%d\n",j+1,k+1,j+1,k+1);
			printf("     = %.4f*%.4f*%.4f = %.4f\n",alpha,ey[k],z[j],dw[j][k]);
			dnw[j][k] = alpha*ey[k]*z[j] + alpha*dw[j][k];
			printf("dnw%d%d = a*e%d*z%d + a*dw%d%d\n",j+1,k+1,j+1,k+1,j+1,k+1);
			printf("     = %.4f*%.4f*%.4f + %.4f*%.4f = %.4f\n",alpha,ey[k],z[j],alpha,dw[j][k],dnw[j][k]);
			nw[j][k] = w[j][k] + dw[j][k];
			printf("nw%d%d = w%d%d + dw%d%d\n",j+1,k+1,j+1,k+1,j+1,k+1);
			printf("     = %.4f + %.4f = %.4f\n",w[j][k],dw[j][k],nw[j][k]);
			w[j][k] = nw[j][k];
			printf("w%d%d = nw%d%d\n",j+1,k+1,j+1,k+1);
			printf("w%d%d = %.4f\n",j+1,k+1,nw[j][k]);

		}
	}
	
	for(j=0;j<JUMLAHX;j++){
		for(k=0;k<JUMLAHZ;k++){
			dv[j][k] = alpha*ez[k]*x[j];
			v[j][k] = nv[j][k];
			printf("dv%d%d = a*e%d*x%d\n",j+1,k+1,j+1,k+1);
			printf("     = %.4f*%.4f*%.4f = %.4f\n",alpha,ez[k],x[j],dv[j][k]);
			dnv[j][k] = alpha*ez[k]*x[j] + alpha*dv[j][k];
			printf("dnv%d%d = a*e%d*x%d + a*dv%d%d\n",j+1,k+1,j+1,k+1,j+1,k+1);
			printf("     = %.4f*%.4f*%.4f + %.4f*%.4f = %.4f\n",alpha,ez[k],x[j],alpha,dv[j][k],dnv[j][k]);
			nv[j][k] = v[j][k] + dv[j][k];
			printf("nv%d%d = v%d%d + dv%d%d\n",j+1,k+1,j+1,k+1,j+1,k+1);
			printf("     = %.4f + %.4f = %.4f\n",v[j][k],dv[j][k],nv[j][k]);
			v[j][k] = nv[j][k];
			printf("v%d%d = nv%d%d\n",j+1,k+1,j+1,k+1);
			printf("v%d%d = %.4f\n",j+1,k+1,nv[j][k]);

		}
	}
	
	printf("Sudah puas ? (y untuk keluar/enter untuk melanjutkan) : ");	
	scanf("%c",&menu);
	switch(menu)
	{
		case 'y':
			puas = puas+1;
			break;
		case 't':
			break;
		default:
			break;
	}
	}

}

