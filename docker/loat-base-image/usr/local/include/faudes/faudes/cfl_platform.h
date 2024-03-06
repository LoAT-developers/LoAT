/** @file cfl_platform.h  Platform dependant wrappers */

/* FAU Discrete Event Systems Library (libfaudes)

   Copyright (C) 2013  Thomas Moor

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNES FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA 
*/


#ifndef FAUDES_PLATFORM_H
#define FAUDES_PLATFORM_H

/** Sense POSIX versus Windows */
#ifndef FAUDES_POSIX
#ifndef FAUDES_WINDOWS
#ifndef FAUDES_GENERIC

#if defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__)
#define FAUDES_WINDOWS
#endif
#if defined (__unix__) || (__linus__) || (__linux__) || (defined (__APPLE__) && defined (__MACH__))
#define FAUDES_POSIX
#endif

#ifndef FAUDES_POSIX
#ifndef FAUDES_WINDOWS
#define FAUDES_GENERIC
#endif
#endif

#endif
#endif
#endif


/** Interface export/import symbols: windows */
#ifdef FAUDES_WINDOWS
#ifdef FAUDES_BUILD_DSO
  #ifdef __GNUC__
    #define FAUDES_API __attribute__ ((dllexport))
  #else
    #define FAUDES_API __declspec(dllexport) 
  #endif
#endif
#ifdef FAUDES_BUILD_APP
  #ifdef __GNUC__
    #define FAUDES_API __attribute__ ((dllimport))
  #else
    #define FAUDES_API __declspec(dllimport) 
  #endif
#endif
#endif

/** Interface export/import symbols: posix/gcc */
#ifdef FAUDES_POSIX
#ifdef FAUDES_BUILD_DSO
  #if __GNUC__ >= 4
    #define FAUDES_API __attribute__ ((visibility ("default")))
  #endif
#endif
#ifdef FAUDES_BUILD_APP
  #define FAUDES_API
#endif
#endif

/** Interface export/import symbols: default */
#ifndef FAUDES_API
   #define FAUDES_API
#endif
 


// Std headers 
#include <cstdlib>
#include <cstring>
#include <inttypes.h>
#include <limits>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <iterator>


// Extra POSIX headers 
#ifdef FAUDES_POSIX

#include <stdlib.h>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#ifdef FAUDES_SYSTIME
#include <time.h>
#include <sys/time.h>
#endif

#ifdef FAUDES_NETWORK
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#endif

#ifdef FAUDES_THREADS
#include <pthread.h>
#endif

#endif


// Extra Windows/MinGW headers
#ifdef FAUDES_WINDOWS

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#define FAUDES_LEAN_AND_MEAN
#endif
#include <windows.h>
#ifdef FAUDES_LEAN_AND_MEAN
#undef FAUDES_LEAN_AND_MEAN
#undef WIN32_LEAN_AND_MEAN
#endif

#ifdef FAUDES_SYSTIME
#include <time.h>
//#include <sys/time.h> //mingw only
#include <mmsystem.h>
#endif

#ifdef FAUDES_NETWORK
#include <winsock2.h>
#include <fcntl.h>
#endif

#ifdef FAUDES_THREADS
#include <process.h>
#endif

#include <io.h>

// dislike min/max msvc macros
#ifdef max
#undef max
#endif
#ifdef min
#undef min
#endif

#endif



// Path-seperators (see cfl_helper.cpp)
//  * the first separator is the one used to prepend directories etc
//  * all other separators are used to extract basenames
//  * using gcc/make also on Windows, we occasionaly get Unix style files names
//    in the build process ... thus we allways define the Unix "/" as a separator 
//  * summary: we use "/" for POSIX and "\\:/" for Windows.
extern FAUDES_API const std::string faudes_pathseps_str; 
inline FAUDES_API const std::string& faudes_pathseps(void) { 
  return faudes_pathseps_str; 
}

// Path-seperator (first char of above, see cfl_helper.cpp)
extern FAUDES_API const std::string faudes_pathsep_str; 
inline FAUDES_API const std::string& faudes_pathsep(void) {
  return faudes_pathsep_str; 
}


// Uniform exit-signalhandler for POSIX / Windows/MinGW (see e.g. simfaudes.cpp)
extern FAUDES_API void faudes_termsignal(void (*sighandler)(int));

