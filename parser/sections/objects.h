#pragma once

#include "../class.h"
#include "../version.h"

namespace libredwg2 {

class ClassesParser;
class DWGBuffer;
class Object;
class Schema;

class ObjectsParser
{
  ////////////////////////////////////////////////////////////////
  // Definitions
  ////////////////////////////////////////////////////////////////
  private:
    typedef std::map<size_t, boost::shared_ptr<Object> > ObjectsMap;

  ////////////////////////////////////////////////////////////////
  // Members
  ////////////////////////////////////////////////////////////////
  private:
    Version version_;

    ObjectsMap mObjects_;

  ////////////////////////////////////////////////////////////////
  // Constructors & Destructor
  ////////////////////////////////////////////////////////////////
  public:
    ObjectsParser(const Version& version);

    virtual ~ObjectsParser() {}

  ////////////////////////////////////////////////////////////////
  // Operators
  ////////////////////////////////////////////////////////////////
  private:

  ////////////////////////////////////////////////////////////////
  // Functions
  ////////////////////////////////////////////////////////////////
  public:
    core::ResultCode restoreObject(Schema& schema, DWGBuffer& buffer, const ClassesParser& classes);
};

////////////////////////////////////////////////////////////////

}