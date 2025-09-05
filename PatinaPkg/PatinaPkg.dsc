## @file
# Build description file for PatinaPkg.
#
# Copyright (C) Microsoft Corporation.
#
# SPDX-License-Identifier: Apache-2.0
#
##
[Defines]
  PLATFORM_NAME                  = PatinaPkg
  PLATFORM_GUID                  = 2C4B0625-39D0-4F45-9DAD-584E7983A0CE
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x0001001C
  OUTPUT_DIRECTORY               = Build/$(PLATFORM_NAME)
  SUPPORTED_ARCHITECTURES        = IA32|X64|AARCH64
  BUILD_TARGETS                  = DEBUG|RELEASE|NO-TARGET
  SKUID_IDENTIFIER               = DEFAULT
