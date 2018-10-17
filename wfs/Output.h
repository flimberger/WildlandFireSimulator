#ifndef FIREMAP_H
#define FIREMAP_H

#include "../cell.h"
#include "../fire.h"
#include "../globals.h"

namespace wildland_firesim {
namespace wfs {

/*!
 * \brief The FireMap class
 * contains function to define the output of the model.
 */
class Output
{
public:
    /*!
     * \brief writeBurnMapToASCII
     * Function to write cell states into an ascii-grid.
     * \param landscape
     * \param fileName
     */
    static void writeBurnMapToASCII(LandscapeInterface &landscape, std::string fileName);
    /*!
     * \brief writeVegetationMapToASCII
     * Function to write vegetation types into an ascii-grid.
     * \param landscape
     * \param fileName
     */
    static void writeVegetationMapToASCII(LandscapeInterface &landscape, std::string fileName);
    /*!
     * \brief writeVegetationDataToCSV
     * Function to write vegetation parameters into a csv-Table
     * \param landscape
     * \param fileName
     */
    static void writeVegetationDataToCSV(LandscapeInterface &landscape, std::string fileName);
    /*!
     * \brief writeFireWeatherDataToCSV
     * Function to write weather data into a csv-Table
     * \param landscape
     * \param fileName
     */
    void writeFireWeatherDataToCSV(std::string fileName);

    /*!
     * \brief writeBurnDataToCSV
     * \param landscape
     * \param fileName
     */
    static void writeBurnDataToCSV(LandscapeInterface &landscape, Fire &fire, std::string fileName);
    /*!
     * \brief setfileName
     * Function to generate file names.
     * \param baseName
     * \param extention
     * \param i
     * \return
     */
    static std::string fileName(std::string baseName, std::string extention, int i);
    /*!
     * \brief storeWeatherData
     * Function to extract weather data at a certain time.
     * \param weather
     * \param durationOfBurn
     */
    void storeWeatherData(const FireWeatherVariables &weather, float durationOfBurn);

    /*!
     * \brief clearWeatherData
     * Deletes all aggregated weather data from this object.
     */
    void clearWeatherData();

private:
    std::vector<std::string> weatherData;
};

} // namespace wfs
} // namespace wildland_firesim

#endif // FIREMAP_H
