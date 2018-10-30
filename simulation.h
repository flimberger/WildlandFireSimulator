#ifndef WILDLAND_FIRESIM_SIMULATION_H
#define WILDLAND_FIRESIM_SIMULATION_H

#include <iostream>
#include <string>
#include "utility.h"
#include "globals.h"
#include "WFS_landscape.h"
#include "WFS_fireweather.h"
#include "fire.h"
#include "WFS_output.h"

namespace wildland_firesim{
/*!
 * \brief The Simulation class
 * contains function to simulate fire within a landscape either with static weather conditions or a
 * weather simulation.
 */
class Simulation
{
public:
    Simulation();

    /*!
     * \brief runSimulation
     * runs the simulation and logs output data.
     * \param landscape
     * \param weather
     * \param output
     */
    void runSimulation(WFS_Landscape *landscape, const FireWeatherVariables &weather,
                       FireWeather weathersim, Output *output);

    void setTimestepLength(int timestepLength) { m_timestepLength = timestepLength; }

    void setMaxFireDuration(int maxFireDuration) { m_maxFireDuration = maxFireDuration; }

    int getNumberOfRuns() const noexcept { return m_numberOfRuns; }
    void setNumberOfRuns(int numberOfRuns) { m_numberOfRuns = numberOfRuns; }

    void setIgniteCentralVertex(bool igniteCentralVertex) {
        m_igniteCentralVertex = igniteCentralVertex;
    }

    bool getSimulateFireWeather() const noexcept { return m_simulateFireWeather; }
    void setSimulateFireWeather(bool simulateFireWeather) {
        m_simulateFireWeather = simulateFireWeather;
    }

    void setMonth(const std::string &month) {
        m_whichMonth = stringToMonth(month);
    }

    const Fire &getFire() const noexcept { return m_fire; }

private:
    static Month stringToMonth(const std::string &m);

    int m_numberOfRuns;
    int m_maxFireDuration;
    bool m_simulateFireWeather;
    bool m_igniteCentralVertex;
    Month m_whichMonth;

    int m_timestepLength;
    float m_timeScalingFactor;

    std::string m_nameOfMeteorologicalParameterFile;

    Fire m_fire;
};

}  // namespace wildland_firesim
#endif // WILDLAND_FIRESIM_SIMULATION_H
