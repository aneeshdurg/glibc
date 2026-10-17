/* Invoke the brk system call.  Generic Linux version.
   Copyright (C) 2022-2024 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library.  If not, see
   <https://www.gnu.org/licenses/>.  */

static inline void *
__brk_call (void *addr)
{
  /* DIFUSE: this libc shares its process with the application, whose
     program break it must leave alone.  A NULL break makes every __brk
     other than __brk (0) fail with ENOMEM, and malloc uses mmap.  */
  if (1)
    return NULL;
  /* The default implementation reports errors through an unchanged
     break.  */
  return (void *) INTERNAL_SYSCALL_CALL (brk, addr);
}
