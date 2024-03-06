/** @file cfl_tokenreader.h @brief Class TokenReader */

/* FAU Discrete Event Systems Library (libfaudes)

Copyright (C) 2006  Bernd Opitz
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



#ifndef FAUDES_TOKENREADER_H
#define FAUDES_TOKENREADER_H


#include <vector>

#include "cfl_definitions.h"
#include "cfl_exception.h"
#include "cfl_token.h"

namespace faudes {

/**
 * A TokenReader reads sequential tokens from a file or string. It can get or peek
 * the next token and it will track line numbers for informative diagnosis output.
 *
 * The token stream is meant to be XML compliant, i.e., there are two dedicated
 * token types that mark the begin and the end of XML elements while all other token
 * types represent atomic data such as integers or strings that form the XML character data; 
 * see the documentation of the class Token for details.  
 *
 * The TokenReader maintains a current position in the stream and implements searching 
 * within nested elements and for sequential access of the tokens within each element;
 * e.g. ReadBegin(const std::string&) will search for the element with the specified name. 
 *
 * Reading from the Tokenreader by a particular method encodes the type of the
 * requested data, e.g. ReadInteger() to read an integer token. If the token at the
 * current position does not match the requiested type, an exception is thrown.
 * There are alose Get() and Peek() methods to retrieve and inspect the token at the current
 * position.
 *
 * For convenience, the TokenReader also implements reading all contents of an alement 
 * and larger chunks of data formtated as CDATA markup within an element; e.g. 
 * ReadVerbatim(const std::string&, std::string&) reads the contents of the specified element
 * en block as one string.
 * 
 * @ingroup TokenIO
 */

class FAUDES_API TokenReader {
public:

  /**
   * Mode of operation: read from file, stdin or string
   */
  enum Mode {File, Stdin, String};

  /**
   * TokenReader constructor
   *
   * @param mode
   *   select source: File, Stdin or String
   * @param rInString
   *   string to read from or filename, respectively.
   *
   * @exception Exception
   *   - faudes::Exception ios error opening file (id 1)
   *   - faudes::Exception invalid mode (Stdin not implemented) (id 1)
   */
  TokenReader(Mode mode, const std::string& rInString="");

  /**
   * Creates a TokenReader for reading a file.
   *
   * This is a convenience wrapper for TokenReader(Mode, const std::string&).
   *
   * @param rFilename
   *   file to read
   *
   * @exception Exception
   *   - faudes::Exception ios error opening file (id 1)
   */
  TokenReader(const std::string& rFilename);


  /**
   * Destruct
   */
  ~TokenReader(void);

  /**
   * Rewind stream
   *
   * Reset the internal state to its initial value, i.e., the
   * current position is the beginning of the stream. This is
   * not functional in console mode.
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   */
  void Rewind(void);

  /** 
   * Access C++ stream
   *
   * This method provides direc access to the underlying C++ stream.
   * After any such access, the TokenReader must be Rewind() to reset
   * its internal state.
   *
   * @return 
   *   pointer to C++ input stream 
   */
  std::istream* Streamp(void);

  /**
   * Access stream mode.
   *
   * Returns mode from construction, i.e. file, string or console.  
   * 
   * @return 
   *   Mode
   */
  Mode SourceMode(void) const { return mMode;};

  /**
   * Access the filename.
   *
   * Returns the name of the attached file, if any. For string mode and
   * console mode dummy values are returned.
   * 
   * @return 
   *   filename
   */
  std::string FileName(void) const;

  /**
   * Peek next token. 
   *
   * Copies the next token to the provided reference and returns
   * true on success. The token remains in an internal buffer.
   *
   * Technical note: we should have used a const-ref as return 
   * in orde to avoid the copy. However, this will require a tedious 
   * rewrite.
   *
   * @param token
   *   reference to token
   * @return
   *   true for a valid token, false for eof or other stream errors
   * 
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *
   */
  bool Peek(Token& token);

  /**
   * Get next token. 
   *
   * Same as Pekk() except that the token is removed from the buffer.
   *
   * @param token
   *   Reference to token
   * 
   * @exception Exception
   *   faudes exception ios (id 1)
   *
   * @return
   *   true for a valid token, false for eof or other stream errors
   */
  bool Get(Token& token);


