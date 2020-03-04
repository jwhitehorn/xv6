// ulib.c

char* strcpy(char*, const char*);
char* strlcpy(char *dst, const char *src, int size);
char* strcat_s(char *dest, char *right, int max_len);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
uint strlen(const char*);

// not sure where the following should live yet:
int stat(const char*, struct stat*);
void *memmove(void*, const void*, int);
void printf(int, const char*, ...);
char* gets(char*, int max);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
