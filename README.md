# Scripter for Scribus built on pybind11

First bits of a new Scripter for [Scribus](https://scribus.net).

## Status

This new Scripter has just left the starting blocks.

Currently, I've only implemented the minimum for running:

```py
import scribus
import sys

try:
    doc = scribus.get_current_document()
    print(doc.get_name())
except:
    print("Unexpected error:", sys.exc_info()[0])

```

The basic structure is in place, now it's time to define the new API and implement it.

## A bit of history

The current Scribus Scripter is getting old and it cannot be ported to Python 3.

Many years ago there has been an effort to create a more modern Scripter (called the _Scripter 2_). I managed to port it to Python 3, but I failed to completely port it to PyQt5.  
It's a very clever approach – almost too clever... – but:

- it's hard to maintain,
- it's based on a library (_minikross_ aka `mikro.py`, that is not in use in any other project and has not been mantained for the last 10 years).
- a couple of years ago Krita tried to use it, but also failed.

## Goals

- Use `pybind11` for embedding Python in Scribus.
- Create a new API:
  - similar to what was going to happen with the defunct [Scripter2](https://scribus-scripter.readthedocs.io/en/latest/)
  - _object oriented_
  - that feels _pythonic_
- Allow UIs in PyQt5 / PySide2
- Old scripts will not run in the new Scripter.

We will use the Github issues in this repository for discussing the development of this Scripter.

## Install

Clone the `scribus-plugin-actionSearch` repository and put – or symlink – its `src` directory into `scribus/plugins/` as `scripter-pybind11`. Then add 

    ADD_SUBDIRECTORY(scripter-pybind11)

to the `CMakeLists.txt` file in `scribus/plugins/`.

In the plugins' `CMakeLists.txt`, disable the install of the other script engines, compile and do a fresh install.

## Run

The _Scripter_ menu entry has an _Execute script..._ command that lets you run Python scripts inside of Scribus.

## Todo

- [ ] Define the new API
- [ ] Document the translation from the old to the new API (also, for making sure that all the current commands are replicated)
- [ ] How to document the new API?

The tasks are tracked in the Github issues attached to this repository.
