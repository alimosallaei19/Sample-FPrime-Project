// ======================================================================
// \title  Pinger.cpp
// \author alimos
// \brief  cpp file for Pinger component implementation class
// ======================================================================

#include "Components/Pinger/Pinger.hpp"
#include "FpConfig.hpp"
#include <stdlib.h>

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  Pinger ::
    Pinger(const char* const compName) :
      PingerComponentBase(compName)
  {
	this->m_randSeed = 78607860;
  }

  Pinger ::
    ~Pinger()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void Pinger ::
    ping_handler(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    this->tlmWrite_RandomTelem(rand());
  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void Pinger ::
    SET_RANDOM_SEED_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        U32 seed
    )
  {
    this->m_randSeed = seed;
    srand(seed);
    this->log_ACTIVITY_HI_SeedChanged(seed);
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
