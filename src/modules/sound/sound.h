#pragma once

#include "fastfetch.h"
#include <yyjson.h>

#define FF_SOUND_MODULE_NAME "Sound"

void ffPrintSound(FFinstance* instance, FFSoundOptions* options);
void ffInitSoundOptions(FFSoundOptions* options);
bool ffParseSoundCommandOptions(FFSoundOptions* options, const char* key, const char* value);
void ffDestroySoundOptions(FFSoundOptions* options);
void ffParseSoundJsonObject(FFinstance* instance, yyjson_val* module);