// Uniform signal names for POSIX / Windows/MinGW (see e.g. simfaudes.cpp)
extern FAUDES_API const char* faudes_strsignal(int sig);

// Uniform sleep for POSIX and Windows/MinGW (see e.g. iodevice plug-in)
#ifdef FAUDES_POSIX
inline FAUDES_API void faudes_sleep(long int sec) {sleep(sec);}
inline FAUDES_API void faudes_usleep(long int usec) {usleep(usec);}
#endif
#ifdef FAUDES_WINDOWS
inline FAUDES_API void faudes_sleep(long int sec) {Sleep((sec) * 1000);}
inline FAUDES_API void faudes_usleep(long int usec) {Sleep((usec) / 1000);}
#endif
#ifdef FAUDES_GENERIC
extern FAUDES_API void faudes_invalid(const std::string& msg);
inline FAUDES_API void faudes_sleep(long int sec) { faudes_invalid("faudes_sleep()"); }
inline FAUDES_API void faudes_usleep(long int usec) { faudes_invalid("faudes_usleep()"); }
#endif


#ifdef FAUDES_SYSTIME

// Uniform system time using POSIX pthreads semantics
#ifdef FAUDES_POSIX
typedef timespec faudes_systime_t;
typedef long int faudes_mstime_t;
#endif
#ifdef FAUDES_WINDOWS
typedef struct {
  long int tv_sec;
  long int tv_nsec;
} faudes_systime_t;
typedef long int faudes_mstime_t;
#endif
#ifdef FAUDES_GENERIC
#error option systime not available on generic platform
#endif


// Uniform system time definitions
extern FAUDES_API void faudes_gettimeofday(faudes_systime_t* now);
extern FAUDES_API void faudes_diffsystime(const faudes_systime_t& end, const faudes_systime_t& begin, faudes_systime_t* res);
extern FAUDES_API void faudes_diffsystime(const faudes_systime_t& end, const faudes_systime_t& begin, faudes_mstime_t* res);
extern FAUDES_API void faudes_sumsystime(const faudes_systime_t& begin, const faudes_systime_t& duration, faudes_systime_t* res);
extern FAUDES_API void faudes_msdelay(faudes_mstime_t msecs,faudes_systime_t* end);
extern FAUDES_API void faudes_usdelay(faudes_mstime_t usecs,faudes_systime_t* end);

// global performance times
extern FAUDES_API faudes_systime_t gPerfTimer1;

#endif



#ifdef FAUDES_NETWORK

// Uniform POSIX sockets (see iop_modbus.cpp and iop_simplenet.cpp)
#ifdef FAUDES_POSIX
inline FAUDES_API int faudes_closesocket(int fd) {return close(fd);}
inline FAUDES_API int faudes_setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen) {
  return setsockopt(fd,level,optname,optval,optlen);}
inline FAUDES_API int faudes_getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlen) {
  return getsockopt(fd,level,optname,optval,optlen);}
extern FAUDES_API int faudes_setsocket_nonblocking(int fd, bool noblo);
extern FAUDES_API int faudes_getsocket_error(int fd);
#endif
#ifdef FAUDES_WINDOWS
typedef int socklen_t;
inline FAUDES_API int faudes_closesocket(int fd) {return closesocket(fd);}
inline FAUDES_API int faudes_setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen) {
  return setsockopt(fd,level,optname,(char*) optval,optlen);}
inline FAUDES_API int faudes_getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlen) {
  return getsockopt(fd,level,optname,(char*) optval,optlen);}
extern FAUDES_API int faudes_setsocket_nonblocking(int fd, bool noblo);
extern FAUDES_API int faudes_getsocket_error(int fd);
#endif
#ifdef FAUDES_GENERIC
#error option network not available on generic platform
#endif

// POSIX sockets to have BSD style REUSEPORT option (see iop_modbus.cpp and iop_simplenet.cpp)
#ifndef SO_REUSEPORT
#define SO_REUSEPORT SO_REUSEADDR
#endif

#endif


#ifdef FAUDES_THREADS

/* 
The remaining section of this file provides elementary support for threads, 
using a minimalistic subset of the POSIX threads interface. It is tailored for 
the use of edge-detection and networking as required by the iodevice plug-in. 
In general, libFAUDES is not threadsafe due to global variables, e.g. 
symoltables. This may change in a future revision.
*/


// Common return codes 
#define FAUDES_THREAD_SUCCESS  0 
#define FAUDES_THREAD_ERROR    1 
#define FAUDES_THREAD_TIMEOUT  2 



