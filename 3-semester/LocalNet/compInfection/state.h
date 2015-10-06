#pragma once

/**
 * @brief The State class
 */


class State
{
public:
    State() : state(Healthy)
    {}
    enum HealthState
    {
        Healthy = 1,
        JustInfected,
        Infected
    };
protected:
    HealthState state;
};
