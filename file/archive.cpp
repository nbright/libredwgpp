#include "archive.h"

#include <parser/parser.h>

namespace libredwg2 {

////////////////////////////////////////////////////////////////

Archive::Archive()
{
}

////////////////////////////////////////////////////////////////

Archive::~Archive()
{
}

////////////////////////////////////////////////////////////////

core::ResultCode Archive::read(core::IWriteBuffer& buffer, size_t pos, size_t len)
{
  if (pos + len > size_)
    return rcOutOfBounds;

  buffer.resize(len);
  fileStream_.seekg(pos);
  fileStream_.read((char*)buffer.getBuffer(), len);
  buffer.setPosition(0);
  return core::rcSuccess;
}

////////////////////////////////////////////////////////////////

core::ResultCode Archive::restore(const boost::filesystem::path& pathFile, boost::shared_ptr<Schema>& ptrSchema)
{
  // Basic tests
  if (!exists(pathFile) || !is_regular(pathFile))
  {
    LOG_ERROR("File not found: " << pathFile);
    return rcFileNotFound;
  }

  fileStream_.open(pathFile.native_file_string().c_str(), std::ios::binary);
  if (!fileStream_)
  {
    LOG_ERROR("File could not be loaded: " << pathFile);
    return rcInputError;
  }

  size_ = boost::filesystem::file_size(pathFile);

  boost::shared_ptr<Parser> ptrParser;
  core::ResultCode rc = Parser::create(*this, ptrParser);
  if (rc.isFailure())
    return rc;

  ASSERT(ptrParser != NULL);

  rc = ptrParser->parse();
  if (rc.isFailure())
    return rc;

  return core::rcSuccess;
}

////////////////////////////////////////////////////////////////

}
