#ifndef _TI994A_COMPAT_H
#define _TI994A_COMPAT_H

#define NULL ((void*)0)
typedef unsigned int size_t;
typedef int ssize_t;
typedef unsigned int off_t;

struct FILE_t
{
  size_t (*read)(struct FILE_t *f, unsigned char *buf, size_t size);
  size_t (*write)(struct FILE_t *f, const unsigned char *buf, size_t size);
  int    (*seek)(struct FILE_t *f, off_t offset, int whence);
  int    (*close)(struct FILE_t *f);
  unsigned int flags;
  unsigned char unget;
  unsigned int offset;
  unsigned int filenum;
  void *cookie;
  unsigned int max_size;
};

typedef struct FILE_t FILE;

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;


/*
int printf(const char *format, ...);

int strcmp(const char *s1, const char *s2);
char *strcpy(char *toHere, const char *fromHere);

char *strncpy(char *toHere, const char *fromHere, size_t count);
size_t strlen(const char *s);
*/

char *strncpy(char *toHere, const char *fromHere, size_t count);
char* fgets(char *buffer, int size, FILE *f);
extern void gets(char *buffer, int size);
#endif
