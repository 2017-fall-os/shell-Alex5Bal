/*
 * Author: Alejandro Balderrama
 * Class: Theory of Operating Systems
 * Professor: Dr. Freudenthal
 * Project: Shell
 *
 * Description: This library is used to handle string manipulations in the program.
 */
#include <stdlib.h>
#include <stdio.h>
#include "mystrlib.h"

int strComp(char* string1, char* string2) /**** Function compares two strings and returns 1 if it's a match ****/
{
	char match = 1;		/** Initially match condition is true **/
	int i = 0;

	while(string1[i] != '\0')		/** Traverse string until null character is found **/
	{
		if(string1[i] != string2[i])	/** If the characters a the current index don't match; **/
			match = 0;		/** Set match to false **/

		i++;
	}

	if(string2[i] != '\0')		/** Check to see if one of the strings is longer than the other **/
		match = 0;

	return match;
}

int strLen(char* stringIn) /**** Function returns the length of a string ****/
{
	int length = 0, i = 0;		/** Initialize length to 0 **/

	while(stringIn[i] != '\0')		/** Traverse string until null character is found **/
	{
		length++;		/** Increment the length by 1 every iteration **/
		i++;
	}
	return length;
}

char* strCat(char* string1, char* string2) /**** Function concatenates two strings and returns a pointer to a string ****/
{
	char* stringOut;		/** String pointer to be returned **/
	int length1, length2, i, j;

	length1 = strLen(string1);		/** Determine the length of the first string **/
	length2 = strLen(string2);		/** Determine the length of the second string **/

	stringOut = (char*) malloc(length1 + length2 + 1);		/** Use the lengths of the two strings to allocate memory for the new string **/

	for(i = 0; i < length1; i++)		/** Transfer first string into the new string **/
	{
		stringOut[i] = string1[i];
	}

	for(j = 0; j < length2; j++)		/** Append the second string into the new string **/
	{
		stringOut[i + j] = string2[j];
	}

	stringOut[i + j] = '\0';		/** End the new string with a null character **/

	return stringOut;
}

char* strCopy(char* dest, char* src) /**** Function copies one string to another ****/
{
	int i = 0;

	while(src[i] != '\0')	/** Traverse the source string until null character is found **/
	{
		dest[i] = src[i];	/** Copy each character from the source string to the destination string **/
		i++;
	}

	dest[i] = '\0';		/** End destination string with the null character **/

	return dest;
}

void printStringVec(char** vectorIn)	/**** Function prints out a vector of strings ****/
{
	for(int i = 0; vectorIn[i] != '\0'; i++)		/** Traverse vector until null character is found **/
	{
		printf("path[%d] : %s\n", i, vectorIn[i]);		/** Print out the string at each vector position **/
	}
}

char* removeNewLine(char* stringIn)		/**** Function removes the newline character from the end of a string ****/
{
	char* stringOut;		/** String pointer to be returned **/

	for(int i = 0; stringIn[i] != '\0'; i++)		/** Traverse string until null character is found **/
	{
		if(stringIn[i] == '\n')			/** If newline character is found; **/
			stringIn[i] = '\0';			/** Replace with null character **/
	}

	stringOut = stringIn;

	return stringOut;
}
