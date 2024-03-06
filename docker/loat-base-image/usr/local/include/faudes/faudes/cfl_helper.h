/** @file cfl_helper.h   Helper functions */

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2006  Bernd Opitz
   Copyright (C) 2008-2010 Thomas Moor
   Exclusive copyright is granted to Klaus Schmidt

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA */


#ifndef FAUDES_HELPER_H
#define FAUDES_HELPER_H

#include "cfl_definitions.h"
#include "cfl_platform.h"
#include "cfl_exception.h"

namespace faudes {

// forward
class Type;

/**
 * integer to string
 * 
 * @param number
 *   integer
 *
 * @return
 *   string
 */
extern FAUDES_API std::string ToStringInteger(Int number);


/**
 * integer to string base 16
 * 
 * @param number
 *   integer
 *
 * @return
 *   string
 */
extern FAUDES_API std::string ToStringInteger16(Int number);

/**
 * float to string 
 * 
 * @param number
 *   double
 *
 * @return
 *   string
 */
extern FAUDES_API std::string ToStringFloat(Float number);


/**
 * Fill string with spaces up to a given length if length of the string
 * is smaller than given length parameter.
 *
 * @param rString
 *   string
 * @param len
 *   Minimum number of charakters in string
 *
 * @return
 *   Expanded string
 */
extern FAUDES_API std::string ExpandString(const std::string& rString, unsigned int len);

/**
 * Limit length of string, return head and tail of string
 *
 * @param rString
 *   string
 * @param len
 *   Maximum number of charakters in string (approx)
 *
 * @return
 *   Collapsed string
 */
extern FAUDES_API std::string CollapsString(const std::string& rString, unsigned int len= FD_MAXCONTAINERNAME);


/**
 * Convert a string to Idx
 *
 * @param rString
 *   string to convert
 *
 * @return 
 *   Idx
 *
 * @exception
 *   Idx overflow (id 600)
 */
extern FAUDES_API Idx ToIdx(const std::string& rString);

/**
 * Substitute in string
 *
 * @param rString
 *   Source string to substitute
 * @param rFrom
 *   String to match
 * @param rTo
 *   Replacement to fill in 
 * @return 
 *   Result string
 *
 */
extern FAUDES_API std::string StringSubstitute(const std::string& rString,const std::string& rFrom,const std::string& rTo);
   


/**
 * Return FAUDES_VERSION as std::string
 *
 * @return 
 *   std::string with FAUDES_VERSION
 */
extern FAUDES_API std::string VersionString();

/**
 * Return FAUDES_PLUGINS as std::string
 *
 * @return 
 *   std::string with FAUDES_VERSION
 */
extern FAUDES_API std::string PluginsString();

/**
 * Return contributors as std::string
 *
 * @return 
 *   std::string 
 */
extern FAUDES_API std::string ContributorsString();


/**
 * Convenience function: process dot file
 * to graphics output.  If no output format is given,
 * try to guess from filename extension. 
 *
 * @param rDotFile
 *   name of dot file
 * @param rOutFile
 *   name of graphics file 
 * @param rOutFormat
 *   graphics format eg "png", "jpg"
 * @param rDotExec
 *   path/name of executable
 *
 * @exception Exception
 *   - error in systemcall (id 3)
 *   - unkown format (id 3)
 *
 */
extern FAUDES_API void ProcessDot(const std::string& rDotFile, const std::string& rOutFile, 
  const std::string& rOutFormat = "", const std::string& rDotExec = "dot");


/**
 * Create a temp file, length 0
 *
 * @return
 *   Name of temp file
 */
extern FAUDES_API std::string CreateTempFile(void);


/**
 * Delete a file
 *
 * @param rFileName
 *   Name of file to delete
 */
extern FAUDES_API bool RemoveFile(const std::string& rFileName);

/**
 * Std dir-separator.
 * @return
 *   Separator as one-char string
 */
extern FAUDES_API const std::string& PathSeparator(void);

/**
 * Extract directory from full path.
 *
 * @param rFullPath
 *   Full name of file eg "/home/friend/data/generator.gen"
 * @return
 *   Directory eg "/home/friend/data"
 */
extern FAUDES_API std::string ExtractDirectory(const std::string& rFullPath);

/**
 * Extract file name from full path.
 *
 * @param rFullName
 *   Full path of file eg "/home/friend/data/generator.gen"
 * @return
 *   Filename "generator.gen"
 */
extern FAUDES_API std::string ExtractFilename(const std::string& rFullName);

/**
 * Extract file name from full path. This version also
 * removes the last suffix.
 *
 * @param rFullName
 *   Full path of file eg "/home/friend/data/generator.gen"
 * @return
 *   Filename "generator"
 */
extern FAUDES_API std::string ExtractBasename(const std::string& rFullName);

/**
 * Extract file name from full path. This version also
 * remove the last suffix.
 *
 * @param rFullName
 *   Full path of file eg "/home/friend/data/generator.gen"
 * @return
 *   Extension "gen"
 */
extern FAUDES_API std::string ExtractExtension(const std::string& rFullName);

/**
 * Construct full path from directory and filename.
 *
 * @param rDirectory
 *   Directory eg "/home/friend/data"
 * @param rFileName
 *   File eg "generator.gen"
 * @return
 *   Path eg "/home/friend/data/generator.gen"
 */
extern FAUDES_API std::string PrependDirectory(const std::string& rDirectory, const std::string& rFileName);

/**
 * Test existence of file
 *
 * @param rFilename
 *   Name of file to test
 * @return
 *   True <> can open file for reading
 */
extern FAUDES_API bool FileExists(const std::string& rFilename);

/**
 * Delete  file
 *
 * @param rFilename
 *   Name of file to delete
 * @return
 *   True <> could delete the file
 */
extern FAUDES_API bool FileDelete(const std::string& rFilename);

/**
 * Copy  file
 *
 * @param rFromFile
 *   Name of source file 
 * @param rToFile
 *   Name of dest file
 * @return
 *   True <> operation ok
 */
extern FAUDES_API bool FileCopy(const std::string& rFromFile, const std::string& rToFile);

/**
 * Test existence of directory
 *
 * @param rDirectory
 *   Name of file to test
 * @return
 *   True <> can open directory for reading
 */
extern FAUDES_API bool DirectoryExists(const std::string& rDirectory);


/**
 * Read the contents of the specified directors.
 *
 * @param rDirectory
 *   Directory eg "/home/friend/data"
 * @return
 *   List of files, e.g. "gen1.gen gen2.gen data subdir"
 */
extern FAUDES_API std::set< std::string > ReadDirectory(const std::string& rDirectory);


/**
 * Console Out
 *
 * All console out messages (errors, progress report etc) are
 * meant to use the global ConsoleOut instance gConsoleOut, presumably
 * using the convenience macro FAUDES_WRITE_CONSOLE(). The default ConsoleOut::G()
 * provides optional redirection to a named file by G()->ConsoleOut.ToFile("filename").
 * libFAUDES itself does not set/respect verbosity levels for its diagnostic
 * output, this feature is implemented to support console applications. 
 * 
 * The main motivation of the entire construct is to support gui applications that may
 * grab all console output by 1) deriving a specialised class from ConsoleOut and 2) 
 * redirection by ConsoleOut::G()->Redirect(derived_class_instance).
 */
class FAUDES_API ConsoleOut {
public:
  /** Acess static instance */
  static ConsoleOut* G(void);
  /** Write a std::string message (optional progress report and verbosity) */
  virtual void Write(const std::string& message,long int cntnow=0, long int cntdone=0, int verb=0);
  /** Redirect to file */
  void ToFile(const std::string& filename);
  /** Query filename */
  const std::string& Filename(void) { return mFilename;}; 
  /** Redirect */
  void Redirect(ConsoleOut* out);
  /** Mute */
  void Mute(bool on) {mMute=on;};
  bool Mute() { return mMute;};
  /** Verbosity */
  void Verb(int verb) {mVerb=verb;};
  int Verb() { return mVerb;};  
protected:
  /** Constructor */
  ConsoleOut(void);
  /** Destructor */
  virtual ~ConsoleOut(void);
  /** Writing hook. Re-implement this function in order to grab all output */
  virtual void DoWrite(const std::string& message,long int cntnow=0, long int cntdone=0, int verb=0);
private:
  /** Private output stream */
  std::ofstream* pStream;
  /** Private record file name */
  std::string mFilename;
  /** Mute flag */
  bool mMute;
  int mVerb;
  /** Redirect */
  ConsoleOut* pInstance;
  /** Private static instance */
  static ConsoleOut* smpInstance;
};

 
/**
 * Debugging counter. Counts items as specified by the type string and reports
 * sums on exit. You must define the macro FAUDES_DEBUG_CODE to get a report.
 *
 * Technical note: we use the somewhat winded static member construct to
 * guarantee that our member variables have been constructed befor actual
 * counting occurs. This is neccessary since some faudes types might have a
 * static instance and, hence, may be consructed rather early. 
 *
 */
class FAUDES_API ObjectCount {
 public:
  static void Inc(const std::string& rTypeName);
  static void Dec(const std::string& rTypeName);
  static void Init(void);
  static std::map< std::string, long int >* mspMax;
  static std::map< std::string, long int >* mspCount;
 private:
  static bool msDone;
  ObjectCount(void);
};


/**
 * Test Protocol. 
 * Sets the filename for the test protocol by 
 * - removing any path specififucation,
 * - replacing "." by "_",
 * - appending ".prot", and finaly
 * - prepending "tmp_".
 * The function returns the filename except for the
 * "tmp_" prefix. The latter is considered the nominal
 * protocol output (aka reference protocol).
 * 
 * Note: only the first invocation of this functions actually sets
 * the protocol file. Further invocations are ignored, but can be
 * used to query the reference protocol.
 * 
 * @param rSource
 *   Source file to protocol
 * @return
 *   Filename with nominal protocol.
 *
 */
extern FAUDES_API std::string TestProtocol(const std::string& rSource);  


/**
 * Test Protocol. 
 * This function dumps the specified data to the protocol file for
 * the purpose of later comparison with a refernce value.
 * If the protocol file has not been set up, this
 * function does nothing; see also TestProtocol(const std::string&.  
 * 
 * @param rMessage
 *   Informal identifyer of the test
 * @param rData
 *   Formal result of the test case
 * @param core
 *   Whether to record full token io or statistics only.
 *
 */
extern FAUDES_API void TestProtocol(const std::string& rMessage, const Type& rData, bool core=false); 

/**
 * Test Protocol. 
 * Specialized version for boolean test data. 
 * See also TestProtocol(const std::string&, const Type&, bool);
 * 
 * @param rMessage
 *   Informal identifyer of the test
 * @param data
 *   Test data
 *
 */
extern FAUDES_API void TestProtocol(const std::string& rMessage, bool data); 

/**
 * Test Protocol. 
 * Specialized version for integer test data. 
 * See also TestProtocol(const std::string&, const Type&, bool);
 * 
 * @param rMessage
 *   Informal identifyer of the test
 * @param data
 *   Test data
 *
 */
extern FAUDES_API void TestProtocol(const std::string& rMessage, long int data); 


/**
 * Test Protocol. 
 * Specialized version for string data. 
 * See also TestProtocol(const std::string&, const Type&, bool);
 * 
 * @param rMessage
 *   Informal identifyer of the test
 * @param data
 *   Test data
 *
 */
extern FAUDES_API void TestProtocol(const std::string& rMessage, const std::string& data); 


/**
 * Test Protocol. 
 * Perform a comparison of the recent protocol file and the
 * corresponding reference. Returns true if the test passes.
 *
 * Note: this function closes the current protocol.
 *
 * @return 
 *    True <=> test past
 */
extern FAUDES_API bool TestProtocol(void);


/** Test protocol record macro ("mangle" filename for platform independance)*/
#define FAUDES_TEST_DUMP(mes,dat) { \
  TestProtocol(__FILE__); \
  std::string fname= __FILE__; \
  std::replace(fname.begin(),fname.end(),'\\','/'); \
  fname=ExtractFilename(fname); \
  std::stringstream sstr; \
  sstr << mes << " [at " << fname << ":" << __LINE__ << "]" ; \
  TestProtocol(sstr.str(),dat); }

/** Test protocol diff macro */
#define FAUDES_TEST_DIFF() { if(!TestProtocol()) { \
    FAUDES_WRITE_CONSOLE("FAUDES_TEST_DIFF: sensed test case error in " << __FILE__); exit(1);} }


/** Algorithm loop callback 
 *
 * Set a callback function for libFAUDES algorithms. Applications
 * are meant to use this interface to terminate an algorithm on user
 * request. libFAUDES algorithms are meant to throw an execption when
 * the callback function returns true. See also void LoopCallback(void).
 *
 * @param pBreakFnct
 *
 */
extern FAUDES_API  void LoopCallback(bool (*pBreakFnct)(void));

 /** Algorithm loop callback
  *
  * Calls the loop callback function and throws an exception if it
  * returns true. 
  *
  * @exception
  *   Break on appliation request (id 110)
  *
  */
extern FAUDES_API void LoopCallback(void);



} // namespace faudes


#endif

