#pragma once

#include <file/archive.h>
#include <parser/section.h>

namespace libredwg2 {

class Section2004 : public Section
{
  ////////////////////////////////////////////////////////////////
  // Definitions
  ////////////////////////////////////////////////////////////////
  public:

  ////////////////////////////////////////////////////////////////
  // Members
  ////////////////////////////////////////////////////////////////
  protected:
    /// The archive to read from
    Archive& archive_;

    /// The section identifier

  private:
    /// The offset where the section starts
    size_t offset_;

  ////////////////////////////////////////////////////////////////
  // Constructors & Destructor
  ////////////////////////////////////////////////////////////////
  public:
    Section2004(Archive& archive, size_t offset);

    virtual ~Section2004() {}

  ////////////////////////////////////////////////////////////////
  // Operators
  ////////////////////////////////////////////////////////////////
  private:

  ////////////////////////////////////////////////////////////////
  // Functions
  ////////////////////////////////////////////////////////////////
  public:
    virtual core::ResultCode restore();

  private:
    virtual int32_t getGuard() const = 0;

    virtual core::ResultCode restoreData(core::IReadBuffer& buffer) = 0;
};

////////////////////////////////////////////////////////////////

}
