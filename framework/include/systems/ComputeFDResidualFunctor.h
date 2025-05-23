//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "libmesh/nonlinear_implicit_system.h"
#include "MooseTypes.h"

namespace libMesh
{
template <typename>
class NumericVector;
class NonlinearImplicitSystem;
}

class FEProblemBase;

class ComputeFDResidualFunctor : public libMesh::NonlinearImplicitSystem::ComputeResidual
{
private:
  FEProblemBase & _fe_problem;

public:
  ComputeFDResidualFunctor(FEProblemBase & fe_problem);

  void residual(const libMesh::NumericVector<Number> & soln,
                libMesh::NumericVector<Number> & residual,
                libMesh::NonlinearImplicitSystem & sys) override;
};
