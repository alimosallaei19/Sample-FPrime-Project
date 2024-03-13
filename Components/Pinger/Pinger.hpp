// ======================================================================
// \title  Pinger.hpp
// \author alimos
// \brief  hpp file for Pinger component implementation class
// ======================================================================

#ifndef Components_Pinger_HPP
#define Components_Pinger_HPP

#include "Components/Pinger/PingerComponentAc.hpp"

namespace Components {

  class Pinger :
    public PingerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct Pinger object
      Pinger(
          const char* const compName //!< The component name
      );

      //! Destroy Pinger object
      ~Pinger();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for ping
      void ping_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          NATIVE_UINT_TYPE context //!< The call order
      ) override;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command SET_RANDOM_SEED
      //!
      //! TODO
      void SET_RANDOM_SEED_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          U32 seed
      ) override;
      U32 m_randSeed = 7867860;
  };

}

#endif
