#pragma once
// List of tunable runtime parameters (only from DynamicConfig)
enum class DynamicParameterKey
{
    Direction,
    Log,
    LogAccel,
    LogPreproc,
    Model,
    PrintDependencyGraph,
    BlockingClauses,
    TRP_MbpKind,
    TRP_RecurrentCycles,
    TRP_RecurrentExps,
    TRP_RecurrentPseudoDivs,
    TRP_RecurrentPseudoBounds,
    TRP_RecurrentBounds
};
