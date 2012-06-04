// Eden - A dynamic program analysis framework.
//
// Copyright (C) 2011 Jie Yu
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// Authors - Jie Yu (jieyu@umich.edu)

// File: delta/randsched_profiler.hpp - Define PSet profile controller.

#ifndef DELTA_RANDSCHED_PROFILER_HPP_
#define DELTA_RANDSCHED_PROFILER_HPP_

#include "core/basictypes.h"
#include "randsched/scheduler.hpp"
#include "delta/observer.h"
#include "idiom/iroot.h"
#include "ilist.h"

namespace delta {

class RandSchedProfiler : public randsched::Scheduler {
//class RandSchedProfiler : public ExecutionControl {

 public:
  RandSchedProfiler() : observer_(NULL), iroot_db_(NULL), ilist_(NULL){}
  ~RandSchedProfiler(){}

 private:
  void HandlePreSetup();
  void HandlePostSetup();
  //bool HandleIgnoreMemAccess(IMG img);
  void HandleProgramExit();

  Observer *observer_;
  idiom::iRootDB *iroot_db_;
  iList *ilist_;
  
  DISALLOW_COPY_CONSTRUCTORS(RandSchedProfiler);
};

} // namespace delta

#endif