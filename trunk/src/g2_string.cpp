/***************************************************************************
 *   Copyright (C) 2006 by Rene Horn   *
 *   the.rhorn@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "g2_string.h"
#include <cstring>
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#ifdef HAVE_STRNLEN
#  include <climits> //useful for strnlen
#endif

namespace g2 {

g2_String::g2_String(double x, double y, const char *text, bool filled)
    : Shape(), m_point(x,y)
{
#ifdef HAVE_STRNLEN
    m_textLen=strnlen(text, UINT_MAX);
#else
    m_textLen=strlen(text); //dangerous!
#endif
    m_text=new char[m_textLen];
    strncpy(m_text, text, m_textLen);
    
    CommonInit();
}


g2_String::~g2_String()
{
    delete [] m_text;
}


void g2_String::DrawToDevice(int dev) const
{
    g2_string(dev, m_point.x, m_point.y, m_text);
}

} //namespace g2


/*!
    \fn g2::g2_String::g2_String(double x, double y, const char *text, size_t textLength, bool filled=false)
 */
 g2::g2_String::g2_String(double x, double y, const char *text, 
                          size_t textLength, bool filled)
    :Shape(), m_point(x,y), m_textLen(textLength)
{
    m_text=new char[m_textLen];
    strncpy(m_text, text, m_textLen);
    
    CommonInit();
}


/*!
    \fn g2::g2_String::g2_String(Point point, const char *text, bool filled=false)
 */
 g2::g2_String::g2_String(Point point, const char *text, bool filled)
    :Shape(), m_point(point)
{
#ifdef HAVE_STRNLEN
    m_textLen=strnlen(text, UINT_MAX);
#else
    m_textLen=strlen(text); //dangerous!
#endif
    m_text=new char[m_textLen];
    strncpy(m_text, text, m_textLen);
    
    CommonInit();
}


/*!
    \fn g2::g2_String::g2_String(Point point, const char *text, size_t textLength, bool filled=false)
 */
 g2::g2_String::g2_String(Point point, const char *text, size_t textLength,
                          bool filled)
    :Shape(), m_point(point), m_textLen(textLength)
{
    /// @todo implement me
    m_text=new char[m_textLen];
    strncpy(m_text, text, m_textLen);
    
    CommonInit();
}

/*!
    \fn g2::g2_String::CommonInit()
 */
void g2::g2_String::CommonInit()
{
}
