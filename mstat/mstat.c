#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "mstat.h"

#define BSIZE 2048

meteodata_t *newmeteodata(char *content) {
		meteodata_t *meteodata_p = NULL;
		char *jsonstring = NULL;

		if(NULL == (meteodata_p = (meteodata_t *) malloc(sizeof(meteodata_t)))) 
			return NULL;

		if(NULL != content) {
			meteodata_p->content = strdup(content); 
			meteodata_p->size = strlen(content)+1;
			jsonstring =  strdup(strrchr(content, ';'));
			jsonstring++; // permet de petter le ; de debut
			jsonstring[strlen(jsonstring)-1] = '\0'; // sup du \n
			meteodata_p->json = strdup(jsonstring);
		}

		return meteodata_p;
}
