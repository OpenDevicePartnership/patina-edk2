/** @file
  Aliased Memory Mapping Protocol

  This protocol creates and removes virtual mappings whose addresses differ
  from their backing physical addresses.

  Copyright (c) Microsoft Corporation.
  SPDX-License-Identifier: Apache-2.0
**/

#ifndef ALIASED_MEMORY_MAPPING_PROTOCOL_H_
#define ALIASED_MEMORY_MAPPING_PROTOCOL_H_

#define ALIASED_MEMORY_MAPPING_PROTOCOL_GUID \
  { 0xCD7B3711, 0x3CE3, 0x456D, { 0xB6, 0xE9, 0x74, 0x36, 0x4F, 0x0B, 0xA3, 0x44 } }

typedef struct _ALIASED_MEMORY_MAPPING_PROTOCOL ALIASED_MEMORY_MAPPING_PROTOCOL;

/**
  Creates an aliased virtual mapping to a physical memory range.

  @param[in] This             A pointer to the protocol instance.
  @param[in] VirtualAddress   The page-aligned virtual address to map.
  @param[in] PhysicalAddress  The page-aligned physical address backing the mapping.
  @param[in] Length           The nonzero, page-aligned mapping length.
  @param[in] Attributes       The UEFI memory attributes for the mapping.

  @retval EFI_SUCCESS            The mapping was created.
  @retval EFI_INVALID_PARAMETER  A parameter is invalid.
  @retval EFI_OUT_OF_RESOURCES   The mapping could not be created due to insufficient resources.
**/
typedef
EFI_STATUS
(EFIAPI *CREATE_ALIASED_MAPPING)(
  IN CONST ALIASED_MEMORY_MAPPING_PROTOCOL  *This,
  IN EFI_VIRTUAL_ADDRESS                    VirtualAddress,
  IN EFI_PHYSICAL_ADDRESS                   PhysicalAddress,
  IN UINT64                                 Length,
  IN UINT64                                 Attributes
  );

/**
  Removes a previously created aliased mapping.

  @param[in] This            A pointer to the protocol instance.
  @param[in] VirtualAddress  The virtual address supplied when the mapping was created.
  @param[in] Length          The length supplied when the mapping was created.

  @retval EFI_SUCCESS            The mapping was removed.
  @retval EFI_INVALID_PARAMETER  A parameter is invalid.
  @retval EFI_NOT_FOUND          No matching aliased mapping is recorded.
**/
typedef
EFI_STATUS
(EFIAPI *UNMAP_ALIASED_MAPPING)(
  IN CONST ALIASED_MEMORY_MAPPING_PROTOCOL  *This,
  IN EFI_VIRTUAL_ADDRESS                    VirtualAddress,
  IN UINT64                                 Length
  );

struct _ALIASED_MEMORY_MAPPING_PROTOCOL {
  CREATE_ALIASED_MAPPING    CreateAliasedMapping;
  UNMAP_ALIASED_MAPPING     UnmapAliasedMapping;
};

extern EFI_GUID  gAliasedMemoryMappingProtocolGuid;

#endif
