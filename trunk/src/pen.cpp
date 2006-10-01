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
#include "pen.h"
#include "device.h"

#ifdef DEBUG
#  include <cassert>
#  include <iostream>
using std::cerr;
using std::endl;
#endif

#define COLORERR(color) #color " out of range"

namespace g2 {

    inline bool IsInvalid(double color)
    {
        return (color<0.0) && (color>1.0);
    }

Device& operator>> (Device &din, Ink &ink) throw( g2exception )
{
    if(din.m_deviceType!=VD)
        throw g2exception("Ink must come from physical device.", 
                          INKLESS_DEVICE);
    if(IsInvalid(ink.red))
        throw g2exception(COLORERR(Red), COLOR_OUTSIDE_RANGE);
    if(IsInvalid(ink.green))
        throw g2exception(COLORERR(Green), COLOR_OUTSIDE_RANGE);
    if(IsInvalid(ink.blue))
        throw g2exception(COLORERR(Blue), COLOR_OUTSIDE_RANGE);
    
    ink.color=g2_ink(din.m_device, ink.red, ink.green, ink.blue);
    return din;
}

Device& operator<< (Device &dout, Pen &pen)
{
    g2_pen(dout.m_device, pen.m_ink.color);
    return dout;
}

Pen::Pen()
{
    m_isEmpty=true;
}


Pen::~Pen()
{
}


} //namespace g2


/*!
    \fn g2::Pen::IsEmpty() const
 */
bool g2::Pen::IsEmpty() const
{
    return m_isEmpty;
}
