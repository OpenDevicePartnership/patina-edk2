/** @file
  Patina Performance Configuration HOB

  This file defines the structure for the Patina Performance Configuration HOB.

  How to use this HOB:

  1. This is only relevant if the platform is using the Patina DXE Core and with the `Performance` component
     included in the platform build of the Patina DXE Core.
  2. This HOB should only be used if the platform needs to dynamically configure the Patina Performance component
     during boot. If that platform build has fixed performance configuration, it can simply configure the `Performance`
     component in the Patina DXE Core build configuration.
  3. The HOB must be produced in a PI producer phase such as PEI or an equivalent phase in non-PI environments prior
     to executing the Patina DXE Core.
  4. Only one copy of the HOB should be produced.

  Note: The HOB is meant to bridge platform-specific details about performance configuration to the Patina Performance
        component. For example, the platform may choose to populate the HOB values based on a build flag, a PCD, or
        other mechanism for the given platform build/boot.

  Copyright (c) Microsoft Corporation. All rights reserved.

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef PATINA_PERFORMANCE_CONFIG_H_
#define PATINA_PERFORMANCE_CONFIG_H_

#define PATINA_PERFORMANCE_CONFIG_HOB_GUID \
    { 0xfd87f2d8, 0x112d, 0x4640, { 0x9c, 0x00, 0xd3, 0x7d, 0x2a, 0x1f, 0xb7, 0x5d } }

#pragma pack(push, 1)
typedef struct {
  ///
  /// Whether the Patina Performance component should be enabled.
  ///
  BOOLEAN    Enabled;
  ///
  /// A mask for selecting measurements enabled in the Patina Performance component.
  ///
  UINT32     EnabledMeasurements;
} PATINA_PERFORMANCE_CONFIG_HOB;
#pragma pack(pop)

#endif
