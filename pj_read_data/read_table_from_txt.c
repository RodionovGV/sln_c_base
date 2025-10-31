/*
Чтение данных из файла и сохранение данных в файл.
*/

// sprintf_s нужно использовать, определение отключает ошибку
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "read_table_from_txt.h"

typedef struct {
	double x1;
	double x2;
	double x3;
	double x4;
} TVariable_field;

#define KL_MEASUREMENT_VECTOR_SIZE      4

typedef union {
	TVariable_field vector;
	double array[KL_MEASUREMENT_VECTOR_SIZE];
} TValues;

typedef struct {
	char baseDir[255];
	char verbose;
	int  frameNum;
	int  logStart;
	float deltaTime;
}TRunOptions;

TRunOptions runOptions = { .baseDir = "./dbg", .verbose = 1, .frameNum = 1, .deltaTime = 1.0f / 15.0f , .logStart = 1 };

#define MAX_TARGET_NUM  1000

static TValues arr_points[MAX_TARGET_NUM];

int importPoints(char* baseDir, double* Point, int frame) {
	int result = 0;
	char fName[255] = "";
	sprintf(fName, "%s/%03d/in.m", baseDir, frame);
	FILE* importFile;
	importFile = fopen(fName, "r");
	printf("Import> file[%s]\n", fName);

	while (importFile) {
		float x1 = 0;
		float x2 = 0;
		float x3 = 0;
		float x4 = 0;
		int n = fscanf(importFile, "%f%f%f%f", &x1, &x2, &x3, &x4);
		if (n != 4) break;
		*Point++ = x1;
		*Point++ = x2;
		*Point++ = x3;
		*Point++ = x4;
		result++;
	}

	if (importFile) {
		fclose(importFile);
	}
	
	return result;
}

void exportTargets(char* baseDir, int tNum, double* Point, int frame) {

	FILE* tracklogFile;
	char fName[255] = "out.c";
	char extDbgInfo[255] = "";

	sprintf(fName, "%s/%03d/out.c", baseDir, frame);
	tracklogFile = fopen(fName, "w+"); //"a" - оставить старый файл


	if (tracklogFile) {
		printf("Export> file[%s]\n", fName);
		for (int i = 0; i < tNum; i++) {
			TValues* p = (TValues*) Point;
			fprintf(tracklogFile, "%05d \t%12.9lf \t%12.9lf \t%12.9lf \t%12.9lf\n", i,
				p->vector.x1,
				p->vector.x2,
				p->vector.x3,
				p->vector.x4);
			((TValues*)Point)++;
		}

		fclose(tracklogFile);
	}
}

void run_in_main(void) {


	int pointNum = importPoints(&runOptions.baseDir[0], &arr_points[0].array[0], 1);

	exportTargets(&runOptions.baseDir[0], pointNum, &arr_points[0], 1);
}

#ifdef __cplusplus
}
#endif