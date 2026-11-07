# Mario Kart DS decompilation

A matching decompilation of *Mario Kart DS* for the Nintendo DS. The C in this repository is written with AI
assistance so that, built with the original compiler, it reproduces the game's code byte for byte.

**No game content is included.** The repository holds no ROM, no assets and no disassembly. To build, you need your
own dump of the game; see [INSTALL.md](INSTALL.md).

| Version | Game code | SHA-1 |
| --- | --- | --- |
| USA | `AMCE` | `691e00d9a5dd80b04f80cc7559503e8b06848785` |
| Europe | `AMCP` | `ce97d9b43f0d3ca0d48b781983e8a16f6393378f` |

Every function is decompiled from the game's own code. Code from other decompilations is not accepted.

## Progress
Each version's section is recorded from a build of that version (`python3 tools/configure.py <ver>`):
`ninja report && python3 tools/progress.py update`.

### USA
<!-- progress:usa:start -->
![USA: function bytes by module](progress/usa/treemap.svg)

| Measure | Progress |
|---|---|
| Matched code | 99.83% (1,882,946 / 1,886,100 bytes) |
| Linked code (complete units) | 99.36% (1,874,106 bytes) |
| Overall accuracy (fuzzy) | 99.83% |
| Matched functions | 11,498 / 11,498 |

_Last updated 2026-11-07. Over time: [graph](progress/usa/progress.svg), [`progress/usa/history.csv`](progress/usa/history.csv)._
<!-- progress:usa:end -->

### Europe
<!-- progress:eur:start -->
![Europe: function bytes by module](progress/eur/treemap.svg)

| Measure | Progress |
|---|---|
| Matched code | 51.12% (964,162 / 1,886,120 bytes) |
| Linked code (complete units) | 3.16% (59,640 bytes) |
| Overall accuracy (fuzzy) | 59.20% |
| Matched functions | 7,422 / 11,497 |

_Last updated 2026-10-29. Over time: [graph](progress/eur/progress.svg), [`progress/eur/history.csv`](progress/eur/history.csv)._
<!-- progress:eur:end -->

## Documentation
- [INSTALL.md](INSTALL.md): setting up and building
- [CONTRIBUTING.md](CONTRIBUTING.md): repository layout, naming and workflow
- [docs/compiler.md](docs/compiler.md): how the compiler and flags were identified
- [docs/decompiling.md](docs/decompiling.md): source patterns that matter for matching
- [docs/versions.md](docs/versions.md): shared-source validation on Europe

Built with [ds-decomp](https://github.com/AetiasHax/ds-decomp), Metrowerks CodeWarrior for DS run through
[wibo](https://github.com/decompals/wibo), and [objdiff](https://github.com/encounter/objdiff).
