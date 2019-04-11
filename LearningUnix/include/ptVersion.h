// ../release/include/ptVersion.h
//   This file was auto-generated on:  Wed Apr  4 17:25:19 PDT 2018
#ifndef _PT_VERSION_H_
#define _PT_VERSION_H_

#if defined(__arm__)
  #define PT_ARCH "(arm)"
#elif defined(__x86_64__)
  #define PT_ARCH "(x86_64)"
#else
  #define PT_ARCH "(unknown)"
#endif

#define PT_COMMIT_HASH "f228a2e7066f8ed1ecc1bec8ed2d7758f47d52d3"
// Major.Minor-Build#-GitHash
#define PT_VERSION "1.1-0-gf228a2e"
#define PT_RELEASE_VERSION "ST7.4.3_RH5.11_PT1.1.0.gf228a2e"

#define PT_LONG_VERSION ("1.1-0-gf228a2e,20180404_172519,prlsemgr," PT_ARCH)

// PT_BUILD_VERSION 1.1-0-gf228a2e - ST7.4.3 - RH5.11 - 20180404_172519 - prlsemgr
#endif