  /**
   * Search for specified element
   * 
   * This function searches for the specified section on the current level. 
   * It skips any sections on the levels below, and it will wrap to the begin 
   * of the current section once. In the case of success, it returns true, else
   * false. In contrast to other token i/o methodes, this method will not throw
   * any execptions.
   *
   * In the case of success, the next token is the begin-tag of the specified element,
   * which can be read with ReadBegin().
   *
   * @param rLabel
   *   Token label to specify section
   *
   * @return
   *   True if sectiob exists
   *
   */
  bool ExistsBegin(const std::string& rLabel);

  /**
   * Open a section by specified label. This function searches
   * for the section on this level, it skips any sections on levels
   * below this level, and it will wrap once to the begin of the current 
   * section. In the case of success, the matching begin token is the 
   * last token read. After processing the section, a matching ReadEnd(label) 
   * must be called. If the specified element does not exist, an exception is thrown.
   *
   * @param rLabel
   *   Token label to specify section
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - Section begin label not found (id 51)
   *
   */
  void ReadBegin(const std::string& rLabel);

  /**
   * Open a section by specified label. 
   *
   * This wrapper ReadBegin(const std::string&) will return the actual
   * begin tag in its second argument, e.g., to inspect XML attributes.
   *
   * @param rLabel
   *   Token label to specify section
   * @param rToken
   *   Begin tag as found in token stream.
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - Section begin label not found (id 51)
   *
   */
  void ReadBegin(const std::string& rLabel, Token& rToken);

  /**
   * Close the current section by matching the previous ReadBegin(). 
   * Reads all tokens up to and including end of current section.
   *
   * @param rLabel
   *   Token label to specify section
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - Section end label not found (id 51)
   *
   */
  void ReadEnd(const std::string& rLabel);

  /**
   * Find specified begin label.
   *
   * This function searches for the section on this level and any descending level. 
   * It does not read the specified section tag, but stops just
   * one token before (and in this regard matches the behaviour of ExistsBegin()).
   *
   * Technical note:
   * Former versions of libFAUDES also read the actual begin token and
   * required a matching call of SeekEnd(). As of version 2.18a, this is not
   * supported anymore. The previous behaviour was rarely needed and can be
   * mimiqued by an ordinary ReadEnd() with a subsequent Recover(level).
   *
   * @param rLabel
   *   Label to specify section
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - Section begin not found (id 51)
   *
   */
  void SeekBegin(const std::string& rLabel);

  /**
   * Find specified begin label.
   *
   * This version SeekBegin(const std::string&) will return the actual
   * begin tag in its second argument.
   *
   * @param rLabel
   *   Token label to specify section
   * @param rToken
   *   Begin tag as found in token stream.
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - Section begin label not found (id 51)
   *
   */
  void SeekBegin(const std::string& rLabel, Token& rToken);

  /**
   * Peek a token and check whether it ends the specified section.
   * This function is meant for scanning a section with a while- construct.
   * \code
   * ReadBegin("MySec"); 
   * while(!Eos("MySec")) { 
   *   ... 
   * }; 
   * ReadEnd("MySec");
   * \endcode
   *
   * @param rLabel
   *   Token label to specify section
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - unexpected eof or section mismatch (id 51)
   *
   * @return
   *   True at end of section
   */
  bool Eos(const std::string& rLabel);

  /**
   * Read integer token
   *
   * Reads the next token and interprets it as an non-negative integer.
   *		  
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - Token mismatch  (id 50)
   *
   * @return
   *   value of index token
   */
  long int ReadInteger(void);

  /**
   * Read float token
   *		  
   * Reads the next token and interprets it as a float.
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - Token mismatch  (id 50)
   *
   * @return
   *   float value of token
   */
  double ReadFloat(void);

  /**
   * Read string token
   *		  
   * Reads the next token and interprets it as a string.
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - Token mismatch  (id 50)
   *
   * @return
   *   value of name token
   */
  std::string ReadString(void);

