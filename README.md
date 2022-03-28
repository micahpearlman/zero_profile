# Zero Profile

## Overview

A simple C++ header only profiling tool.

## Usage

Let zero profile automatically manage the number of iterations and execution by wrapping the code to execute in a lambda:

```
    // have zero profile execute the code 10 times while managing the begine and end
    zero_profile::profile p("example1_1", 10);
    p([&]() { std::this_thread::sleep_for(std::chrono::milliseconds(13)); });
    p.report();
```

Manage the begin and end of profiling manually:

```
    // manually set the begin and end
    zero_profile::profile p2("example1_2", 1);
    p2.begin();
    std::this_thread::sleep_for(std::chrono::milliseconds(13));
    p2.end();
    p2.report();
```

Example report:

```
:: example1_1 ::
        call count: 1000
        average time milliseconds: 13.10741
        min time milliseconds: 13.01200 at iteration: 999
        max time milliseconds: 14.66000 at iteration: 700
:: example1_2 ::
        call count: 100
        average time milliseconds: 13.09302
        min time milliseconds: 13.05600 at iteration: 61
        max time milliseconds: 13.34800 at iteration: 47

```        