void get_data(char file_name[], int n[2],double t[5], double other[2]);
void write_data(char file_name[], double data[20][20], int n[2]);
//reads n no of data points from the file file_name and stores in the array coeff
void get_data(char file_name[], int n[2],double t[5], double other[2])
{
int i=0;
FILE *fp;
fp=fopen(file_name,"r");
//reading the size
fscanf(fp,"%d %d",&n[0],&n[1]);
printf("%d %d\n",n[0],n[1]);
for(i=0;i<=3;i=i+1)
{
fscanf(fp,"%lf",&t[i]);
printf("%lf ",t[i]); 
}

//error and lambda
fscanf(fp,"%lf %lf",&other[0],&other[1]);
printf("\n%lf %lf\n",other[0],other[1]);
fclose(fp); 
}
void write_data(char file_name[], double data[20][20], int n[2])
{
int i=0,j;
FILE *fp;
fp=fopen(file_name,"w"); 
for(i=0;i<n[0]+2;i=i+1)
{
	for(j=0;j<n[1]+2;j++) fprintf(fp,"%lf ",data[i][j]);
	fprintf(fp,"\n");
}
fclose(fp); //Closing the file opened
}