#ifdef FAUDES_POSIX
// Thread data type (use plain POSIX thread)
typedef pthread_t faudes_thread_t;
// Thread functions (all inline, plain pthread wrapper)
inline FAUDES_API int faudes_thread_create(faudes_thread_t *thr, void *(*fnct)(void *), void *arg){
  // prepare attribute for plain joinable thread
  pthread_attr_t attr;	
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  // start execute
  int ret  = pthread_create(thr, &attr, fnct, arg);
  // done
  pthread_attr_destroy(&attr);
  return ret == 0 ? FAUDES_THREAD_SUCCESS : FAUDES_THREAD_ERROR;
}
inline FAUDES_API faudes_thread_t faudes_thread_current(void) {
  return pthread_self();
}
inline FAUDES_API int faudes_thread_detach(faudes_thread_t thr) {
  return pthread_detach(thr)==0 ? FAUDES_THREAD_SUCCESS : FAUDES_THREAD_ERROR;
}
inline FAUDES_API int faudes_thread_equal(faudes_thread_t thr0, faudes_thread_t thr1) {
  return pthread_equal(thr0, thr1);
}
inline FAUDES_API void faudes_thread_exit(void* res) {
  pthread_exit(res);
}
inline int faudes_thread_join(faudes_thread_t thr, void **res) {
  return pthread_join(thr, res) == 0 ? FAUDES_THREAD_ERROR : FAUDES_THREAD_SUCCESS;
}
#endif


#ifdef FAUDES_WINDOWS
// Thread data type 
// We wrap the client function to provide pointer-typed  
// return values (as opposed to Windows int-typed return values)
typedef struct {
  HANDLE mHandle;          // Windows thread handle             
  void *(*mFnct)(void *);  // client function
  void *mArg;              // argument
  void *mRes;              // result
} faudes_thread_record_t;
typedef faudes_thread_record_t* faudes_thread_t;
// Thread functions (Windows to mimic plain pthreads)
extern FAUDES_API int faudes_thread_create(faudes_thread_t *thr, void *(*fnct)(void *), void *arg);
extern FAUDES_API faudes_thread_t faudes_thread_current(void);
extern FAUDES_API int faudes_thread_detach(faudes_thread_t thr);
extern FAUDES_API int faudes_thread_equal(faudes_thread_t thr0, faudes_thread_t thr1);
extern FAUDES_API void faudes_thread_exit(void* res);
extern FAUDES_API int faudes_thread_join(faudes_thread_t thr, void **res);
#endif


#ifdef FAUDES_POSIX
// Mutex data type (use plain POSIX mutex)
typedef pthread_mutex_t faudes_mutex_t;
// Mutex functions (all inline, plain pthread wrapper)
inline FAUDES_API int faudes_mutex_init(faudes_mutex_t* mtx){
  return pthread_mutex_init(mtx, NULL)==0 ? FAUDES_THREAD_SUCCESS : FAUDES_THREAD_ERROR;
}
inline FAUDES_API void faudes_mutex_destroy(faudes_mutex_t* mtx){
  pthread_mutex_destroy(mtx);
}
inline FAUDES_API int faudes_mutex_lock(faudes_mutex_t *mtx) {
  return pthread_mutex_lock(mtx) == 0 ? FAUDES_THREAD_SUCCESS : FAUDES_THREAD_ERROR;
}
inline FAUDES_API int faudes_mutex_trylock(faudes_mutex_t *mtx){
  return (pthread_mutex_trylock(mtx) == 0) ? FAUDES_THREAD_SUCCESS : FAUDES_THREAD_ERROR;
}
inline FAUDES_API int faudes_mutex_unlock(faudes_mutex_t *mtx){
  return pthread_mutex_unlock(mtx) == 0 ? FAUDES_THREAD_SUCCESS : FAUDES_THREAD_ERROR;
}
#endif


