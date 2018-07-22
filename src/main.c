#include <stdio.h>
#include <stdint.h>
#include "monitor.h"

void init_device();
int init_monitor(int, char *[]);
void gdb_mainloop();
void cpu_exec(uint64_t);

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
  work_mode_t mode = init_monitor(argc, argv);
  if(mode & MODE_BATCH) {
	init_device();
	cpu_exec(-1);
  } else {
	gdb_mainloop();
  }
  return 0;
}
