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

class PolyForcing : public Kernel
{
public:
  static InputParameters validParams();

  PolyForcing(const InputParameters & parameters);

protected:
  Real f();

  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  Real _x;
  Real _y;
  Real _z;
};