  /**
   * Read option token
   *		  
   * Reads the next token and interprets it as an option.
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - Token mismatch  (id 50)
   *
   * @return
   *   value of name token
   */
  std::string ReadOption(void);

  /**
   * Read binary token. 
   *
   * Reads the next token and interprets it as an base64
   * encoded binary array.
   *		  
   * @param rData
   *   Buffer to read data 
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - Token mismatch  (id 50)
   *
   */
   void ReadBinary(std::string& rData);


  /**
   * Read plain text
   *		  
   * Interpret the specified section as plain charater data section, read
   * the character data and interpret relevant entities. Leading and trailing
   * whitespaces are ignored, other formating is maintained. 
   * 
   * This method facilitates the input of paragraphs of plain ASCII text with 
   * no other markup as the relevant entities (i.e. no HTML or RTF).
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - Stream mismatch (id 50)
   *
   * @param rLabel
   *   Buffer to read Text
   * @param rText
   *   Name of section to read text from
   */
   void ReadText(const std::string& rLabel, std::string& rText);


  /**
   * Read verbatim text
   *		  
   * Interpret the section as plain charater data section, read
   * the character data from either one faudes string token or from consecutive CDATA markups. 
   * Leading and trailing whitespaces are ignored, other formating is maintained.
   *
   * This method facilitates the input of paragraphs of plain ASCII text with 
   * excessive use of special characters, e.g., program fragments.
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - Stream mismatch (id 50)
   *
   * @param rLabel
   *   Buffer to read Text
   * @param rText
   *   Name of section to read text from
   */
   void ReadVerbatim(const std::string& rLabel, std::string& rText);


  /**
   * Read plain text
   *		  
   * Read all text until and excluding the next markup tag. This method 
   * does no interpretation/substitution at all. It is meant to implemet carbon 
   * copy of text sections.
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - Stream mismatch (id 50)
   *
   * @param rData
   *   Buffer to read characterdata
   */
   void ReadCharacterData(std::string& rData);

 
  /**
   * Read XML section
   *		  
   * Reads the current element, including all character data and markup, 
   * until and excluding the matching end tag. This method does no interpretation whatsoever.
   * The result is a string that represents the respective section in plain XML format
   * and can be used for expernal post-processing.
   *
   * @exception Exception
   *   - faudes::Exception ios error reading file (id 1)
   *   - Stream mismatch (id 50)
   *
   * @param rSectionString
   *   Buffer to read section
   */
   void ReadSection(std::string& rSectionString);


  /** Operator for get */
  bool operator >> (Token& token) {
    return Get(token);
  }

  /**
   * Return number of lines read
   * 
   * @return
   *   Number of lines read
   */ 
  int Line(void) const;

  /**
   * Return current level of section nesting.
   * 
   * @return
   *   Number of lines read
   */ 
  int Level(void) const { return mLevel;};

  /**
   * Recover by skipping tokens until returning to the specified level of section nesting
   *
   * @return
   *   True on success
   */ 
  bool Recover(int level);

  /**
   * Reset to the begining of the specified level of section nesting.
   * 
   * @param level
   *    target level, defaults to current level
   * @return
   *   True on success
   */ 
  bool Reset(int level=-1);

  /**
   * Return "filename:line"
   */
  std::string FileLine(void) const;

 private:

  /** input mode */
  Mode mMode;

  /** istream object pointer */
  std::istream* mpStream;

  /** actual stream object, file input  */
  std::ifstream mFStream;

  /** actual stream object on heap, string input  */
  std::istringstream* mpSStream;

  /** Filename */
  std::string mFileName;

  /** Line counter */
  int mLineCount;

  /** file position */
  long int mFilePos;

  /** flag to ignore faudes comments marked by '%' */
  bool mFaudesComments;

  /** Level (of nested sections) */
  int mLevel;

  /** State on entry of respective level */
  struct LState {
    std::string mLabel;
    long int mStartPosition;
    long int mStartLine;
    Token mStartPeek;
    bool mFaudesComments;
  };
  std::vector<LState> mLevelState;

  /** peek buffer */
  Token mPeekToken;
};

} // namespace faudes

#endif 
