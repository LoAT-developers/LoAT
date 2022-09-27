/*  This file is part of LoAT.
 *  Copyright (c) 2015-2016 Matthias Naaf, RWTH Aachen University, Germany
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses>.
 */

#pragma once

#include <string>
#include <cstdarg>
#include <stdarg.h>
#include <stdio.h>

/**
 * The base class for all exceptions in this project,
 * extending std::exception with an error message
 */
class CustomException : public std::exception {
protected:
    std::string errorMessage;
public:
    CustomException() : CustomException("") {}
    CustomException(std::string message) : errorMessage(message) {}
    const char *what() const noexcept { return errorMessage.c_str(); }
};


/**
 * Macro to define custom exceptions.
 * If no error message is given when thrown, the class name is used.
 * This allows at least some specific information when catching the CustomException base class only.
 */
#define EXCEPTION(exceptionName, baseException) \
class exceptionName : public baseException { \
public: \
    exceptionName(std::string message) : baseException(message) {} \
    exceptionName() : exceptionName(#exceptionName) {} \
}

EXCEPTION(QepcadError, CustomException);
EXCEPTION(ParseError, CustomException);
EXCEPTION(FileError, CustomException);
EXCEPTION(RedlogError, CustomException);
EXCEPTION(GinacConversionError, CustomException);
EXCEPTION(GinacLargeConstantError, CustomException);
EXCEPTION(UnsupportedOperationError, CustomException);
