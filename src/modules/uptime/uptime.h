#pragma once

#include "fastfetch.h"
#include <yyjson.h>

#define FF_UPTIME_MODULE_NAME "Uptime"

void ffPrintUptime(FFinstance* instance, FFUptimeOptions* options);
void ffInitUptimeOptions(FFUptimeOptions* options);
bool ffParseUptimeCommandOptions(FFUptimeOptions* options, const char* key, const char* value);
void ffDestroyUptimeOptions(FFUptimeOptions* options);
void ffParseUptimeJsonObject(FFinstance* instance, yyjson_val* module);
