// Windows/FileName.h

#pragma once

#ifndef __WINDOWS_FILENAME_H
#define __WINDOWS_FILENAME_H

#include "Common/String.h"

namespace NWindows {
namespace NFile {
namespace NName {

const TCHAR kDirDelimiter = '\\';
const TCHAR kAnyStringWildcard = '*';

void NormalizeDirPathPrefix(CSysString &aDirPath); // ensures that it ended with '\\'

namespace NPathType
{
  enum EEnum
  {
    kLocal,
    kUNC
  };
  EEnum GetPathType(const CSysString &aPath);
}

struct CParsedPath
{
  CSysString Prefix; // Disk or UNC with slash
  CSysStringVector PathParts;
  void ParsePath(const CSysString &aPath);
  CSysString MergePath() const;
};

void SplitNameToPureNameAndExtension(const CSysString &aFullName, CSysString &aPureName,
  CSysString &anExtensionDelimiter, CSysString &anExtension); 

}}}

#endif