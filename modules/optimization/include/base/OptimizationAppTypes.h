//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "Moose.h"

namespace OptimizationAppTypes
{
extern const ExecFlagType EXEC_FORWARD;
extern const ExecFlagType EXEC_ADJOINT;
extern const ExecFlagType EXEC_HOMOGENEOUS_FORWARD;

extern const ExecFlagType EXEC_ADJOINT_TIMESTEP_BEGIN;
extern const ExecFlagType EXEC_ADJOINT_TIMESTEP_END;
}
