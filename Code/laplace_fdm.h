#include<math.h>
void solve_laplace(double T[20][20], int n[2], double error, double lambda);
void initialize_temp(double T[20][20], int n[2], double t[5]);

void solve_laplace(double T[20][20], int n[2], double error, double lambda)
{
	printf("solving the laplace equation\n");
	int i=0,j=0,counter=0,r=50;
	double tij,error_ij,tij_prev;
	double prev[20][20];
	// Initializing prev array
	for(i=0;i<n[0]+2;i++)
	{
		for(j=0;j<n[1]+2;j++)
		{
			prev[i][j] = T[i][j];
		}
	}

	while(counter<(n[0]*n[1])&&r--)
	{
		counter=0;
		for(i=1;i<=n[0];i++)
		{
			for(j=1;j<=n[1];j++)
			{
				tij = T[i-1][j] + prev[i+1][j] + T[i][j-1] + prev[i][j+1];
				tij = tij/4;
				tij = lambda*tij + (1-lambda)*prev[i][j];
				error_ij = fabs((tij-prev[i][j])/tij)*100;
				T[i][j] = tij;
				if(error_ij<error) counter++;
			}
		}
		// update prev matrix
		for(i=0;i<n[0]+2;i++)
		{
			for(j=0;j<n[1]+2;j++)
			{
				prev[i][j] = T[i][j];
			}
		}
	}
	printf("\nr - %d\n",r);
}
void initialize_temp(double T[20][20], int n[2], double t[5])
{
	int i,j;
	for(i=1;i<=n[0];i++)
	{
		for(j=1;j<=n[1];j++)
		{
			T[i][j] = 0;
		}
	}
	// t[0] for side 1 :::: VERTCAL LEFT SIDE
	for(i=0;i<n[0]+2;i++) T[i][0] = t[0];
	// t[1] for side 2 :::: HORIZONTAL DOWN SIDE
	for(j=0;j<n[1]+2;j++) T[n[0]+1][j] = t[1];
	// t[2] for side 3 :::: VERTICAL RIGHT SIDE
	for(i=0;i<n[0]+2;i++) T[i][n[1]+1] = t[2];
	// t[3] for side 4 :::: HORIZONTAL UP SIDE
	for(j=0;j<n[1]+2;j++) T[0][j] = t[3];
}
