#include "computer.h"
#include "helper.h"
Computer::Computer():defaultCpu(nullptr), defaultCpuprog(nullptr),
        defaultMemory(nullptr),option(0){}

Computer::Computer(int opt) : defaultCpu(nullptr), defaultCpuprog(nullptr)
, defaultMemory(nullptr) {
    option=opt;
    if (!controlOption())
    {
          cerr << "the option value is false!!" << endl;
          option=-1;
    }
}

Computer::Computer(CPU& cpuref, CPUProgram& progref, Memory& memoryref, int opt) {
    /*change the defaul member with referansce*/
    defaultCpu = &cpuref;
    defaultCpuprog = &progref;
    defaultMemory = &memoryref;
    option = opt;
    if (!controlOption()){
           cerr << "the option value is false!!" << endl;
           option=-1;
    }
}

/*setters*/
void Computer::setCPU(CPU& cpuobj) {
    defaultCpu = &cpuobj;
}
void Computer::setOption(int value){
      if (value < 0 || value > 2) {
           cerr << "the option value is false!!" << endl;
      }
      else
          option=value;
}

void Computer::setCPUProgram(CPUProgram& obj) {
    defaultCpuprog = &obj;
}

void Computer::setMemory(Memory& obj) {
    defaultMemory = &obj;

}

bool Computer::controlOption()const {
    if (option < 0 || option > 2) {
        return false;
    }
    else
        return true;

}

/*getters*/
 CPU& Computer::getCPU() {
   
        return *defaultCpu;
}

 CPUProgram& Computer::getCPUProgram() {
   
        return *defaultCpuprog;
}


 Memory& Computer::getMemory() {
    
        return *defaultMemory;

}

int Computer::getOption()const {
    return option;
}

void Computer::execute() {
    if (defaultCpu == nullptr || defaultCpuprog == nullptr || defaultMemory == nullptr) {
        cerr << "Please initialize the all  computer's members!!"<<endl;
        return;
    }
    else if(!controlOption())
    {
        cerr<<"Computer option value is false!!"<<endl;
        return;
    }
    else if(defaultCpuprog->size()==0)
    {
        cerr<<"The file is false,Please check it!!"<<endl;
        return;
    }
    defaultCpu->setOption(option);
    defaultCpuprog->setoption(option);
    defaultMemory->setOption(option);
    cout<<defaultMemory->getOption();
    while(!defaultCpu->gethalted())
    {
          string line=defaultCpuprog->getLine(defaultCpu->getPC()-1);
          defaultCpu->execute(line,*defaultMemory);
    }
}