#pragma once

#include "../decoder.h"

namespace libredwg2 {

class DWGBuffer;

class Decoder2004_2 : public Decoder
{
  ////////////////////////////////////////////////////////////////
  // Definitions
  ////////////////////////////////////////////////////////////////
  public:

  ////////////////////////////////////////////////////////////////
  // Members
  ////////////////////////////////////////////////////////////////
  private:

  ////////////////////////////////////////////////////////////////
  // Constructors & Destructor
  ////////////////////////////////////////////////////////////////
  public:
    virtual ~Decoder2004_2() {}

  ////////////////////////////////////////////////////////////////
  // Operators
  ////////////////////////////////////////////////////////////////
  private:

  ////////////////////////////////////////////////////////////////
  // Functions
  ////////////////////////////////////////////////////////////////
  public:
    virtual core::ResultCode decode(core::IReadBuffer& raw, core::IWriteBuffer& out);

  private:
    uint32_t readLiteralLength(DWGBuffer& in, uint8_t& opcode);

    uint32_t readOffset2b(DWGBuffer& in, uint32_t& litlen);

    uint32_t readOffsetLong(DWGBuffer& in);
};

////////////////////////////////////////////////////////////////

}