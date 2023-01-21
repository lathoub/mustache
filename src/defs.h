#pragma once

#if ARDUINO
#include <Arduino.h>
#else
#include <inttypes.h>
typedef uint8_t byte;
#endif

#include "namespace.h"

BEGIN_MUSTACHE_NAMESPACE

const String __dirname{};

END_MUSTACHE_NAMESPACE
