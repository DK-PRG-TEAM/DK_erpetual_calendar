<!-- Source: Best-README-Template BLANK_README (Unlicense) — https://github.com/othneildrew/Best-README-Template -->
<a id="readme-top"></a>

# DK Erpetual Calendar

A C++ command-line program that computes the day of the week with Zeller's congruence and prints a demonstration calendar for the year 2020.

**English** · [简体中文](README.zh-CN.md)

[![CI](https://github.com/DK-PRG-TEAM/DK_erpetual_calendar/actions/workflows/ci.yml/badge.svg)](https://github.com/DK-PRG-TEAM/DK_erpetual_calendar/actions/workflows/ci.yml)
[![License](https://img.shields.io/github/license/DK-PRG-TEAM/DK_erpetual_calendar)](LICENSE)

[Report a bug](https://github.com/DK-PRG-TEAM/DK_erpetual_calendar/issues/new?template=bug_report.yml) · [Request a feature](https://github.com/DK-PRG-TEAM/DK_erpetual_calendar/issues/new?template=feature_request.yml)

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li><a href="#getting-started">Getting Started</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

## About The Project

DK Erpetual Calendar is a small C++20 console program that finds the day of the week for a given date using Zeller's congruence, then reuses that same formula to print an entire year's calendar one month at a time (`src/Main/src/main.cpp`). The month lengths and weekday labels it prints come from lookup tables in `src/Consts/include/consts.h`, including the leap-year table that governs February.

See the [open issues](https://github.com/DK-PRG-TEAM/DK_erpetual_calendar/issues) for planned features and known issues.

## Getting Started

### Prerequisites

- CMake 3.17 or newer (`CMakeLists.txt`: `cmake_minimum_required(VERSION 3.17)`)
- A C++20-capable compiler, such as GCC or Clang
- Git, to clone the repository

### Installation

```sh
git clone https://github.com/DK-PRG-TEAM/DK_erpetual_calendar.git
cd DK_erpetual_calendar
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Usage

```sh
./build/src/Main/DK_erpetual_calendar
```

The program takes no arguments: `main()` (`src/Main/src/main.cpp`) always runs the same fixed demonstration, resolving the weekday for 2020-05-03 and then printing the full year 2020, one month at a time. A handful of month and weekday labels in that output are stored in a non-UTF-8 source encoding, so they can render as mojibake depending on your terminal's locale.

## Contributing

Contributions are welcome. Read [CONTRIBUTING.md](CONTRIBUTING.md) for how to open an issue or a pull request, and [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md) for the standards expected of everyone taking part.

Please do not report security issues in public issues or pull requests. [SECURITY.md](SECURITY.md) explains how to report them privately.

## License

Distributed under the MIT License. See [LICENSE](LICENSE) for details.

## Contact

Project link: [https://github.com/DK-PRG-TEAM/DK_erpetual_calendar](https://github.com/DK-PRG-TEAM/DK_erpetual_calendar)

<p align="right">(<a href="#readme-top">back to top</a>)</p>
