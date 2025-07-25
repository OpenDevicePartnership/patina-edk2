# Patina Package

This package is an optional, supplementary collection of definitions and helper utilities designed for EDK II-style C
firmware projects that integrate [Patina](https://github.com/OpenDevicePartnership/patina).

It is important to note that this package is not required to build or use Patina. Rather, it is provided to support the
convenience and standardization of Patina-authored content that may be utilized within C codebases.

## Repo Scope and Dependencies

First and foremost, Patina is a Rust project. This section is intended to clarify the scope and dependencies of
`patina-edk2`, to ensure that it is used correctly and does not conflict with other Patina repositories.

1. **Single Repository** - All Patina content that is intended to be consumed by EDK II style C code must reside this
   repository.
2. **Proper Scope** - The `patina-edk2` repository should only contain Patina definitions that are intended to be
   consumed by EDK II style C code. It may contain minimal helper functionality.
   - This includes Patina-specific HOBs, GUIDs, and other content that is not intended to be used by Rust code.
   - The repository should not contain any Rust code or Patina crates.
3. **Proper Classification** - The `patina-edk2` repository should rarely be used within Patina work. Patina is not
   meant to establish a large set of C-specific content that is not already defined in specifications and made available
   through existing means. However, Patina will define some new content that is not defined in specifications and may
   be made available for use in EDK II style C code. In that case, this repository is the proper place to put a single
   officially maintained copy of that content.
4. **Minimal Dependencies** - The repository is not allowed to depend on any content other than `MdePkg` and
   `MdeModulePkg` from upstream `edk2`. Any other dependency to an `edk2` package must be requested via RFC.
   Dependencies on projects other than `edk2` are not allowed.
5. **No Dependencies From Patina** - No other Patina repository can depend on content in this repository. No other
   Patina repository documentation should reference details in this repository. The repository should be able to be
   removed from the Patina project at any time without impacting any other Patina repository.

## Build Instructions

This repository uses the Stuart build system that is part of the Tianocore project to build. More information about
stuart can be found in its source repositories at:

- [How to Build with Stuart](https://github.com/tianocore/tianocore.github.io/wiki/How-to-Build-With-Stuart)
- [Using Stuart](https://www.tianocore.org/edk2-pytool-extensions/using/install/)
- [EDK II Pytool Extensions](https://github.com/tianocore/edk2-pytool-extensions)
- [EDK II Pytool Library](https://github.com/tianocore/edk2-pytool-library)

The simple instructions to build this repository are (Windows example):

```bash
> py -3 -m venv venv
> .\venv\Scripts\activate
> pip install -r requirements.txt --upgrade
> stuart_ci_setup -c .\.pytool\CISettings.py
> stuart_update -c .\.pytool\CISettings.py
> stuart_ci_build -c .\.pytool\CISettings.py
```

Consult [How to Build with Stuart](https://github.com/tianocore/tianocore.github.io/wiki/How-to-Build-With-Stuart) for
more detailed usage on ways to modify these commands.
