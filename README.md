# YSASA

YSASA is a tool to calculate the [solvent-accessible surface area (SASA)](https://en.wikipedia.org/wiki/Accessible_surface_area).

YSASA uses the Shrake-Rupley algorithm with a virtual "roll ball" as probe, SASA can be calculated quickly, and a protein surface dot file can be created optionally.

## Dependencies

* C++11 compiler, such as GCC 4.8+
* boost
* Eigen, 3.0+
* PDBToolsCpp, clone this repository with the following command:

``` Bash
git clone https://github.com/yingyulou/PDBToolsCpp.git
```

## Installation

To compile YSASA, make sure the location is in the YSASA/ directory and simply run the following commands:

``` Bash
cd src
make
```

The executable file "YSASA" will be created in YSASA/bin/YSASA.

In addition, "make debug" is used to compile with the debug mode: 

``` Bash
cd src
make debug
```

Use "make clean" to remove the installation:

``` Bash
cd src
make clean
```

## Testing

To test the installation, make sure the location is in the YSASA/ directory and simply run the following commands:

``` Bash
cd test
sh test.sh
```

Then the test result file: "test_result.txt" and "test_dot.pdb" will be created.

## Getting Help

Command "YSASA -h" or "YSASA --help" is used to get the help information:

```
  -h [ --help ]         show this help message and exit
  -i arg                Input PDB File Path (Required)
  -p arg (=0)           Probe R, Default = 0. (VDW Surface)
  -c arg (=60)          Dot Count, Default = 60
  -o arg                Output Result File Path
  -d arg                Output Dot File Path
```

## Parameters

### 1. -i, required

The path of PDB file to calculate the SASA.

### 2. -p, optional, default = 0.

Radius of the virtual roll ball.

If the radius is 0, which represents the van der Waals surface.

Radius is typically set to 1.4, which approximates the radius of a water molecule.

### 3. -c, optional, default = 60

Number of dots on the surface of the roll ball.

Actually, this parameter will be used to create a file path like "/.../YSASA/data/xxx.xyz" where "xxx" is the value of the parameter. Therefore, the "-c" is typically set to 10~400 or other higher value in YSASA/data such as 812, 912 and so on. If this parameter gives a nonexistent file, program will exit and an error message will be shown to explain this situation.

The value of this parameter is positively correlated with the accuracy, but it needs to spend a little time.
 
All the original ".xyz" files are from the following database and have been processed by some scripts (so these files will not be as same as which downloaded from the webside):

[http://www-wales.ch.cam.ac.uk/~wales/CCD/Thomson/table.html](http://www-wales.ch.cam.ac.uk/~wales/CCD/Thomson/table.html)

This database gives lots of solutions of the [Thomson Problem](https://en.wikipedia.org/wiki/Thomson_problem).

### 4. -o, optional

Result file path (typically is a ".txt" file).

The "result file" has only one line, such as

```
SASA: xxx (A^2)
```

The SASA value of input file will be given by the result file.

(The result file will be created unless this parameter is not given)

### 5. -d, optional

Result dot file path (must be the ".pdb" format).

The "dot file" is a PDB file to represent the surface dot distribution of the input file.

(The result file will be created unless this parameter is not given)
