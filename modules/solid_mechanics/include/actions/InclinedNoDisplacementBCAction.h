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

class InclinedNoDisplacementBCAction : public Action
{
public:
  static InputParameters validParams();

  InclinedNoDisplacementBCAction(const InputParameters & params);

  virtual void act() override;

protected:
  /// Flag to use automatic differentiation
  const bool _use_ad;

  /// displacement variables
  std::vector<VariableName> _displacements;

  /// number of displacement variables
  unsigned int _ndisp;

  /// auxvariables to save residuals
  std::vector<AuxVariableName> _save_in;
};
