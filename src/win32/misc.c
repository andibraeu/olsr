/*
 * The olsr.org Optimized Link-State Routing daemon (olsrd)
 * Copyright (c) 2004, Thomas Lopatic (thomas@lopatic.de)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met:
 *
 * * Redistributions of source code must retain the above copyright 
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright 
 *   notice, this list of conditions and the following disclaimer in 
 *   the documentation and/or other materials provided with the 
 *   distribution.
 * * Neither the name of olsr.org, olsrd nor the names of its 
 *   contributors may be used to endorse or promote products derived 
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Visit http://www.olsr.org for more information.
 *
 * If you find this software useful feel free to make a donation
 * to the project. For more information see the website or contact
 * the copyright holders.
 *
 * $Id: misc.c,v 1.2 2004/11/21 01:21:10 tlopatic Exp $
 */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef interface

void clear_console(void)
{
  HANDLE Hand;
  CONSOLE_SCREEN_BUFFER_INFO Info;
  unsigned long Written;
  static COORD Home = { 0, 0 };

  Hand = GetStdHandle(STD_OUTPUT_HANDLE);

  if (Hand == INVALID_HANDLE_VALUE)
    return;

  if(!GetConsoleScreenBufferInfo(Hand, &Info))
    return;

  if(!FillConsoleOutputCharacter(Hand, ' ',
                                 Info.dwSize.X * Info.dwSize.Y, Home,
                                 &Written))
    return;

  if(!FillConsoleOutputAttribute(Hand, Info.wAttributes,
                                 Info.dwSize.X * Info.dwSize.Y, Home,
                                 &Written))
    return;

  SetConsoleCursorPosition(Hand, Home);
}