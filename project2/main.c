/*
This file contains the main fuction which calls the doexperiment() function.
*/
#include "project2.h"

int main()
{
	int population, serviceP, infected,arr[10],j = 0,k = 0;
	double m[4],sd[4];
	clock_t t;
	printf("\n\t\t\tCOVID-19 (A GLOBAL PANDEMIC)\n\n\n");
	printf("In the time of this global pandemic, we are here with this program to help the government to\n");
	printf("detect the number of testing kits they need to provide to a particular town admininstration.\n");
	printf("Just provide the total population of the town, the percentage of service providers and the count\n");
	printf("of infected people detected and this program will perform different random experiments and\n");
	printf("outputs the number of people needed to be tested based on different scenarios to help the\n");
	printf("government decide the number of testing kits they need to provide.\n\n");
	printf("Enter the population of the town( >100):: ");
	scanf("%d",&population);
	printf("Enter the percentage of the service providers(either 3 or 8):: ");
	scanf("%d",&serviceP);
	printf("Enter the number of detected infected persons:: ");
	scanf("%d",&infected);
	t = clock();
	if ((serviceP != 3 && serviceP != 8) || population < 100){
		printf("\nERROR 151:: Please give the data as specified.\n(program aborted)\n");
		exit(0);
	}
	if (infected > population){
		printf("\nERROR 028:: Infected people more than town population.\n(program aborted)\n");
		exit(0);
	}

	printf("\n\nPlease be patient, the program might take some time depending on the population :)\n\n");
	printf("If there is no social distancing::\n\n");
	for (int i = 00; i < 10; i++){
		arr[i] = doExperiment(population,serviceP,infected,'A');
		printf("Experiment no. %d, people to be tested = %d\n",i+1,arr[i]);
	}
	printf("\n");
	m[j++] = mean(arr);
	sd[k++] = stanDev(arr,m[j-1]);
	printf("Mean in this case =  %d\n",(int)m[j-1]);
	printf("Standard Deviation = %lf\n\n",sd[k-1]);
	printf("If there is 50 percent social distancing::\n\n");
	for (int i = 00; i < 10; i++){
		arr[i] = doExperiment(population,serviceP,infected,'B');
		printf("Experiment no. %d, people to be tested = %d\n",i+1,arr[i]);
	}
	printf("\n");
	m[j++] = mean(arr);
	sd[k++] = stanDev(arr,m[j-1]);
	printf("Mean in this case =  %d\n",(int)m[j-1]);
	printf("Standard Deviation = %lf\n\n",sd[k-1]);
	printf("If there is 33 percent social distancing::\n\n");
	for (int i = 00; i < 10; i++){
		arr[i] = doExperiment(population,serviceP,infected,'C');
		printf("Experiment no. %d, people to be tested = %d\n",i+1,arr[i]);
	}
	printf("\n");
	m[j++] = mean(arr);
	sd[k++] = stanDev(arr,m[j-1]);
	printf("Mean in this case =  %d\n",(int)m[j-1]);
	printf("Standard Deviation = %lf\n\n",sd[k-1]);
	printf("If there is 33 social distancing and interactions with \n");
	printf("service providers is also reduced to 50 percent::\n\n");
	for (int i = 00; i < 10; i++){
		arr[i] = doExperiment(population,serviceP,infected,'D');
		printf("Experiment no. %d, people to be tested = %d\n",i+1,arr[i]);
	}
	printf("\n");
	m[j++] = mean(arr);
	sd[k++] = stanDev(arr,m[j-1]);
	printf("Mean in this case =  %d\n",(int)m[j-1]);
	printf("Standard Deviation = %lf\n\n\t",sd[k-1]);
	for (int i = 0; i < 98; i++) printf("-");
	printf("\n\t DESCRIPTION OF EXPERIMENT\t\t    VALUE\n\t");
	for (int i = 0; i < 98; i++) printf("-");
	printf("\n");
	printf("\t Population of the town (P)\t\t    %d\n",population);
	printf("\t Count of major service providers (S)\t    %d \n",(population*serviceP)/100);
	printf("\t Count of known infected persons (IR)\t    %d \n",infected);
	printf("\t\n\t RESULTS\t\t\t\t    Count of person who need to be\n");
	printf("\t\t\t\t\t\t    tested -- Average of 10 runs (with standard deviation)\n\n");
	printf("\t Without any social distancing (T100)\t    %d (%lf)\n", (int)m[0],sd[0]);
	printf("\t With social distancing reducing contacts   %d (%lf)\n\t to 50 percent (T50) \n",(int)m[1],sd[1]);
	printf("\t With social distancing reducing contacts   %d (%lf)\n\t to 33 percent (T33) \n",(int)m[2],sd[2]);
	printf("\t With social distancing reducing contacts   %d (%lf)\n\t to 50 percent with ",(int)m[3],sd[3]);
    printf("assigned \n\t service provider (TC)\n\t");
    for (int i = 0; i < 98; i++) printf("-");
	printf("\n\nTHE EXPERIMENT IS COMPLETED.\nFOLLOW SOCIAL DISTANCING.\n");
	printf("STAY HOME, STAY SAFE DURING THIS COVID-19 PANDEMIC.\n");
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC/60;
	printf("\n(Time taken = %lf minutes)\n",time_taken);
	return 0;
}
