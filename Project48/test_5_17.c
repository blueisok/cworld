#define _CRT_SECURE_NO_WARNINGS
#include   <stdio.h>
#include   <string.h>
struct student {
	long  sno;
	char  name[10];
	float  score[3];
};
/**********found**********/
struct student fun(struct  student  a)
{
	int  i;
	a.sno = 10002;
	/**********found**********/
	strcpy(a.name, "LiSi");
	/**********found**********/
	for (i = 0; i < 3; i++) a.score[i] += 1;
	return  a;
}
void main()
{
	struct student  s = { 10001,"ZhangSan", 95, 80, 88 }, t;
	int  i;
	printf("\n\nThe original data :\n");
	printf("\nNo: %ld  Name: %s\nScores:  ", s.sno, s.name);
	for (i = 0; i < 3; i++)  printf("%6.2f ", s.score[i]);
	printf("\n");
	t = fun(s);
	printf("\nThe data after modified :\n");
	printf("\nNo: %ld  Name: %s\nScores:  ", t.sno, t.name);
	for (i = 0; i < 3; i++)  printf("%6.2f ", t.score[i]);
	printf("\n");
}

#include <stdio.h>
void fun(int a, int b, long* c)
{

	*c = (a / 10) + (a % 10) * 100 + (b % 10) * 10 + (b / 10) * 1000;
}
void main()
{
	int a, b; long c;
	void NONO();
	printf("Input a, b:");
	scanf("%d %d", &a, &b);
	fun(a, b, &c);
	printf("The result is: %ld\n", c);
	NONO();
}
void NONO()
{
	FILE* rf, * wf;
	int i, a, b; long c;

	rf = fopen("in.dat", "r");
	wf = fopen("out.dat", "w");
	for (i = 0; i < 10; i++) {
		fscanf(rf, "%d,%d", &a, &b);
		fun(a, b, &c);
		fprintf(wf, "a=%d,b=%d,c=%ld\n", a, b, c);
	}
	fclose(rf);
	fclose(wf);
}

