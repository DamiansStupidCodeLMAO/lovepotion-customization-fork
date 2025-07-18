# LÖVE Potion

A port of [LÖVE](https://love2d.org) for Nintendo Homebrew. This is not my project. I am using a fork of this project to customize metadata.

## Why?

Thanks to some jank related to the Wii U, only some of the latest commits of LÖVE Potion are fully functional. 

This is not the fault of the developer at all, in fact I find her work on this project fantastic. The fact this even exists for Wii U is amazing. Thank you for feeding my hyperfixations, [TurtleP](https://github.com/TurtleP) (and other contributors).

Anyway, with that aside, why the hell does this fork exist? Can't I just use [the bundler](https://bundle.lovebrew.org/) to add metadata?

Unfortunately, given the fact that the latest builds are pretty much all I can use right now, the bundler won't work, as it relies instead on the latest release (3.0.1). So, to add metadata, I'm modifying the source directly. This is a fairly quick and easy method to get things working. From there, I can use the [manual fusing method](https://lovebrew.org/getting-started/get-lovepotion#manual-fusing) instead to add my own code.

TL;DR: Wii U jank. Need latest builds. Can't easily bundle latest builds. Add custom metadata via source code instead. Yippee!

## Help and Support

[![Discord Shield](https://discordapp.com/api/guilds/215551912823619584/widget.png?style=shield)](https://discord.gg/ggbKkhc)

## Acknowledgements

- [devkitPro](https://github.com/devkitPro)
  - devkitARM and libctru
  - devkitPPC and wut
  - devkitA64 and libnx
  - Various portlibs for the consoles

- [piepie](https://github.com/piepie62)
  - Various C++ components

- [fincs](https://github.com/fincs)
  - citro2d, citro3d, and deko3d

- [mtheall](https://github.com/mtheall)
  - Initial debugging with Switch font rendering

- [LÖVE's Developers](https://github.com/love2d/love)
  - Code is referenced and used in this project

- [videah](https://github.com/videah)
  - Original author of LÖVE Potion
