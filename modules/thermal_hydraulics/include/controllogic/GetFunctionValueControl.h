//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "THMControl.h"

class Function;

/**
 * This control takes a function and converts it into a control data
 */
class GetFunctionValueControl : public THMControl
{
public:
  GetFunctionValueControl(const InputParameters & parameters);

  virtual void execute();

protected:
  /// The stored function value
  Real & _value;
  /// Function that is sampled
  const Function & _function;

public:
  static InputParameters validParams();
};
