# Zero crossing triac controller Arduino Shield

An arduino shield that makes it easy to detect [zero crossings](http://en.wikipedia.org/wiki/Zero_cross_circuit) on mains AC, and control a triac with [phase control](http://playground.arduino.cc/Main/ACPhaseControl)

# Circuit board

* [Schematic](schematic.png)
* Eagle schematic/board in the repo
* order boards from [oshpark](http://oshpark.com/shared_projects/XGqh7Sy8)

# Todo

* opto is wrong way round (on silkscreen) as output is in the live side and input on the logic side.
* cap input is only up to 16v or so, not 240
* spaces for most R are too narrow
* add a cap on the zc input, got a bit of triac switching noise on it

# BOM

The [BOM](bom.txt) is in tab separated form, with Farnell part numbers. Missing parts are standard, or don't matter:

* Diodes are forming a low current bridge rectifier
* Caps - follow voltage and polarisation.
* Reistors - power rating 1/8W unless specified.

# Useful resources

I made use of the following in the design.

## Spindle controller

Thanks to Klaas for a great write up on a [cnc router controller](https://sites.google.com/site/klaasdc/cnc-router/spindle-controller) of which this project is mostly a copy of.

## Triac Block

Thanks to Mic at [wemakethings.net](http://wemakethings.net) for his work on the Triac Bloc:

* [git repo](https://github.com/Miceuz/triac-bloc)
* [pdf schematic](https://github.com/Miceuz/triac-bloc/blob/master/ssr.pdf)

## Triac controller datasheet

* This [opto isolated triac controller](http://www.farnell.com/datasheets/1806097.pdf) datasheet has a useful circuit for controlling triac including snubber circuit.

## Zero crossing circuit

* [Zero crossing circuit](http://www.dextrel.net/diyzerocrosser.htm)

If I do a second version I'll reduce part count by using an [AC input opto coupler](http://www.vishay.com/docs/83608/h11aa1.pdf) for the zero crossing sensor.

# License

This hardware is licensed under the [CERN open hardware license 1.2](http://www.ohwr.org/attachments/2388/cern_ohl_v_1_2.txt), which also included in this repository.
