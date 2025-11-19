/** @file
  ACPI Table Protocol Driver

  Copyright (c) 2006 - 2021, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _ACPI_TABLE_H_
#define _ACPI_TABLE_H_

#include <PiDxe.h>

#include <Protocol/AcpiTable.h>
#include <Protocol/AcpiGet.h>
#include <Guid/Acpi.h>
#include <Protocol/AcpiSystemDescriptionTable.h>

#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiDriverEntryPoint.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/PcdLib.h>
#include <Library/HobLib.h>
#include <UniversalPayload/AcpiTable.h>

//
// Statements that include other files
//
#include <IndustryStandard/Acpi.h>

#include "AcpiSdt.h"

//
// ACPI support protocol instance data structure
//
typedef struct {
  UINTN                                           Signature;
  EFI_ACPI_1_0_ROOT_SYSTEM_DESCRIPTION_POINTER    *Rsdp1;               // Pointer to RSD_PTR structure
  EFI_ACPI_3_0_ROOT_SYSTEM_DESCRIPTION_POINTER    *Rsdp3;               // Pointer to RSD_PTR structure
  EFI_ACPI_DESCRIPTION_HEADER                     *Rsdt1;               // Pointer to RSDT table header
  EFI_ACPI_DESCRIPTION_HEADER                     *Rsdt3;               // Pointer to RSDT table header
  EFI_ACPI_DESCRIPTION_HEADER                     *Xsdt;                // Pointer to XSDT table header
  EFI_ACPI_1_0_FIXED_ACPI_DESCRIPTION_TABLE       *Fadt1;               // Pointer to FADT table header
  EFI_ACPI_3_0_FIXED_ACPI_DESCRIPTION_TABLE       *Fadt3;               // Pointer to FADT table header
  EFI_ACPI_1_0_FIRMWARE_ACPI_CONTROL_STRUCTURE    *Facs1;               // Pointer to FACS table header
  EFI_ACPI_3_0_FIRMWARE_ACPI_CONTROL_STRUCTURE    *Facs3;               // Pointer to FACS table header
  EFI_ACPI_DESCRIPTION_HEADER                     *Dsdt1;               // Pointer to DSDT table header
  EFI_ACPI_DESCRIPTION_HEADER                     *Dsdt3;               // Pointer to DSDT table header
  LIST_ENTRY                                      TableList;
  UINTN                                           NumberOfTableEntries1; // Number of ACPI 1.0 tables
  UINTN                                           NumberOfTableEntries3; // Number of ACPI 3.0 tables
  UINTN                                           CurrentHandle;
  EFI_ACPI_TABLE_PROTOCOL                         AcpiTableProtocol;
  EFI_ACPI_SDT_PROTOCOL                           AcpiSdtProtocol;
  LIST_ENTRY                                      NotifyList;
} EFI_ACPI_TABLE_INSTANCE;

//
// Protocol Constructor functions
//

/**

  This function calculates and updates an UINT8 checksum.

  @param[in]  Buffer          Pointer to buffer to checksum
  @param[in]  Size            Number of bytes to checksum
  @param[in]  ChecksumOffset  Offset to place the checksum result in

  @retval EFI_SUCCESS             The function completed successfully.

**/
EFI_STATUS
AcpiPlatformChecksum (
  IN VOID   *Buffer,
  IN UINTN  Size,
  IN UINTN  ChecksumOffset
  );

/**
  This function initializes AcpiSdt protocol in ACPI table instance.

  @param[in]  AcpiTableInstance       Instance to construct
**/
VOID
SdtAcpiTableAcpiSdtConstructor (
  IN EFI_ACPI_TABLE_INSTANCE  *AcpiTableInstance
  );

extern EFI_HANDLE  mHandle;

#endif
