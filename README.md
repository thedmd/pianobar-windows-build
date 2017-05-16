pianobar for Windows - build environment
========

[![Build status](https://ci.appveyor.com/api/projects/status/yimv2fbp5m1stagi/branch/master?svg=true)](https://ci.appveyor.com/project/thedmd/pianobar-windows-build/branch/master)

*Binaries* in the form of *standalone* executable ara available at:
[pianobar-windows-binaries](https://github.com/thedmd/pianobar-windows-binaries)

pianobar is a console client for the personalized web radio pandora
(http://www.pandora.com). Source code of the original project can be found at
at [github.com](http://github.com/PromyLOPh/pianobar/) or [6xq.net](http://6xq.net/projects/pianobar/)

This project is a build environment for pianobar port for Windows. Port source
code is at [pianobar-windows](https://github.com/thedmd/pianobar-windows/) repository.

Solution files for Microsoft Visual Studio 2015 are available and allow building
pianobar in clean environment.

Source code of included libraries:
  - libcurl
  - json-c
  - vtparse - modified VT parser, UTF8 support was added
  - blowfish - modified Paul Kocher sources ([www.schneier.com](http://www.schneier.com/blowfish-download.html))

