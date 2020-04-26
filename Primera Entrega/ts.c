#include "ts.h"
#include <string.h>


void initTs(FILE *fp)
{
    fprintf(fp, "%-35s %-20s %-45s %-20s", "NAME", "TYPE", "VALUE", "LENGTH");
}

void insertInTs(char *text, char *type, char *value, char *length)
{
	if (searchTs(text) == 0)
	{
		saveTs(text,type,value,length);
	}
}

void saveTs(char *text, char *type, char *value, char *length)
{
    FILE *fp = fopen("ts.txt", READ_FILE);
    if (!fp)
    {
        fp = fopen("ts.txt", APPEND_FILE);
        initTs(fp);
        fprintf(fp, "\n%-35s %-20s %-45s %-20s", text, type, value, length);
        fclose(fp);
    }
    else
    {
        fp = fopen("ts.txt", APPEND_FILE);
        fprintf(fp, "\n%-35s %-20s %-45s %-20s", text, type, value, length);
        fclose(fp);
    }
}

int searchTs(char *text){
	
	char linea[1000],word[100];
	
	FILE *fp = fopen("ts.txt", READ_FILE);
    if(fp!= NULL) 
	{	
		while(fgets(linea,sizeof(linea),fp))
		{
			sscanf(linea, "%s", word);
			if(strcmp(word,text)==0){
				fclose(fp);
				return 1;
			}
		}
	}
	fclose(fp);
	return 0;
}


