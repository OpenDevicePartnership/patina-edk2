/** @file
  ACPI Table Protocol Implementation

  Copyright (c) 2006 - 2021, Intel Corporation. All rights reserved.<BR>
  Copyright (c) 2016, Linaro Ltd. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

//
// Includes
//
#include "AcpiTable.h"

/**
  This function calculates and updates an UINT8 checksum.

  @param  Buffer          Pointer to buffer to checksum
  @param  Size            Number of bytes to checksum
  @param  ChecksumOffset  Offset to place the checksum result in

  @return EFI_SUCCESS             The function completed successfully.
**/
EFI_STATUS
AcpiPlatformChecksum (
  IN VOID   *Buffer,
  IN UINTN  Size,
  IN UINTN  ChecksumOffset
  );

//
// Protocol function implementations.
//

/**
  This function calculates and updates an UINT8 checksum.

  @param  Buffer          Pointer to buffer to checksum
  @param  Size            Number of bytes to checksum
  @param  ChecksumOffset  Offset to place the checksum result in

  @return EFI_SUCCESS             The function completed successfully.

**/
EFI_STATUS
AcpiPlatformChecksum (
  IN VOID   *Buffer,
  IN UINTN  Size,
  IN UINTN  ChecksumOffset
  )
{
  UINT8  Sum;
  UINT8  *Ptr;

  Sum = 0;
  //
  // Initialize pointer
  //
  Ptr = Buffer;

  //
  // set checksum to 0 first
  //
  Ptr[ChecksumOffset] = 0;

  //
  // add all content of buffer
  //
  while ((Size--) != 0) {
    Sum = (UINT8)(Sum + (*Ptr++));
  }

  //
  // set checksum
  //
  Ptr                 = Buffer;
  Ptr[ChecksumOffset] = (UINT8)(0xff - Sum + 1);

  return EFI_SUCCESS;
}
