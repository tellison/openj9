/*******************************************************************************
 * Copyright (c) 2002, 2014 IBM Corp. and others
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at https://www.eclipse.org/legal/epl-2.0/
 * or the Apache License, Version 2.0 which accompanies this distribution and
 * is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following
 * Secondary Licenses when the conditions for such availability set
 * forth in the Eclipse Public License, v. 2.0 are satisfied: GNU
 * General Public License, version 2 with the GNU Classpath
 * Exception [1] and GNU General Public License, version 2 with the
 * OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] http://openjdk.java.net/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0
 *******************************************************************************/
#define true 1
#define false 0
#include "floatsanityg.h"


   void group_JBd2i() {
      int i=0, groupNum=1,numTests=28;
      int testsPassed=0, testsFailed=0;
      unsigned int op_0 [] = {
         0x80000000, 0x00000000,
         0x40000000, 0x00000000,
         0xc0100000, 0x00000000,
         0xc0000000, 0x00000000,
         0x40080000, 0x00000000,
         0x40140000, 0x00000000,
         0x40240000, 0x00000000,
         0x40100000, 0x00000000,
         0x00000000, 0x00000000,
         0x3ff00000, 0x00000000,
         0xbff00000, 0x00000000,
         0x405fc000, 0x00000000,
         0xc0600000, 0x00000000,
         0x40dfffc0, 0x00000000,
         0xc0e00000, 0x00000000,
         0xc1e00000, 0x00000000,
         0x7ff00000, 0x00000000,
         0xfff00000, 0x00000000,
         0x7fefffff, 0xffffffff,
         0xffefffff, 0xffffffff,
         0x00000000, 0x00000001,
         0x80000000, 0x00000001,
         0x408f4000, 0x00000000,
         0xc08f4000, 0x00000000,
         0x40300000, 0x00000000,
         0x40180000, 0x00000000,
         0x401c0000, 0x00000000,
         0x402c0000, 0x00000000,
         0x0, 0x0};
      unsigned int result [] = {
         0x00000000,
         0x00000002,
         0xfffffffc,
         0xfffffffe,
         0x00000003,
         0x00000005,
         0x0000000a,
         0x00000004,
         0x00000000,
         0x00000001,
         0xffffffff,
         0x0000007f,
         0xffffff80,
         0x00007fff,
         0xffff8000,
         0x80000000,
         0x7fffffff,
         0x80000000,
         0x7fffffff,
         0x80000000,
         0x00000000,
         0x00000000,
         0x000003e8,
         0xfffffc18,
         0x00000010,
         0x00000006,
         0x00000007,
         0x0000000e,
         0x0};
      double *p0=(double *) op_0;
      int *erp=(int*) result, r, *rp=&r;
      for (i=0; i<numTests; i++) {
         r = JBd2i(*(p0));
         if ( IS_SNAN(erp)){
            if ( !(IS_SNAN(&r)) ){
               printf("%d.%d: op_0=0x%08x%08x Expected=0x%08x Actual=0x%08x \n",
                  groupNum, i, 
                  *(int *)p0, *((int *)p0+1), *(int *)erp, *(int *)&r);
               testsFailed++;
            } else {
               testsPassed++;
            }

         } else {
            if ( (FLWORD(&r) != FLWORD(erp)) ){
               printf("%d.%d: op_0=0x%08x%08x Expected=0x%08x Actual=0x%08x \n",
                  groupNum, i, 
                  *(int *)p0, *((int *)p0+1), *(int *)erp, *(int *)&r);
               testsFailed++;
            } else {
               testsPassed++;
            }
         }

         p0++;erp++;
      }
      printf("[%d] %s Passed %d Failed %d Total %d \n", groupNum,"JBd2i", testsPassed, testsFailed, numTests);
      totalNumTest +=numTests; totalTestsPassed +=testsPassed; totalTestsFailed +=testsFailed;
   }

