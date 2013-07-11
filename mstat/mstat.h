#include <sys/queue.h>

struct meteodata_s {
	char *content;
	char *json;
	size_t size;
	float temperature;
	float humidity;
	LIST_ENTRY(meteodata_s) entries;
};

typedef struct meteodata_s meteodata_t; 

meteodata_t *newmeteodata(char *content);
