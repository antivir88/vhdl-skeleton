#include <stdlib.h>
#include "obj_dir/Vmain.h"

#ifndef TRACED
#define TRACED false
#else
#include <verilated_vcd_c.h>
#endif


int main(int argc, char** argv)
{
  Verilated::commandArgs(argc, argv);
  Vmain* module = new Vmain;

  #if TRACED==true
   VerilatedVcdC* vcd = nullptr;
   Verilated::traceEverOn(true);
   vcd = new VerilatedVcdC;
   module->trace(vcd, 99);
   vcd->open("out.vcd");
   vluint64_t vtime = 0;
  #endif

  while( !Verilated::gotFinish() ) {
    module->eval();

    #if TRACED==true
     vtime += 1;
     vcd->dump( vtime );
    #endif

    printf("traced: %d\n", TRACED);
  }

  #if TRACED==true
   module->final();
   if (vcd) {
     vcd->close();
   }
  #endif

  delete module;
  exit(EXIT_SUCCESS);
}
