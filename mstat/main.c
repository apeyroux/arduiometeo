#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/queue.h>

#include "mstat.h"

int usage() {
	fprintf(stdout, "usage: -f /path/to/meteo.log\n");
	exit(EXIT_SUCCESS);
}

int main(int ac, char **av) {

	int ch;
	char *filename = NULL;
	FILE *meteo_fd = NULL;

	while(-1 != (ch = getopt(ac, av, "f:"))) {
		switch(ch) {
			case 'f':
				filename = strdup(optarg);
				break;
			default:
				break;
		}	
	}

	if(NULL == filename)
		usage();

	fprintf(stdout, "use : %s\n", filename);

	if(NULL == (meteo_fd = fopen(filename, "r"))) {
		fprintf(stderr, "error: can't open %s\n", filename);
		return EXIT_FAILURE;
	}

	LIST_HEAD(listmeteodata, meteodata_s) head;
	LIST_INIT(&head);

	char buf[1024];
	while(0 != fgets(buf, 1024, meteo_fd)) {
		meteodata_t *md_p = newmeteodata(buf);
		LIST_INSERT_HEAD(&head, md_p, entries);
	}

	meteodata_t *item = malloc(sizeof(meteodata_t));
	LIST_FOREACH(item, &head, entries) {
        printf("json:%s\n", item->json);
    }

	// Free partie
	free(filename);
	free(meteo_fd);

	return EXIT_SUCCESS;
}
