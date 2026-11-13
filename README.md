# Waste collection route planner (C++)

A command-line tool that plans a rubbish-collection round for a small road network. It builds three candidate routes, shows the cost, distance and number of bins emptied for each, and saves the one you pick to a text file.

Written in C++17 for a university module, using Dijkstra's and Floyd–Warshall shortest-path algorithms on a weighted graph.

## The three strategies

The depot is **A**. Each run generates random waste levels (0–99%) for the other nine locations, then compares:

| # | Strategy | Collects from | How the route is chosen |
|---|----------|---------------|--------------------------|
| 1 | Fixed route | locations ≥ 40% full | A hard-coded loop around the map (34 km), skipping bins that are not full enough |
| 2 | Budgeted search | locations ≥ 60% full | Floyd–Warshall distances plus a backtracking search for the route that empties the **most bins within a 20 km budget**, shortest first on ties |
| 3 | Greedy | locations ≥ 10% full | Repeatedly runs Dijkstra and drives to the nearest bin that needs emptying, then returns to the depot |

Cost model: fuel RM2.5 per km, plus labour at RM10 per time unit, where time = 3 × distance + 20 per bin emptied.

## Example run

```
Waste Levels:
B: 79%  C: 8%  D: 55%  E: 75%  F: 92%  G: 90%  H: 36%  I: 74%  J: 59%

Non-Optimised Route(1):
||A||-->C-->|D|-->|B|-->D-->|F|-->H-->|G|-->|J|-->|I|-->|E|-->||A||
Total Costs: RM2505   Distance: 34KM   Garbage Locations Emptied Up: 7

Optimised Route(2):
||A||-->|F|-->A-->|E|-->A-->|G|-->||A||
Total Costs: RM1185   Distance: 18KM   Garbage Locations Emptied Up: 3

Greedy Route(3):
||A||-->|F|-->|D|-->|B|-->D-->|H|-->|G|-->|J|-->|I|-->|E|-->||A||
Total Costs: RM2607.5   Distance: 31KM   Garbage Locations Emptied Up: 8
```

`|X|` marks a bin that is emptied and a bare letter is a location driven through. The chosen route is written to `textFiles/GL_Route.txt`.

## What the numbers look like

Over 300 random waste-level seeds on the bundled map:

| Strategy | Distance (km) | Bins emptied (mean) | Cost (mean) | Cost per bin (mean) |
|----------|---------------|---------------------|-------------|---------------------|
| Fixed route | 34 | 5.4 | RM2190 | RM426 |
| Budgeted search | 0–20 (mean 15.5) | 2.8 | RM1068 | RM388 |
| Greedy | 22–41 (mean 33.2) | 8.1 | RM2696 | RM335 |

These are not like-for-like, because each strategy uses a different waste threshold. The budgeted search is cheapest per run because it does less, not because it is better. Greedy is the cheapest per bin emptied. On all 300 seeds the budgeted search matched an independent brute-force check for the most bins within 20 km.

## Build and run

Needs a C++17 compiler and CMake 3.27 or newer.

```bash
cmake -S . -B build
cmake --build build
./build/GarbageAutomaticManagementSystem   # run from the project root
```

It must be run from the project root because it reads `textFiles/garbageLocations.txt` by relative path. It asks which route to save (1, 2 or 3).

## Changing the map

`textFiles/garbageLocations.txt` is a CSV edge list: a header line, then the number of locations, then one `u,v,weight` edge per line (location 0 is the depot, A). The map drawn on screen is hard-coded in `GarbageLocations.cpp` and `saveToFile.cpp`, so it will not update if you change the edges.

## Layout

```
src/                 C++ sources (one class per file)
Headers/             class declarations
textFiles/           map data (garbageLocations.txt) and the saved route
docs/sample_output.txt
```

## Limitations

- The map, thresholds, 20 km budget and cost constants are fixed in the source.
- The budgeted search checks routes recursively, so it only suits small numbers of bins.
- Waste levels are random with no seed option, so a run cannot be repeated exactly.
- The fixed route is a hard-coded baseline for this one map.
