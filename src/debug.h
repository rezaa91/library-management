#ifndef DEBUG_H_
#define DEBUG_H_

#define die(msg) fprintf(stderr, "%s-%d-%s: %s\n", __FILE__, __LINE__, __FUNCTION__, msg); exit(1);
#define debug(msg) fprintf(stdout, "%s-%d-%s: %s\n", __FILE__, __LINE__, __FUNCTION__, msg)

#endif
