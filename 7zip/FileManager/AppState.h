// AppState.h

#pragma once

#ifndef __APPSTATE_H
#define __APPSTATE_H

#include "Windows/Synchronization.h"

void inline AddUniqueStringToHead(UStringVector &list, 
    const UString &string)
{
  for(int i = 0; i < list.Size();)
    if (string.CollateNoCase(list[i]) == 0)
      list.Delete(i);
    else
      i++;
  list.Insert(0, string);
}

class CFastFolders
{
  NWindows::NSynchronization::CCriticalSection _criticalSection;
public:
  UStringVector Strings;
  void SetString(int index, const UString &string)
  {
    NWindows::NSynchronization::CCriticalSectionLock lock(_criticalSection);
    while(Strings.Size() <= index)
      Strings.Add(UString());
    Strings[index] = string;
  }
  UString GetString(int index)
  {
    NWindows::NSynchronization::CCriticalSectionLock lock(_criticalSection);
    if (index >= Strings.Size())
      return UString();
    return Strings[index];
  }
  void Save()
  {
    NWindows::NSynchronization::CCriticalSectionLock lock(_criticalSection);
    SaveFastFolders(Strings);
  }
  void Read()
  {
    NWindows::NSynchronization::CCriticalSectionLock lock(_criticalSection);
    ReadFastFolders(Strings);
  }
};

class CFolderHistrory
{
  NWindows::NSynchronization::CCriticalSection _criticalSection;
  UStringVector Strings;
public:
  
  void GetList(UStringVector &foldersHistory)
  {
    NWindows::NSynchronization::CCriticalSectionLock lock(_criticalSection);
    foldersHistory = Strings;
  }
  
  void Normalize()
  {
    NWindows::NSynchronization::CCriticalSectionLock lock(_criticalSection);
    const int kMaxSize = 100;
    if (Strings.Size() > kMaxSize)
      Strings.Delete(kMaxSize, Strings.Size() - kMaxSize + 1);
  }
  
  void AddString(const UString &string)
  {
    NWindows::NSynchronization::CCriticalSectionLock lock(_criticalSection);
    AddUniqueStringToHead(Strings, string);
    Normalize();
  }
  
  void RemoveAll()
  {
    NWindows::NSynchronization::CCriticalSectionLock lock(_criticalSection);
    Strings.Clear();
  }
  
  void Save()
  {
    NWindows::NSynchronization::CCriticalSectionLock lock(_criticalSection);
    SaveFolderHistory(Strings);
  }
  
  void Read()
  {
    NWindows::NSynchronization::CCriticalSectionLock lock(_criticalSection);
    ReadFolderHistory(Strings);
    Normalize();
  }
};

struct CAppState
{
  CFastFolders FastFolders;
  CFolderHistrory FolderHistrory;
  void Save()
  {
    FastFolders.Save();
    FolderHistrory.Save();
  }
  void Read()
  {
    FastFolders.Read();
    FolderHistrory.Read();
  }
};


#endif