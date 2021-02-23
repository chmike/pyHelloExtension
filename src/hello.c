#include <string.h>
#include <stdlib.h>

// hello return a heap allocated string containing the name appended 
// to "hello " and followed by "!".
const char *hello(const char *name) {
	if (name == NULL)
		return NULL;
	const char *txt = "hello ";
    char *buf = malloc(strlen(txt)+strlen(name)+2);
    if (buf == NULL)
    	return NULL;
    buf[0] = '\0';
	strcat(buf, txt);
	strcat(buf, name);
	strcat(buf, "!");
    return buf;
}
