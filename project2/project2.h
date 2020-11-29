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

This file contains function declaration.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include<math.h>

int biasedYes(int x, int y);
double stanDev(int arr[],float m);
double mean(int *arr);
int randomYes ();
int hcf (int x, int y);
int isprime(int a);
int countPrimeFactors (int x, int y);
void markProviders(int population,int serviceP,int **matrix);
void markInteractions(int population,int distancing,int serviceP,int **matrix);
void markInfected(int population,int infected,int** matrix);
void BFS(int population, int** matrix,int start,char* visited);
void findInfected(int population, int** matrix);
int countInfected(int population,int** matrix);
int doExperiment(int population ,int serviceP,int infected,int distancing);