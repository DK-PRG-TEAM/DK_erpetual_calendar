[English](README.md) · **简体中文**

> 英文版是规范版本。本页与 [README.md](README.md) 不一致时，以英文版为准。

<!-- translation-of: README.md sha256:69032a6067000445 -->

<!-- Source: Best-README-Template BLANK_README (Unlicense) — https://github.com/othneildrew/Best-README-Template -->
<a id="readme-top"></a>

# DK Erpetual Calendar

一个 C++ 命令行程序，使用蔡勒公式计算星期几，并打印 2020 年的演示日历。

[![CI](https://github.com/DK-PRG-TEAM/DK_erpetual_calendar/actions/workflows/ci.yml/badge.svg)](https://github.com/DK-PRG-TEAM/DK_erpetual_calendar/actions/workflows/ci.yml)
[![License](https://img.shields.io/github/license/DK-PRG-TEAM/DK_erpetual_calendar)](LICENSE)

[报告问题](https://github.com/DK-PRG-TEAM/DK_erpetual_calendar/issues/new?template=bug_report.yml) · [提出需求](https://github.com/DK-PRG-TEAM/DK_erpetual_calendar/issues/new?template=feature_request.yml)

<details>
  <summary>目录</summary>
  <ol>
    <li><a href="#about-the-project">关于本项目</a></li>
    <li><a href="#getting-started">开始使用</a></li>
    <li><a href="#usage">用法</a></li>
    <li><a href="#contributing">参与贡献</a></li>
    <li><a href="#license">许可证</a></li>
    <li><a href="#contact">联系方式</a></li>
  </ol>
</details>

## 关于本项目

DK Erpetual Calendar 是一个小型的 C++20 控制台程序，使用蔡勒公式（Zeller's congruence）
计算给定日期是星期几，再用同一个公式逐月打印一整年的日历（`src/Main/src/main.cpp`）。
它打印时用到的每月天数和星期标签，来自 `src/Consts/include/consts.h` 中的查找表，其中
也包含了控制二月天数的闰年表。

计划中的功能与已知问题，见 [open issues](https://github.com/DK-PRG-TEAM/DK_erpetual_calendar/issues)。

## 开始使用

### 环境要求

- CMake 3.17 或更高版本（`CMakeLists.txt`：`cmake_minimum_required(VERSION 3.17)`）
- 支持 C++20 的编译器，例如 GCC 或 Clang
- Git，用于克隆本仓库

### 安装

```sh
git clone https://github.com/DK-PRG-TEAM/DK_erpetual_calendar.git
cd DK_erpetual_calendar
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## 用法

```sh
./build/src/Main/DK_erpetual_calendar
```

该程序不接受任何参数：`main()`（`src/Main/src/main.cpp`）每次都运行同一套固定的演示，
先计算 2020-05-03 是星期几，然后逐月打印完整的 2020 年日历。输出中的部分月份和星期标签
使用了非 UTF-8 的源码编码保存，因此在你的终端语言环境下，这部分文字可能显示为乱码。

## 参与贡献

欢迎参与。[CONTRIBUTING.md](CONTRIBUTING.md) 说明如何提交 issue 或 pull request，[CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md) 说明对所有参与者的行为要求。

请不要在公开的 issue 或 pull request 中报告安全问题。[SECURITY.md](SECURITY.md) 说明了私下报告的方式。

## 许可证

以 MIT 许可证分发。详见 [LICENSE](LICENSE)。

## 联系方式

项目地址：[https://github.com/DK-PRG-TEAM/DK_erpetual_calendar](https://github.com/DK-PRG-TEAM/DK_erpetual_calendar)

<p align="right">(<a href="#readme-top">back to top</a>)</p>
