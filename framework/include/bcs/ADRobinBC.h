//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "ADIntegratedBC.h"

class ADRobinBC : public ADIntegratedBC
{
public:
  static InputParameters validParams();

  ADRobinBC(const InputParameters & parameters);

protected:
  ADReal computeQpResidual() override;

  /// Coefficient to be applied to the Robin boundary condition
  const Real _coef;
};