#ifdef FAUDES_WINDOWS
// Mutex data type (use Windows "critical section")
typedef CRITICAL_SECTION faudes_mutex_t;
// Mutex functions (all inline, wraps to Windows "critical section")
inline FAUDES_API int faudes_mutex_init(faudes_mutex_t *mtx){
  InitializeCriticalSection(mtx);
  return FAUDES_THREAD_SUCCESS;
}
inline FAUDES_API void faudes_mutex_destroy(faudes_mutex_t *mtx){
  DeleteCriticalSection(mtx);
}
inline FAUDES_API int faudes_mutex_lock(faudes_mutex_t *mtx) {
  EnterCriticalSection(mtx);
  return FAUDES_THREAD_SUCCESS;
}
inline FAUDES_API int faudes_mutex_trylock(faudes_mutex_t *mtx){
  return TryEnterCriticalSection(mtx) ? FAUDES_THREAD_SUCCESS : FAUDES_THREAD_ERROR;
}
inline FAUDES_API int faudes_mutex_unlock(faudes_mutex_t *mtx){
  LeaveCriticalSection(mtx);
  return FAUDES_THREAD_SUCCESS;
}
#endif


#ifdef FAUDES_POSIX
// Condition variable data type (use plain POSIX condition variables)
typedef pthread_cond_t faudes_cond_t;
// Condition functions (all inline, plain pthread wrapper)
inline FAUDES_API int faudes_cond_init(faudes_cond_t* cond) {
  return pthread_cond_init(cond, NULL) == 0 ? FAUDES_THREAD_SUCCESS : FAUDES_THREAD_ERROR;
}
inline FAUDES_API void faudes_cond_destroy(faudes_cond_t* cond) {
  pthread_cond_destroy(cond);
}
inline FAUDES_API int faudes_cond_signal(faudes_cond_t *cond){
  return pthread_cond_signal(cond) == 0 ? FAUDES_THREAD_SUCCESS : FAUDES_THREAD_ERROR;
}
inline FAUDES_API int faudes_cond_broadcast(faudes_cond_t *cond) {
  return pthread_cond_signal(cond) == 0 ? FAUDES_THREAD_SUCCESS : FAUDES_THREAD_ERROR;
}
inline FAUDES_API int faudes_cond_wait(faudes_cond_t *cond, faudes_mutex_t *mtx) {
  return pthread_cond_wait(cond, mtx) == 0 ? FAUDES_THREAD_SUCCESS : FAUDES_THREAD_ERROR;
}
inline FAUDES_API int faudes_cond_timedwait(faudes_cond_t *cond, faudes_mutex_t *mtx, const faudes_systime_t *abstime) {
  int ret = pthread_cond_timedwait(cond, mtx, abstime);
  if(ret == ETIMEDOUT) return FAUDES_THREAD_TIMEOUT;
  return ret == 0 ? FAUDES_THREAD_SUCCESS : FAUDES_THREAD_ERROR;
}
// Extension: timed wait with duration as opposed to absolute time
inline FAUDES_API int faudes_cond_reltimedwait(faudes_cond_t *cond, faudes_mutex_t *mtx, faudes_mstime_t duration) {
  faudes_systime_t abstime;
  faudes_msdelay(duration,&abstime);
  return faudes_cond_timedwait(cond,mtx,&abstime);
}
#endif


#ifdef FAUDES_WINDOWS
// Condition variable data type 
// The approach is taken from "Strategies for Implementing POSIX Condition Variables 
// on Win32" by Douglas C. Schmidt and Irfan Pyarali, Department of Computer 
// Science, Washington University. 
typedef struct {
  HANDLE mEvents[2];                   // signal and broadcast event handles
  unsigned int mWaitersCount;          // count the number of waiters
  CRITICAL_SECTION mWaitersCountMutex; // mutex access to waiterscount
} faudes_cond_t;
// Condition functions (Windows to mimic plain pthread conditions)
extern FAUDES_API int faudes_cond_init(faudes_cond_t* cond);
extern FAUDES_API void faudes_cond_destroy(faudes_cond_t* cond);
extern FAUDES_API int faudes_cond_signal(faudes_cond_t *cond);
extern FAUDES_API int faudes_cond_broadcast(faudes_cond_t *cond);
extern FAUDES_API int faudes_cond_wait(faudes_cond_t *cond, faudes_mutex_t *mtx);
extern FAUDES_API int faudes_cond_timedwait(faudes_cond_t *cond, faudes_mutex_t *mtx, const faudes_systime_t *abstime);
extern FAUDES_API int faudes_cond_reltimedwait(faudes_cond_t *cond, faudes_mutex_t *mtx, faudes_mstime_t duration);
#endif



#ifdef FAUDES_GENERIC
#error option threads not available on generic platform
#endif


#endif // threads

#endif // header

