/*
 * @(#)jni_md.h	1.19 05/11/17
 *
 * Copyright 2006 Sun Microsystems, Inc. All rights reserved.
 * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

#ifndef _JAVASOFT_JNI_MD_H_
#define _JAVASOFT_JNI_MD_H_

#define JNIEXPORT __attribute__((visibility("default")))
#define JNIIMPORT
#define JNICALL

#if defined(__LP64__) && __LP64__ /* for -Wundef */
typedef int jint;
#else
typedef long jint;
#endif
typedef long long jlong;
typedef signed char jbyte;

#if defined(__linux__)
#include <unistd.h>
#include <sys/syscall.h>
#include <termios.h>

static pid_t gettid() {
    return syscall(SYS_gettid);
}
#endif

#endif /* !_JAVASOFT_JNI_MD_H_ */
