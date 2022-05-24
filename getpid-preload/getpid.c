/*
	Generate a random pid using /dev/urandom. 
	If the MAGICPID environment is set, use that integer value.

	BSD 2-Clause License

	Copyright (c) 2008, HD Moore
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this
	list of conditions and the following disclaimer.

	2. Redistributions in binary form must reproduce the above copyright notice,
	this list of conditions and the following disclaimer in the documentation
	and/or other materials provided with the distribution.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
	FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
	SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
	CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
	OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.	
*/

#include <stdio.h>
#include <stdlib.h>

int magicpid = 0;

pid_t getpid(void)
{
	FILE *fd;
	unsigned int seed;
	
	if(magicpid) return magicpid;	

	if(getenv("MAGICPID")) {
		magicpid = atoi(getenv("MAGICPID"));
		return magicpid;
	}
	
	fd = fopen("/dev/urandom", "rb");
	fread(&seed, sizeof(seed), 1, fd);
	fclose(fd);
	
	magicpid = seed % 32768;
	return magicpid;
}
