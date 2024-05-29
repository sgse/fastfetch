#include "fastfetch.h"
#include "modules/modules.h"

void ffOptionsInitModules(FFOptionsModules* options)
{
    ffInitBatteryOptions(&options->battery);
    ffInitBiosOptions(&options->bios);
    ffInitBluetoothOptions(&options->bluetooth);
    ffInitBoardOptions(&options->board);
    ffInitBootmgrOptions(&options->bootmgr);
    ffInitBreakOptions(&options->break_);
    ffInitBrightnessOptions(&options->brightness);
    ffInitCameraOptions(&options->camera);
    ffInitCPUOptions(&options->cpu);
    ffInitCPUUsageOptions(&options->cpuUsage);
    ffInitChassisOptions(&options->chassis);
    ffInitColorsOptions(&options->colors);
    ffInitCommandOptions(&options->command);
    ffInitCursorOptions(&options->cursor);
    ffInitCustomOptions(&options->custom);
    ffInitDEOptions(&options->de);
    ffInitDateTimeOptions(&options->dateTime);
    ffInitDiskOptions(&options->disk);
    ffInitDiskIOOptions(&options->diskIo);
    ffInitDisplayOptions(&options->display);
    ffInitEditorOptions(&options->editor);
    ffInitFontOptions(&options->font);
    ffInitGPUOptions(&options->gpu);
    ffInitGamepadOptions(&options->gamepad);
    ffInitHostOptions(&options->host);
    ffInitIconsOptions(&options->icons);
    ffInitInitSystemOptions(&options->initSystem);
    ffInitKernelOptions(&options->kernel);
    ffInitLMOptions(&options->lm);
    ffInitLoadavgOptions(&options->loadavg);
    ffInitLocalIpOptions(&options->localIP);
    ffInitLocaleOptions(&options->locale);
    ffInitMediaOptions(&options->media);
    ffInitMemoryOptions(&options->memory);
    ffInitMonitorOptions(&options->monitor);
    ffInitNetIOOptions(&options->netIo);
    ffInitOSOptions(&options->os);
    ffInitOpenCLOptions(&options->openCL);
    ffInitOpenGLOptions(&options->openGL);
    ffInitPackagesOptions(&options->packages);
    ffInitPhysicalDiskOptions(&options->physicalDisk);
    ffInitPhysicalMemoryOptions(&options->physicalMemory);
    ffInitPlayerOptions(&options->player);
    ffInitPowerAdapterOptions(&options->powerAdapter);
    ffInitProcessesOptions(&options->processes);
    ffInitPublicIpOptions(&options->publicIP);
    ffInitSeparatorOptions(&options->separator);
    ffInitShellOptions(&options->shell);
    ffInitSoundOptions(&options->sound);
    ffInitSwapOptions(&options->swap);
    ffInitTerminalOptions(&options->terminal);
    ffInitTerminalFontOptions(&options->terminalFont);
    ffInitTerminalSizeOptions(&options->terminalSize);
    ffInitTerminalThemeOptions(&options->terminalTheme);
    ffInitThemeOptions(&options->theme);
    ffInitTitleOptions(&options->title);
    ffInitUptimeOptions(&options->uptime);
    ffInitUsersOptions(&options->users);
    ffInitVersionOptions(&options->version);
    ffInitVulkanOptions(&options->vulkan);
    ffInitWMOptions(&options->wm);
    ffInitWMThemeOptions(&options->wmTheme);
    ffInitWallpaperOptions(&options->wallpaper);
    ffInitWeatherOptions(&options->weather);
    ffInitWifiOptions(&options->wifi);
}

void ffOptionsDestroyModules(FFOptionsModules* options)
{
    ffDestroyBatteryOptions(&options->battery);
    ffDestroyBiosOptions(&options->bios);
    ffDestroyBluetoothOptions(&options->bluetooth);
    ffDestroyBoardOptions(&options->board);
    ffDestroyBootmgrOptions(&options->bootmgr);
    ffDestroyBreakOptions(&options->break_);
    ffDestroyBrightnessOptions(&options->brightness);
    ffDestroyCameraOptions(&options->camera);
    ffDestroyCPUOptions(&options->cpu);
    ffDestroyCPUUsageOptions(&options->cpuUsage);
    ffDestroyChassisOptions(&options->chassis);
    ffDestroyColorsOptions(&options->colors);
    ffDestroyCommandOptions(&options->command);
    ffDestroyCursorOptions(&options->cursor);
    ffDestroyCustomOptions(&options->custom);
    ffDestroyDEOptions(&options->de);
    ffDestroyDateTimeOptions(&options->dateTime);
    ffDestroyDiskOptions(&options->disk);
    ffDestroyDiskIOOptions(&options->diskIo);
    ffDestroyDisplayOptions(&options->display);
    ffDestroyEditorOptions(&options->editor);
    ffDestroyFontOptions(&options->font);
    ffDestroyGPUOptions(&options->gpu);
    ffDestroyGamepadOptions(&options->gamepad);
    ffDestroyHostOptions(&options->host);
    ffDestroyIconsOptions(&options->icons);
    ffDestroyInitSystemOptions(&options->initSystem);
    ffDestroyKernelOptions(&options->kernel);
    ffDestroyLMOptions(&options->lm);
    ffDestroyLoadavgOptions(&options->loadavg);
    ffDestroyLocalIpOptions(&options->localIP);
    ffDestroyLocaleOptions(&options->locale);
    ffDestroyMediaOptions(&options->media);
    ffDestroyMemoryOptions(&options->memory);
    ffDestroyMonitorOptions(&options->monitor);
    ffDestroyNetIOOptions(&options->netIo);
    ffDestroyOSOptions(&options->os);
    ffDestroyOpenCLOptions(&options->openCL);
    ffDestroyOpenGLOptions(&options->openGL);
    ffDestroyPhysicalDiskOptions(&options->physicalDisk);
    ffDestroyPhysicalMemoryOptions(&options->physicalMemory);
    ffDestroyPackagesOptions(&options->packages);
    ffDestroyPlayerOptions(&options->player);
    ffDestroyPowerAdapterOptions(&options->powerAdapter);
    ffDestroyProcessesOptions(&options->processes);
    ffDestroyPublicIpOptions(&options->publicIP);
    ffDestroySeparatorOptions(&options->separator);
    ffDestroyShellOptions(&options->shell);
    ffDestroySoundOptions(&options->sound);
    ffDestroySwapOptions(&options->swap);
    ffDestroyTerminalOptions(&options->terminal);
    ffDestroyTerminalFontOptions(&options->terminalFont);
    ffDestroyTerminalSizeOptions(&options->terminalSize);
    ffDestroyTerminalThemeOptions(&options->terminalTheme);
    ffDestroyThemeOptions(&options->theme);
    ffDestroyTitleOptions(&options->title);
    ffDestroyUptimeOptions(&options->uptime);
    ffDestroyUsersOptions(&options->users);
    ffDestroyVersionOptions(&options->version);
    ffDestroyVulkanOptions(&options->vulkan);
    ffDestroyWMOptions(&options->wm);
    ffDestroyWMThemeOptions(&options->wmTheme);
    ffDestroyWallpaperOptions(&options->wallpaper);
    ffDestroyWeatherOptions(&options->weather);
    ffDestroyWifiOptions(&options->wifi);
}
