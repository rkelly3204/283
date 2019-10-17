#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUFFER_SIZE 1000

void replaceAll(char *str, const char *oldWord, const char *newWord, const char *prefix);

int main(int argc, char *argv[])
{
	
	struct dirent *de; //Pointer dir
	DIR *dr = opendir(".");
	int count = 0;
	int index = 0;

	FILE * fPtr;
	FILE * fPtrt;

	char *path;
	char *oldWord;
	char *newWord;
	char *prefix;

	char buffer[BUFFER_SIZE];
	
	if(argc > 2)
	{
		oldWord = argv[1];
		newWord = argv[2];
		prefix = argv[3];
	}

	if (dr == NULL)
	{
		printf("Could not open current dir");
		return 0;
	}

	while ((de = readdir(dr)) != NULL){

		int length = strlen(de->d_name);

		if (strncmp(de->d_name + length - 4, ".txt", 4) == 0){
			path = de->d_name;
			printf("Checking: %s\n", de->d_name);

			//Open the required files
			fPtr = fopen(path, "r");
			fPtrt = fopen("replace.tmp", "w");

			//fOpen() return NULL if unable to open file in given mode
			if (fPtr == NULL || fPtrt == NULL)
			{
				//Unable to open file then exit
				printf("\nUnable to open file.\n");
				exit(EXIT_SUCCESS);
			}

			/*
			 * Read line from source file and write to destination
			 * file after replacing given word
			 */
			while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
			{
			//Replace all occurance of word from current line
			replaceAll(buffer, oldWord, newWord, prefix);

			// After replacing write it to a temp file
			fputs(buffer, fPtrt);
			}	
	
			//Close all the files to release the resource
			fclose(fPtr);
			fclose(fPtrt);

			// Delete original source file
			remove (path);
				
			//Rename temp file as orginal file
			rename("replace.tmp", path);

		}

	}
	return 0;


}

// Replace all occurrence of a given word in a string
void replaceAll(char *str, const char *oldWord, const char *newWord, const char *prefix)
{
	char *pos, temp[BUFFER_SIZE];
	int index = 0;
	int owlen;
	int linec;

	//owlen = strlen(oldWord);

	// This is for the find parameter
	if ((pos = strstr(str, oldWord)) != NULL)
	{
		
		owlen = strlen(oldWord);
		linec = 1;

		//Repeat till all occurrence are replaced
		while ((pos = strstr(str, oldWord)) != NULL)
		{
			// Backup the current line
			strcpy(temp, str);

			//Index of current found word
			index = pos - str;

			//Terminate str after word found index
			str[index] = '\0';

			//Concatenate str with new word
			strcat(str, newWord);

			//Concatenate str with the remaining words after oldWord found in index
			strcat(str, temp + index + owlen);

			printf("Successfully replace | %s with %s | on line %d\n", oldWord, newWord, linec);
			linec ++;
		}
		printf("------------------------------------------------\n");
	}

	// Finds the prefix parameter
	else if ((pos = strstr(str, prefix)) != NULL)
	{
		owlen = (strlen(oldWord) + strlen(prefix)+3);
		linec = 1;

		char new_str[owlen];
		strcpy(temp,str);
		index = pos - str;
		str[index] = '\0';
				
		strcat(new_str, prefix);
		strcat(new_str,oldWord);

		strcat(str,new_str);
		strcat(str, temp + index + owlen);

			
		printf("Successfully preappend | %s with %s |%d\n", oldWord, prefix, linec);
		linec ++;

		printf("-------------------------------------------\n");
	}
	
	else
	{
		printf("Could not find | %s or %s |in this in this file\n", oldWord, prefix);
		printf("------------------------------------------------\n");
	}


}


