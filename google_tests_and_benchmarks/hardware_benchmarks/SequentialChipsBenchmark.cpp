#include "HardwareBenchmarkManager.hpp"
#include "src/hardware/SequentialChips.hpp"


#ifdef REGISTER_BM_SEQUENTIALCHIPS
    SEQUENTIALCHIP_BENCHMARK(_dff,              _dff,               (0,0)           )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_bit,              _bitread,           .read()         )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_bit,              _bitwrite,          .write(0)       )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_register32,       _register32read,    .read()         )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_register32,       _register32write,   .write(0)       )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_RAM<     8>,      _RAM8read,          .read(0)        )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_RAM<     8>,      _RAM8write,         .write(0,0)     )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_RAM<    64>,      _RAM64read,         .read(0)        )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_RAM<    64>,      _RAM64write,        .write(0,0)     )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_RAM<   512>,      _RAM512read,        .read(0)        )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_RAM<   512>,      _RAM512write,       .write(0,0)     )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_RAM< 4'096>,      _RAM4096read,       .read(0)        )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_RAM< 4'096>,      _RAM4096write,      .write(0,0)     )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_RAM<32'768>,      _RAM32768read,      .read(0)        )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_RAM<32'768>,      _RAM32768write,     .write(0,0)     )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_counter32,        _counter32,         (0,0,0,0)       )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_counter32,        _counter32read,     .read()         )->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
#endif