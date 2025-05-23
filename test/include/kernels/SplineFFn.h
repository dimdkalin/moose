//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "Kernel.h"
#include "SplineFunction.h"

/**
 * Forcing function defined with a spline
 */
class SplineFFn : public Kernel
{
public:
  static InputParameters validParams();

  SplineFFn(const InputParameters & parameters);
  virtual ~SplineFFn();

protected:
  virtual Real computeQpResidual();

  const SplineFunction & _fn;
};
