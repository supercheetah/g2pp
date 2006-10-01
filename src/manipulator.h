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
#ifndef G2MANIPULATOR_H
#define G2MANIPULATOR_H

#include <device.h>

namespace g2 {

/**
	@author Rene Horn <the.rhorn@gmail.com>
*/
class Manipulator{
    friend Device& operator<< (Device &dout, Manipulator &manipulator);
public:
    Manipulator();

    virtual ~Manipulator();

protected:
    virtual void Manipulate(int dev) = 0;
};

Device& operator<< (Device &device, Manipulator &manipulator);

} //namespace g2

#endif
