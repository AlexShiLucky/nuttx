/****************************************************************************
 * libc/unistd/lib_gethostname.c
 *
 *   Copyright (C) 2015 Stavros Polymenis. All rights reserved.
 *   Author: Stavros Polymenis <sp@orbitalfox.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <string.h>
#include <unistd.h>

#ifdef CONFIG_NET

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifndef CONFIG_NET_HOSTNAME
#  define CONFIG_NET_HOSTNAME ""
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: gethostname
 *
 * Description:
 *   The gethostname() function will return the standard host name for the
 *   current machine. The namelen argument will specify the size of the
 *   array pointed to by the name argument. The returned name will be null-
 *   terminated, except that if namelen is an insufficient length to hold the
 *   host name, then the returned name will be truncated and it is
 *   unspecified whether the returned name is null-terminated.
 *
 *   Host names are limited to {HOST_NAME_MAX} bytes.
 *
 * Input Parameters:
 *   name - The user-provided buffer to receive the host name.
 *   namelen - The size of the user provided buffer in bytes.
 *
 * Returned Value:
 *   Upon successful completion, 0 will be returned; otherwise, -1 will be
 *   returned.  No errors are defined;  errno variable is not set.
 *
 ****************************************************************************/

int gethostname(FAR char *name, size_t namelen)
{
  /* Return the host name, truncating to fit into the user provided buffer */

  strncpy(name, CONFIG_NET_HOSTNAME, namelen);
  return 0;
}

#endif /* CONFIG_NET */
