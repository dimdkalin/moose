//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "Action.h"

/**
 * Used for marking that some block are deprecated and not be used
 */
class DeprecatedBlockAction : public Action
{
public:
  static InputParameters validParams();

  DeprecatedBlockAction(const InputParameters & parameters);

  void act() override;
};
