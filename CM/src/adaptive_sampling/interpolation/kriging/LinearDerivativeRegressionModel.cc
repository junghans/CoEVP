// DO-NOT-DELETE revisionify.begin() 
/*

                            Copyright (c) 2014.
               Lawrence Livermore National Security, LLC.
         Produced at the Lawrence Livermore National Laboratory
                             LLNL-CODE-656392.
                           All rights reserved.

This file is part of CoEVP, Version 1.0. Please also read this link -- http://www.opensource.org/licenses/index.php

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the disclaimer below.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the disclaimer (as noted below)
     in the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the LLNS/LLNL nor the names of its contributors
     may be used to endorse or promote products derived from this software
     without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL LAWRENCE LIVERMORE NATIONAL SECURITY, LLC,
THE U.S. DEPARTMENT OF ENERGY OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


Additional BSD Notice

1. This notice is required to be provided under our contract with the U.S.
   Department of Energy (DOE). This work was produced at Lawrence Livermore
   National Laboratory under Contract No. DE-AC52-07NA27344 with the DOE.

2. Neither the United States Government nor Lawrence Livermore National
   Security, LLC nor any of their employees, makes any warranty, express
   or implied, or assumes any liability or responsibility for the accuracy,
   completeness, or usefulness of any information, apparatus, product, or
   process disclosed, or represents that its use would not infringe
   privately-owned rights.

3. Also, reference herein to any specific commercial products, process, or
   services by trade name, trademark, manufacturer or otherwise does not
   necessarily constitute or imply its endorsement, recommendation, or
   favoring by the United States Government or Lawrence Livermore National
   Security, LLC. The views and opinions of authors expressed herein do not
   necessarily state or reflect those of the United States Government or
   Lawrence Livermore National Security, LLC, and shall not be used for
   advertising or product endorsement purposes.

*/
// DO-NOT-DELETE revisionify.end() 
//
// File:        LinearDerivativeRegressionModel.cc
// Package:     kriging algorithm
// 
// 
// 
// Description: Class implementing linear regression model with derivatives.
//
// $Id$
//
// $Log$
//

#include "LinearDerivativeRegressionModel.h"

namespace krigalg {

  //
  // construction/destruction
  //

  LinearDerivativeRegressionModel::LinearDerivativeRegressionModel()
  {

    return;

  }

  LinearDerivativeRegressionModel::~LinearDerivativeRegressionModel()
  {

    return;
    
  }

  //
  // compute a matrix containing values of the regression model:
  // first row:  {1, x1, x2, ..., xd}
  // second row: {0, 1,  0,  ..., 0}
  // ...
  // n-th row:   {0, 0, ..., 1, ..., 0}; "1" appears in the n-th slot
  //

  Matrix
  LinearDerivativeRegressionModel::getValues(const Point & point) const
  {

    const int pointDimension = point.size();
    const int dimension = pointDimension + 1;

    //
    // instantiate Matrix
    //

    Matrix values = identity(dimension);

    //
    // fill function basis values
    //

    for (int i = 1; i < dimension; ++i)
      values[0][i] = point[i - 1];

    return values;

  }

  //
  // get dimension 
  //

  Dimension
  LinearDerivativeRegressionModel::getDimension(const Point & point) const
  {

    return Dimension(point.size() + 1,
		     point.size() + 1);

  }

  //
  // get a string representation of the class name
  //

  std::string
  LinearDerivativeRegressionModel::getClassName() const
  {
    
    return std::string("krigalg::LinearDerivativeRegressionModel");
  }
    
  //
  // Database output
  //
  
  void
  LinearDerivativeRegressionModel::putToDatabase(toolbox::Database & db) const
  {
   
    //
    // store base-class data
    //

    DerivativeRegressionModel::putToDatabase(db);

    //
    //
    //
 
    return;

  }

  //
  // Database input
  //

  void
  LinearDerivativeRegressionModel::getFromDatabase(toolbox::Database & db)
  {
    
    //
    // get base-class data
    //

    DerivativeRegressionModel::getFromDatabase(db);

    //
    //
    //

    return;
    
  }


}


