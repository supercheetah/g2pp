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
#include "dashes.h"

#include <cstring>

namespace g2 {

Dashes::Dashes(int num_dash_lengths, double *dash_lengths)
    : Manipulator(), m_dashLengths(new double[num_dash_lengths]),
      m_numDashLengths(num_dash_lengths)
{
    memcpy(m_dashLengths, dash_lengths, num_dash_lengths*sizeof(double));
}


Dashes::~Dashes()
{
    delete [] m_dashLengths;
}


void Dashes::Manipulate(int dev)
{
    g2_set_dash(dev, m_numDashLengths, m_dashLengths);
}

} //namespace g2
