//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "ADDirichletBCBaseTempl.h"

/**
 * Boundary condition of a Dirichlet type
 *
 * Sets the values of a LAGRANGE_VEC variable at nodes to values specified by functions
 */
class ADVectorFunctionDirichletBC : public ADDirichletBCBaseTempl<RealVectorValue>
{
public:
  static InputParameters validParams();

  ADVectorFunctionDirichletBC(const InputParameters & parameters);

protected:
  virtual ADRealVectorValue computeQpValue() override;

  /// Optional vectorValue function
  const Function * const _function;

  /// x component function
  const Function & _function_x;
  /// y component function
  const Function & _function_y;
  /// z component function
  const Function & _function_z;

  /// The value for this BC
  RealVectorValue _values;
};
