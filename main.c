/**
 * This program inserts a blank line after each line in a file, i.e., it double 
 * spaces the text
 **/

#include <stdio.h>
#include "ins_bl_line.h"

#define LB printf("\n")

int main(void)
{
	/* Local Declarations */
	int	n;
	int	count_lines_inserted = 0;
	FILE*	sp_read;
	FILE*	sp_write;

	/* Program Intro */
	LB; printf("Given a text file, this program will blank lines after each line");
	LB; printf("Please enter the no. of blank lines to separate each line from next:\t");
	scanf("%d", &n);

	/* Open files */
	if ((sp_read = fopen("speech.txt", "r")) == NULL)
	{
		LB; printf("ERROR1: File failed to open");
		return -1;
	}

	if ((sp_write = fopen("output.txt", "w")) == NULL)
	{
		LB; printf("ERROR1: File failed to open");
		return -1;
	}

	/* Function to insert blank line after each line */
	count_lines_inserted = ins_bl_line(n, sp_read, sp_write);
	LB; printf("Program run successful");
	LB; printf("%d lines inserted", count_lines_inserted);

	/* Close files */
	if (fclose(sp_read) == EOF)
	{
		LB; printf("ERROR2: File failed to close");
		return -2;
	}

	if (fclose(sp_write) == EOF)
	{
		LB; printf("ERROR2: File failed to close");
		return -2;
	}

	/* Exit Program */
	LB; LB;
	return 0;
}

