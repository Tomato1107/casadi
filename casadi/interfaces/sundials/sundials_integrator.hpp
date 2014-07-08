/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010 by Joel Andersson, Moritz Diehl, K.U.Leuven. All rights reserved.
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef SUNDIALS_INTEGRATOR_HPP
#define SUNDIALS_INTEGRATOR_HPP

#include "casadi/core/function/integrator.hpp"

#include <casadi/interfaces/sundials/casadi_sundials_common_export.h>

namespace casadi {

/// Forward declaration of internal class
class SundialsInternal;

/** \brief Interface to the Sundials integrators

  @copydoc DAE_doc
*/
class CASADI_SUNDIALS_COMMON_EXPORT SundialsIntegrator : public Integrator {
public:
  /// Default constructor
  SundialsIntegrator();

  /// Access functions of the node
  SundialsInternal* operator->();

  /// Access functions of the node
  const SundialsInternal* operator->() const;

  /// Check if the node is pointing to the right type of object
  virtual bool checkNode() const;

  /// Set a stop time for the forward integration
  void setStopTime(double tf);
};

} // namespace casadi

#endif //SUNDIALS_INTEGRATOR_HPP
