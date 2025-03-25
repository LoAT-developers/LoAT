#pragma once
// List of tunable runtime parameters (only from DynamicConfig)
enum class DynamicParameterKey
{
    Log,
    LogAccel,
    LogPreproc,
    PrintDependencyGraph,
    BlockingClauses,
    TRP_RecurrentCycles,
    TRP_RecurrentExps,
    TRP_RecurrentPseudoDivs,
    TRP_RecurrentPseudoBounds,
    TRP_RecurrentBounds
};
