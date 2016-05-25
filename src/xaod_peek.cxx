#include "POOLRootAccess/TEvent.h"
#include "GaudiKernel/ToolHandle.h"
#include "TrigDecisionTool/TrigDecisionTool.h"

int main(int argc, char* argv[]) {
  POOL::TEvent evt;
  evt.readFrom(argv[1]);


  ToolHandle<Trig::TrigDecisionTool> tdt;
  tdt.setTypeAndName("Trig::TrigDecisionTool/TrigDecisionTool");
  tdt.retrieve(); //retrieve does the initialization

  for(int i=0;i<evt.getEntries();i++) {
    evt.getEntry(i);
    std::cout << "is passed: " << tdt->isPassed("HLT_.*") << std::endl;
  }
  return 0;
}
