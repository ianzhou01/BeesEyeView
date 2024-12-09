/******************************
 * File: common_defs.h
 * Purpose: This file declares the listComp shared comparator keyword utilized in sorting methods
 * Authors: Ian Zhou
 * Created: 12/4/2024
 ******************************/

#ifndef COMMON_DEFS_H
#define COMMON_DEFS_H

#include <functional>
#include "util.h"

using listComp = std::function<bool(const Listing&, const Listing&)>;

#endif