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
#include "multipointshape.h"

#include <cstdlib>
#include <cstring>

namespace g2 {

size_t MultiPointShape::m_refCount=0;
double *MultiPointShape::m_pointsBuffer=NULL;

MultiPointShape::MultiPointShape(int num_points, Point *points)
 : Shape()
{
    m_points=new Point[num_points];
    memcpy(m_points, points, num_points*sizeof(double));
    m_numPoints=num_points;
    m_refCount++;
}


MultiPointShape::~MultiPointShape()
{
    delete [] m_points;
    m_refCount--;
    if(0>=m_refCount && NULL!=m_pointsBuffer)
        free(m_pointsBuffer);
}

} //namespace g2


/*!
    \fn g2::MultiPointShape::CopyPointsToBuffer()
 */
void g2::MultiPointShape::CopyPointsToBuffer() const
{
    /// @todo implement me
    if(NULL==m_pointsBuffer)
        m_pointsBuffer = (double*)malloc(m_numPoints*2*sizeof(double));
    else
        realloc(m_pointsBuffer, m_numPoints*2*sizeof(double));
    
    for( int i=0, j=0; i<m_numPoints; i++){
        m_pointsBuffer[j++]=m_points[i].x;
        m_pointsBuffer[j++]=m_points[i].y;
    }

}
