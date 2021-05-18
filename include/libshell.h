#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "exc_req.h"

// the void is the shell instance
typedef uint8_t (*shell_callback) (void*, char*);

enum {
  SHELL_CONTINUE,
  SHELL_EXIT
};

// Anything that does not need to be directly edited by the user goes in _shell_inst
struct _shell_config{
  char* pkey;
  char* comment;
  FILE* stream_in;
  FILE* stream_out;
  shell_callback callback;
};

struct _shell_stats{
  size_t commands_processed;
  size_t comments_processed;
};

struct _shell_inst{
  struct _shell_config config;
  struct _shell_stats stats;
};

typedef struct _shell_inst shell_inst_t;
typedef struct _shell_config shell_config_t;

extern void shell_run_default(shell_callback callback);
extern void shell_run(shell_config_t* config);