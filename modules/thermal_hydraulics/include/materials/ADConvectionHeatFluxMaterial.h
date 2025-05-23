//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "Material.h"

/**
 * Computes heat flux from convection for a given fluid phase.
 */
class ADConvectionHeatFluxMaterial : public Material
{
public:
  ADConvectionHeatFluxMaterial(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;

  /// Wall heat flux
  ADMaterialProperty<Real> & _q_wall;
  /// Fluid temperature for phase
  const ADMaterialProperty<Real> & _T;
  /// Wall temperature
  const ADVariableValue & _T_wall;
  /// Wall heat transfer coefficient for phase
  const ADMaterialProperty<Real> & _htc_wall;
  /// Wall contact fraction for phase
  const ADMaterialProperty<Real> & _kappa;

public:
  static InputParameters validParams();
};
