// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
char* strlcpy(char *dst, const char *src, int size);
char* strcat_s(char *dest, char *right, int max_len);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, const char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
