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
#ifndef G2PEN_H
#define G2PEN_H

#include <g2exception.h>

namespace g2 {

struct Ink
{
    double red;
    double green;
    double blue;
    int color;
    inline Ink(double r=0.0, double g=0.0, double b=0.0)
    {
        color=-1;
        red=r;
        green=g;
        blue=b;
    }
};

class Device;

Device& operator>>(Device &din, Ink &ink) throw( g2exception );

/**
    @author Rene Horn <the.rhorn@gmail.com>
*/
class Pen{
    friend void operator<<(Pen &pen, Ink &ink) throw( g2exception );
    friend Device& operator<< (Device &dout, Pen &pen) throw( g2exception );
public:
    Pen();
    ~Pen();
    bool IsEmpty() const;

protected:
    Ink m_ink;
    bool m_isEmpty;
}; //class Pen

Device& operator<< (Device &dout, Pen &pen) throw( g2exception );
void operator<<(Pen &pen, Ink &ink);

} //namespace g2

#endif
