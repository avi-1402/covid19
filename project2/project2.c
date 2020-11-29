/*
GROUP NO.18

MEMBERS::
AVINAV JAIN 19UCS021
AMIT GUPTA 19UCS011
SIDDHARTHA SINGH 19UCS167
SURENDRA KUMAR 19UCC018
DIVYA JAIN 19UCS216
ARPITA JAIN 19DCS008
VISHAL DAYALANI 19UCS012

DATE: 09-05-2020

This file does the experiment.
*/
#include "project2.h"

double stanDev(int arr[],float m){
    double SD = 0.0;
    for (int i = 0; i < 10; ++i)
        SD += pow(arr[i] - m, 2);
    return sqrt(SD / 10);
}
double mean(int *arr){
	double sum = 0.0;
	for (int i = 0; i < 10; i++)
		sum += arr[i];
	return sum/10;
}
int randomYes (){
	srand(clock());
	int a = rand() % 1000;
	if (!a)
		return 1;
	return 0;
}
int hcf (int x, int y){
	if (y == 0)
		return x;
	return hcf(y, x % y);
}
int isprime(int a){
	for (int i = 2; i < a / 2; i++)
		if(!(a % i))
			return 0;
	return 1;
}

int countPrimeFactors (int x, int y){
	int z = hcf(x,y);
	int count = 0;
	for (int i = 2; i <= z; i++)
	{
		if (!(z % i) && isprime(i))
			count++;
	}
	return count;
}
void markProviders(int population,int serviceP,int **matrix){
	srand(clock());
	int count,index;
	count = (population * serviceP) / 100;
	while (count){
		index = rand() % population;
		if (!matrix[index][population]){
			matrix[index][population] = 'S';
			count--;
		}
	}
}
void markInteractions(int population,int distancing,int serviceP,int **matrix){
	int takenAvg,serviceAvg;
	serviceAvg = (population * serviceP)/100;
	int nonProviders = 100 - serviceP;
	switch(serviceP){
		case 3: serviceAvg *= (population * 5)/100; break;
		case 8: serviceAvg *= (population * 3)/100; break;
	}
	switch(distancing){
		case 'A': takenAvg = 20; break;
		case 'B': takenAvg = 10; break;
		case 'C': takenAvg = 7;  break;
		case 'D': takenAvg = 7;
				  serviceAvg /= 2; break;
	}
	int avgInteractions = (takenAvg*population*nonProviders)/100;
	int lowerBound = ((avgInteractions + serviceAvg)* 90) / 100;
	int upperBound = ((avgInteractions + serviceAvg) * 110) / 100;
	int interactions = (rand() % (upperBound - lowerBound + 1)) + lowerBound;
	interactions -= serviceAvg;

	while(serviceAvg > 0 || interactions > 0){
		for (int i = 0; i < population; i++){
			if (matrix[i][population] == 'S')
				for (int j = i+1; j < population && serviceAvg > 0; j++){
					if (!matrix[i][j] && biasedYes(i,j)){
						matrix[i][j] = matrix[j][i] = 1;
						serviceAvg -= 1;
					}
				}
			else
				for (int j = i+1; j < population && interactions > 0; j++){
					if (!matrix[i][j] && matrix[j][population] != 'S' && biasedYes(i,j)){
						matrix[i][j] = matrix[j][i] = 1;
						interactions -= 2;
					}
				}
		}
	}
}

void markInfected(int population,int infected,int** matrix){
	int index;
	while (infected){
		index = rand() % population;
		if (matrix[index][population] != 'I'){
			matrix[index][population] = 'I';
			infected--;
		}
	}
}

void BFS(int population, int** matrix,int start, char* visited) 
{  
    int queue[2*population];
    int front = 0,back = 0;
    queue[back++] = start;
    visited[start] = 1; 
    int vis; 
    while (front != back) { 
        vis = queue[front++];
        for (int i = 0; i < population; i++) { 
            if (matrix[vis][i] == 1 && visited[i] != 1) {  
                queue[back++] = i;
                matrix[start][i] = 1; 
                visited[i] = 1; 
            } 
        } 
    } 
} 

void findInfected(int population, int** matrix){
    char visited[population];
	for (int i = 0; i < population; i++)
		if (matrix[i][population] == 'I')
			BFS(population,matrix,i,visited);
}

int countInfected(int population,int** matrix){
	int count = 0;
	for (int i = 0; i < population; i++){
		if (matrix[i][population] == 'I')
			for (int j = 0; j < population; j++)
				if (matrix[j][population] != 'I' && matrix[j][population] != 'A' && matrix[i][j] == 1){
					matrix[j][population] = 'A';
					count++;
				}
	}
	return count;
}

int doExperiment(int population ,int serviceP,int infected,int distancing){
	int **matrix;
	matrix = (int**) malloc (sizeof(int*) * population);
	for(int i = 0; i < population; i++)
		matrix[i] = (int*) calloc (population+1,sizeof(int));

	markProviders(population,serviceP,matrix);
	markInteractions(population,distancing,serviceP,matrix);
	markInfected(population,infected,matrix);
	findInfected(population,matrix);
	int count = countInfected(population,matrix);
	for (int i = 0; i < population; i++)
		free(matrix[i]);
	free(matrix);
	return count;
}

int biasedYes(int x, int y){
	int common = countPrimeFactors(x+1001,y+1001);
	while (common--)
		if (randomYes())
			return 1;
	return 0;
}
