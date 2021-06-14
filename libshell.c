#include "include/libshell.h"


void shell_run_default(shell_callback callback){
  shell_config_t conf={"$ ", "#",stdin, stdout,callback};
  shell_run(&conf);
}

void shell_run(shell_config_t* config){
  shell_inst_t inst={*config, {1}};
  for(;;inst.stats.commands_processed++){
    fputs(inst.config.pkey, inst.config.stream_out);
    char* ln=get_line(inst.config.stream_in);
    if(!starts_with(ln,inst.config.comment)){
      inst.stats.comments_processed++;
      continue;
    }
    switch(inst.config.callback(&inst, ln)){
      case SHELL_EXIT: return;
    }
    free(ln);
  }
}