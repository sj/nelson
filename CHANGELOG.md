# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## 0.6.5 (2022-05-26)

### Added

- [#572](http://github.com/Nelson-numerical-software/nelson/issues/572): `pow2`: Base 2 exponentiation.

- `audioread`, `audiowrite` supports new file formats `.mp3`, `.flac`, `.caf` (Thanks to libsndfile).

- MacOs 12 Monterey Github CI.

- [#634](http://github.com/Nelson-numerical-software/nelson/issues/634): Ubuntu 22.04 CI.

### Changed

- [#631](http://github.com/Nelson-numerical-software/nelson/issues/631): Qt6 used as default distribution on some OS platforms.

  For backport compatibility only Qt5.15.x and Qt6.3 (or more) are supported.

  - Windows 64 bits: Qt6.3
  - Windows 32 bits: Qt5.15.x
  - Ubuntu 22.04: Qt6.3
  - Ubuntu 20.04, 18.04: Qt5.15.x
  - MacOs Monterey: Qt6.3
  - MacOs BigSur, Catalina: Qt5.15.x
  - Others OS platforms: Qt version based on distributed Qt version.

- [#636](http://github.com/Nelson-numerical-software/nelson/issues/636): docker image uses bullseye image.

- `system` builtin: multithread rework.

- [#633](http://github.com/Nelson-numerical-software/nelson/issues/633): libsndfile 1.1.0 used.

- Windows build uses `/permissive-` option.

- [#646](http://github.com/Nelson-numerical-software/nelson/issues/646): `warndlg`, `questdlg`, `errordlg`, `helpdlg` reworked to better Qt6 support.

### Fixed

- Dark theme detection with Gnome.

- [#642](http://github.com/Nelson-numerical-software/nelson/issues/642): `rand` was not thread safe.

- [#648](http://github.com/Nelson-numerical-software/nelson/issues/648): Ubuntu 18.04 CI failed.

- [#651](http://github.com/Nelson-numerical-software/nelson/issues/651): MacOs monterey crashs at exit with mpi module.

## 0.6.4 (2022-04-24)

### Changed

- [#590](http://github.com/Nelson-numerical-software/nelson/issues/590): Nelson's license moved to LGPL v3.0 and GPL v3.0 and uses SPDX format.

- Nelson uses [Hack](https://sourcefoundry.org/hack/) font.

- Linux 64 bits and 32 bits uses same main script.

- [#594](http://github.com/Nelson-numerical-software/nelson/issues/594): `.pot` used to generate en_US.

### Added

- 'sscanf' reworked to manage unicode characters and speed optimization.

- French translations imported from Weblate (Thanks to contributors)

- Dark theme detected and applied on Linux, MacOS and Windows.

- [#559](http://github.com/Nelson-numerical-software/nelson/issues/559): `formattedDisplayText` function: Capture display output as string.

- Better detection Qt6 or Qt5 with CMake.

### Fixed

- Main Nelson's font was not applied on some OS platforms (ex: MacOS Catalina)

- [#622](http://github.com/Nelson-numerical-software/nelson/issues/622): `isreal(sqrt(i^4))` did not return true.

- Nelson's help indexing is faster (x100).

## 0.6.3 (2022-03-26)

### Changed

- [#596](http://github.com/Nelson-numerical-software/nelson/issues/596): Tests results display use emoji if terminal supports Unicode.

### Added

- Packaging:

  - [#603](http://github.com/Nelson-numerical-software/nelson/issues/603): Nelson as snap package for Linux.
  - [#605](http://github.com/Nelson-numerical-software/nelson/issues/605): [Package request] Chocolatey package manager for Windows.
  - [#582](http://github.com/Nelson-numerical-software/nelson/issues/582): Nelson available as Portable apps.

- add information for Software Center (Linux desktop, icons).

- `nelson` Main script to start Nelson (superceed others scripts).

- `isunicodesupported` function: Detect whether the current terminal supports Unicode.

- `dlsym` function: search nearest symbol name if value entry is not found.

- `terminal_size` function:Query the size of the terminal window.

- [#598](http://github.com/Nelson-numerical-software/nelson/issues/598): `sscanf` function read formatted data from strings.

### Fixed

- [#599](http://github.com/Nelson-numerical-software/nelson/issues/599): `make install` step in CI for linux and MacOs.

- [#601](http://github.com/Nelson-numerical-software/nelson/issues/601): embed all tests on linux and macos install.

## 0.6.2 (2022-02-26)

### Changed

- [#576](http://github.com/Nelson-numerical-software/nelson/issues/576): C++17 Compiler required to build Nelson.

- [#581](http://github.com/Nelson-numerical-software/nelson/issues/581): Github CI platforms list extended (ArchLinux, Fedora, Ubuntu 18.04, MacOs BigSur).

- [#539](http://github.com/Nelson-numerical-software/nelson/issues/539): Visual studio 2022 build on Windows

  - Visual studio 2022 solution upgraded,
  - Github CI and Appveyor use VS 2022 image,
  - boost 1.78 (VS 2022 x86, x64 build),
  - Eigen 3.4 stable branch (Feb 06/22),
  - MSVC 2022 support added to build C/C++ code easily "on fly" on Windows,
  - slicot 5.0 (VS 2022 x86, x64 build),
  - libffi (VS 2022 x86, x64 build),
  - taglib 1.12 (VS 2022 x86, x64 build),
  - hdf5 1.12.1 (VS 2022 x86, x64 build),
  - matio 1.5.21 (VS 2022 x86, x64 build),
  - all others windows dependencies rebuilt with VS 2022.
  - [#505](http://github.com/Nelson-numerical-software/nelson/issues/505): libCurl 7.81 on Windows.
  - [#524](http://github.com/Nelson-numerical-software/nelson/issues/524): oneApi 2022.1 on Windows.

### Added

- Nelson uses `JuliaMono-Regular` font as default.
- [#567](http://github.com/Nelson-numerical-software/nelson/issues/567): `...` in cells if character vector is too long.

### Fixed

- [#587](http://github.com/Nelson-numerical-software/nelson/issues/587): implicit cast to string array for horzcat and vertcat operators.
- [#562](http://github.com/Nelson-numerical-software/nelson/issues/562): `format long` complex do not display expected precision.
- scale factor for integer values did not display as expected.
- [#561](http://github.com/Nelson-numerical-software/nelson/issues/561): `0^0` did not return expected value.
- [#560](http://github.com/Nelson-numerical-software/nelson/issues/560): many warnings fixed (Thanks to new PVS-Studio and cppcheck).
- cmake `WITH_SLICOT`, `WITH_FFTW`, `ENABLE_CLANG_TIDY_FIX` were not documented.
- [#584](http://github.com/Nelson-numerical-software/nelson/issues/584): docker files updated to support C++17 and new libraries.
- [#591](http://github.com/Nelson-numerical-software/nelson/issues/591): Innosetup display glitch with `Nelson's website` button.

## 0.6.1 (2022-01-31)

### Changed

- display of all types reworked to be `pixel perfect`. (a small sentence but a big rework)

### Added

- `format` extended to manage: `compact`, `loose`, `longE`, `longG`, `hex`, `bank`, `rational`.
- [#507](http://github.com/Nelson-numerical-software/nelson/issues/507): `celldisp`: Display cell array contents.
- [#548](http://github.com/Nelson-numerical-software/nelson/issues/548): `hypot` builtin: Square root of sum of squares.
- [#555](http://github.com/Nelson-numerical-software/nelson/issues/555): `rsf2csf` function: Convert real Schur form to complex Schur form.
- `CHANGELOG` 0.6.x family.

## Previous changelog

[Changelog v0.5.x](CHANGELOG-0.5.x.md)

[Changelog v0.4.x](CHANGELOG-0.4.x.md)

[Changelog v0.3.x](CHANGELOG-0.3.x.md)

[Changelog v0.2.x](CHANGELOG-0.2.x.md)

[Changelog v0.1.x](CHANGELOG-0.1.x.md)
