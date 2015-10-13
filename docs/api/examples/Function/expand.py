#
#     This file is part of CasADi.
#
#     CasADi -- A symbolic framework for dynamic optimization.
#     Copyright (C) 2010-2014 Joel Andersson, Joris Gillis, Moritz Diehl,
#                             K.U. Leuven. All rights reserved.
#     Copyright (C) 2011-2014 Greg Horn
#
#     CasADi is free software; you can redistribute it and/or
#     modify it under the terms of the GNU Lesser General Public
#     License as published by the Free Software Foundation; either
#     version 3 of the License, or (at your option) any later version.
#
#     CasADi is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#     Lesser General Public License for more details.
#
#     You should have received a copy of the GNU Lesser General Public
#     License along with CasADi; if not, write to the Free Software
#     Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
#
#
#! expand
#!======================
from casadi import *
import casadi as c

#! We construct a simple MX expression
x = MX.sym("x",2,2)
y = MX.sym("y",2,1)

z = mul(x,y)

#! Let's construct an MXfunction
f = MX.fun("f", [x,y],[z])

#! We expand the MX.fun into an SX.fun
fSX = SX.fun('fSX', f)

print "Expanded expression = ", fSX


#! Limitations
#! =============
#! Not all MX graphs can be expanded.
#! Here is an example of a situation where it will not work.
#!
linear_solver = LinearSolver("linear_solver", "csparse", x.sparsity())
g = linear_solver.solve(x,y)
G = MX.fun("G", [x,y], [g])

#! This function cannot be expanded.
try:
  SX.fun('G_sx', G)
except Exception as e:
  print e
