#include "stdio.h"

#define READ_FILE "r"
#define APPEND_FILE "a"
#define TYPE_INTEGER_TS "INT"
#define TYPE_CONST_INT_TS "CONST_INT"
#define TYPE_FLOAT_TS "FLOAT"
#define TYPE_CONST_FLOAT_TS "CONST_REAL"
#define TYPE_CONST_STRING_TS "CONST_STR"
#define TYPE_STRING_TS "STRING"

void initTs(FILE *);
int searchTs(char *);
void saveTs(char *, char *, char *, char *);
void insertInTs(char *text, char *type, char *value, char *length);
int modifyTypeTs(char *, char *);
int getType(char *text);