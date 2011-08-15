#pragma once

#include "../page.h"
#include "section2004.h"

namespace libredwgpp {

class DWGBuffer;

class SectionMap : public Section2004
{
  ////////////////////////////////////////////////////////////////
  // Definitions
  ////////////////////////////////////////////////////////////////
  public:
    typedef std::map<int32_t, Page> SectionsMap;

  ////////////////////////////////////////////////////////////////
  // Members
  ////////////////////////////////////////////////////////////////
  private:
    /// All sections listed here
    SectionsMap mSections_;

    static const int32_t s_guard;

  ////////////////////////////////////////////////////////////////
  // Constructors & Destructor
  ////////////////////////////////////////////////////////////////
  public:
    SectionMap(Archive& archive, const Page& single);

    virtual ~SectionMap() {}

  ////////////////////////////////////////////////////////////////
  // Operators
  ////////////////////////////////////////////////////////////////
  private:

  ////////////////////////////////////////////////////////////////
  // Functions
  ////////////////////////////////////////////////////////////////
  public:
    const Page* findPage(int32_t id) const;

  private:
    virtual int32_t getGuard() const { return s_guard; }

    virtual core::ResultCode restoreData(DWGBuffer& buffer);
};

////////////////////////////////////////////////////////////////

}
