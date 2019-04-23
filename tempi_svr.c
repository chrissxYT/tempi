#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#define INTERCHANGE_FILE
#define TEMPLATE_FILE
#define QUARK_ROOT

#define QUARK_INDEX QUARK_ROOT"/index.html"
#define QUARK_RAW QUARK_ROOT"/raw"

int main()
{
	FILE *f;
	struct stat s;
	stat(TEMPLATE_FILE, &s);
	off_t sz = s.st_size;
	char template[sz];
	f = fopen(TEMPLATE_FILE, "r");
	fread(template, 1, sz, f);
	fclose(f);
	while(1)
	{
		f = fopen(INTERCHANGE_FILE, "r");
		char data[9];
		fread(data, 1, 9, f);
		fclose(f);
		f = fopen(QUARK_RAW, "w");
		fwrite(data, 1, 9, f);
		fclose(f);
		char *str = convert2str(data);
		char bfr[strlen(str) + sz];
		sprintf(bfr, template, str);
		free(str);
	}
}
