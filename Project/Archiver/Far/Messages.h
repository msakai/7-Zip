// SevenZip/ Messages.h

#pragma once

#ifndef __SEVENZIP_MESSAGES_H
#define __SEVENZIP_MESSAGES_H

namespace NMessageID {

enum EEnum
{
  kOk,     
  kCancel,

  kWarning,
  kError,

  kArchiveType,

  kProperties,

  kYes,
  kNo,
  
  kName,
  kIsFolder,
  kSize,
  kPackedSize,
  kAttributes,
  kCreationTime,
  kLastAccessTime,
  kLastWriteTime,
  kSolid, 
  kComment, 
  kEncrypted, 
  kSplitBefore, 
  kSplitAfter, 
  kDictionarySize, 
  kCRC, 

  kGetPasswordTitle,
  kEnterPasswordForFile,

  kExtractTitle,
  kExtractTo,

  kExtractPathMode,
  kExtractPathFull,
  kExtractPathCurrent,
  kExtractPathNo,

  kExtractOwerwriteMode,
  kExtractOwerwriteAsk,
  kExtractOwerwritePrompt,
  kExtractOwerwriteSkip,

  kExtractFilesMode,
  kExtractFilesSelected,
  kExtractFilesAll,

  kExtractPassword,

  kExtractExtract,
  kExtractCancel,

  kExtractCanNotOpenOutputFile,

  kExtractUnsupportedMethod,
  kExtractCRCFailed,
  kExtractDataError,

  kOverwriteTitle,
  kOverwriteMessage1,
  kOverwriteMessageWouldYouLike,
  kOverwriteMessageWithtTisOne,

  kOverwriteBytes,
  kOverwriteModifiedOn,

  kOverwriteYes,
  kOverwriteYesToAll,
  kOverwriteNo,
  kOverwriteNoToAll,
  kOverwriteCancel,

  kUpdateNotSupportedForThisArchive,

  kDeleteTitle,
  kDeleteFile,
  kDeleteFiles,
  kDeleteNumberOfFiles,
  kDeleteDelete,
  kDeleteCancel,

  kUpdateTitle,
  kUpdateAddToArchive,

  kUpdateMethod,
  kUpdateMethodStore,
  kUpdateMethodNormal,
  kUpdateMethodMaximum,

  kUpdateMode,
  kUpdateModeAdd,
  kUpdateModeUpdate,
  kUpdateModeFreshen,
  kUpdateModeSynchronize,

  kUpdateAdd,
  kUpdateSelectArchiver,

  kUpdateSelectArchiverMenuTitle,

  // kArcReadFiles,
  
  kWaitTitle,
  
  kReading,
  kExtracting,
  kDeleting,
  kUpdating,
  
  // kReadingList,

  kMoveIsNotSupported,

  kOpenArchiveMenuString,
  kCreateArchiveMenuString,

  kConfigTitle,
  
  kConfigPluginEnabled
};

}

#endif