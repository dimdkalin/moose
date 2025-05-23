//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "ThermalSolidProperties.h"

class ThermalUCProperties : public ThermalSolidProperties
{
public:
  static InputParameters validParams();

  ThermalUCProperties(const InputParameters & parameters);

  using ThermalSolidProperties::k_from_T;
  virtual Real k_from_T(const Real & T) const override;
  virtual void k_from_T(const Real & T, Real & k, Real & dk_dT) const override;

  using ThermalSolidProperties::cp_from_T;
  virtual Real cp_from_T(const Real & T) const override;
  virtual void cp_from_T(const Real & T, Real & cp, Real & dcp_dT) const override;

  using ThermalSolidProperties::cp_integral;
  virtual Real cp_integral(const Real & T) const override;

  using ThermalSolidProperties::rho_from_T;
  virtual Real rho_from_T(const Real & T) const override;
  virtual void rho_from_T(const Real & T, Real & rho, Real & drho_dT) const override;

protected:
  /// (constant) density
  const Real & _rho_const;

  // Constants used in specific heat relation
  const Real _c1;
  const Real _c2;
  const Real _c3;
  const Real _c4;
};
