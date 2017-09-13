/*******************************************************************************
 * Copyright (c) 2012, 2014 IBM Corp. and others
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

#include "j9port.h"
#include "j9protos.h"

/**
 * Opens /proc/sys/kernel/sched_compat_yield if it exists
 * and returns the value.
 *
 * @param[in] javaVM A pointer to the J9JavaVM structure.
 *
 * @return A char representing the value of /proc/sys/kernel/sched_compat_yield or
 * 		   a whitespace char (' ') if the file does not exist or an error occurred.
 */
char
j9util_sched_compat_yield_value(J9JavaVM *javaVM)
{
	char value = ' ';
	IDATA fd = -1;
	PORT_ACCESS_FROM_JAVAVM(javaVM);

	fd = j9file_open("/proc/sys/kernel/sched_compat_yield", EsOpenRead, 0);
	if (fd != -1) {
		char buf[3] = "\0\0\0";
		IDATA bytesread = 0;

		bytesread = j9file_read(fd, buf, 3);
		if ((bytesread == 2) && (buf[1] == '\n')) {
			value = buf[0];
		}
		j9file_close(fd);
	}

	return value;
}
