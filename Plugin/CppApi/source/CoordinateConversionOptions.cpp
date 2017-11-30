// Copyright 2017 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

#include "CoordinateConversionOptions.h"
#include "CoordinateConversionController.h"

namespace Esri
{
namespace ArcGISRuntime
{
namespace Toolkit
{

/*!
  \class Esri::ArcGISRuntime::Toolkit::CoordinateConversionOptions
  \ingroup ToolCoordinateConversion
  \inmodule ArcGISQtToolkit
  \brief Options for converting between geographic coordinate notations.
  \since Esri::ArcGISRuntime 100.2

  CoordinateConvertionsOptions define the various coordinate notation formats that this tool can convert between.
  Create one of these objects for each format you want your app to convert between. See
  \l CoordinateConversionController for details.

  \table
  \header
    \li Notations supported
    \li Format options (valid range)
  \row
    \li {1, 3} Latitude-longitude in degrees
    \li \l name
  \row
    \li \l latLonFormat
  \row
    \li \l decimalPlaces (0 to 16)
  \row
    \li GARS (Global Area Reference System)
    \li \l name
  \row
    \li {1, 2} GEOREF (World Geographic Reference System)
    \li \l name
  \row
    \li \l precision (0 to 9)
  \row
    \li {1, 4} MGRS (Military Grid Reference System)
    \li \l name
  \row
    \li \l mgrsConversionMode
  \row
    \li \l precision (0 to 8)
  \row
    \li \l addSpaces
  \row
    \li {1, 3} USNG (United States National Grid)
    \li \l name
  \row
    \li \l precision (0 to 8)
  \row
    \li \l addSpaces
  \row
    \li {1 ,3} UTM (Universal Transverse Mercator)
    \li \l name
  \row
    \li \l utmConversionMode
  \row
    \li \l addSpaces
  \endtable

  For more information see the API documentation for
  \l {http://../../../cpp/api-reference/esri-arcgisruntime-coordinateformatter.html} {CoordinateFormatter}.
 */

using MgrsConversionMode = CoordinateConversionOptions::MgrsConversionMode;
using LatitudeLongitudeFormat = CoordinateConversionOptions::LatitudeLongitudeFormat;
using UtmConversionMode = CoordinateConversionOptions::UtmConversionMode;

static const QString s_gars   = QStringLiteral("Gars");
static const QString s_georef = QStringLiteral("GeoRef");
static const QString s_latlon = QStringLiteral("LatLon");
static const QString s_mgrs   = QStringLiteral("Mgrs");
static const QString s_usng   = QStringLiteral("Usng");
static const QString s_utm    = QStringLiteral("Utm");

/*!
   \brief The constructor that accepts an optional \a parent object.
 */
CoordinateConversionOptions::CoordinateConversionOptions(QObject* parent):
  QObject(parent)
{
}

/*!
   \brief The destructor.
 */
CoordinateConversionOptions::~CoordinateConversionOptions()
{
}

/*!
  \property CoordinateConversionOptions::outputMode
  \brief The output coordinate notation type.

  The default value is \l {CoordinateType} {CoordinateTypeUsng}.
 */
CoordinateConversionOptions::CoordinateType CoordinateConversionOptions::outputMode() const
{
  return m_outputMode;
}

void CoordinateConversionOptions::setOutputMode(CoordinateType outputMode)
{
  m_outputMode = outputMode;
  emit outputModeChanged();
}

/*!
  \property CoordinateConversionOptions::name
  \brief The name used to identify this option, usually in the UI.
 */
QString CoordinateConversionOptions::name() const
{
  return m_name;
}

void CoordinateConversionOptions::setName(const QString& name)
{
  m_name = name;
  emit nameChanged();
}

/*!
  \property CoordinateConversionOptions::addSpaces
  \brief Whether the output notation format should use spaces.

  This option only applies to the Mgrs, Usng and Utm notation types.
 */
bool CoordinateConversionOptions::addSpaces() const
{
  return m_addSpaces;
}

void CoordinateConversionOptions::setAddSpaces(bool addSpaces)
{
  m_addSpaces = addSpaces;
  emit addSpacesChanged();
}

/*!
  \property CoordinateConversionOptions::precision
  \brief The precision for the notation type.

  \table
  \header
  \li Notation type
  \li Value range
  \li Default value
  \row
  \li GeoRef
  \li \c {0 to 9}
  \li \c 8
  \row
  \li MGRS
  \li \c {0 to 8}
  \li \c 8
  \row
  \li USNG
  \li \c {0 to 8}
  \li \c 8
  \endtable
 */
int CoordinateConversionOptions::precision() const
{
  return m_precision;
}

void CoordinateConversionOptions::setPrecision(int precision)
{
  m_precision = precision;
  emit precisionChanged();
}

/*!
  \property CoordinateConversionOptions::decimalPlaces
  \brief The number of decimal places used in the notation.

  This option only applies to the latitude / longitude notation type.
  Possible values are \c 0 to \c 16. The default value is \c 6.
 */
int CoordinateConversionOptions::decimalPlaces() const
{
  return m_decimalPlaces;
}

void CoordinateConversionOptions::setDecimalPlaces(int decimalPlaces)
{
  m_decimalPlaces = decimalPlaces;
  emit decimalPlacesChanged();
}

/*!
  \property CoordinateConversionOptions::mgrsConversionMode
  \brief The MGRS conversion mode.

  This option only applies to the MGRS notation. The default value is
  \l {MgrsConversionMode} {\c MgrsConversionModeAutomatic}.
 */
MgrsConversionMode CoordinateConversionOptions::mgrsConversionMode() const
{
  return m_mgrsConversionMode;
}

void CoordinateConversionOptions::setMgrsConversionMode(MgrsConversionMode mgrsConversionMode)
{
  m_mgrsConversionMode = mgrsConversionMode;
  emit mgrsConversionModeChanged();
}

/*!
  \property CoordinateConversionOptions::latLonFormat
  \brief The latitude / longitude notation format.

  This option only applies to the latitude / longitude notation.
  The default value is \l {LatitudeLongitudeFormat} {LatitudeLongitudeFormatDecimalDegrees}.
 */
LatitudeLongitudeFormat CoordinateConversionOptions::latLonFormat() const
{
  return m_latLonFormat;
}

void CoordinateConversionOptions::setLatLonFormat(LatitudeLongitudeFormat latLonFormat)
{
  m_latLonFormat = latLonFormat;
  emit latLonFormatChanged();
}

/*!
  \property CoordinateConversionOptions::utmConversionMode
  \brief The Utm conversion mode.

  This option only applies to the Utm format.
  The default value is \l {UtmConversionMode} {UtmConversionModeLatitudeBandIndicators}.
 */
UtmConversionMode CoordinateConversionOptions::utmConversionMode() const
{
  return m_utmConversionMode;
}

void CoordinateConversionOptions::setUtmConversionMode(UtmConversionMode utmConversionMode)
{
  m_utmConversionMode = utmConversionMode;
  emit utmConversionModeChanged();
}

/*!
  \internal
 */
void CoordinateConversionOptions::listAppend(QQmlListProperty<CoordinateConversionOptions>* property, CoordinateConversionOptions* value)
{
  static_cast<CoordinateConversionController*>(property->object)->addOption(value);
}

/*!
  \internal
 */
CoordinateConversionOptions* CoordinateConversionOptions::listAt(QQmlListProperty<CoordinateConversionOptions>* property, int index)
{
  return static_cast<QList<CoordinateConversionOptions*>*>(property->data)->value(index);
}

/*!
  \internal
 */
int CoordinateConversionOptions::listCount(QQmlListProperty<CoordinateConversionOptions>* property)
{
  return static_cast<QList<CoordinateConversionOptions*>*>(property->data)->count();
}

/*!
  \internal
 */
void CoordinateConversionOptions::listClear(QQmlListProperty<CoordinateConversionOptions>* property)
{
  static_cast<CoordinateConversionController*>(property->object)->clearOptions();
}

/*!
  \brief Returns the input string \a type converted to a \l CoordinateType enum value.
 */
CoordinateConversionOptions::CoordinateType CoordinateConversionOptions::stringToCoordinateType(const QString& type) const
{
  if (type == s_gars)
    return CoordinateType::CoordinateTypeGars;
  else if (type == s_georef)
    return CoordinateType::CoordinateTypeGeoRef;
  else if (type == s_latlon)
    return CoordinateType::CoordinateTypeLatLon;
  else if (type == s_mgrs)
    return CoordinateType::CoordinateTypeMgrs;
  else if (type == s_usng)
    return CoordinateType::CoordinateTypeUsng;
  else if (type == s_utm)
    return CoordinateType::CoordinateTypeUtm;

  return CoordinateType::CoordinateTypeLatLon;
}

/*!
  \brief Returns the \l CoordinateType enum value \a type converted to a string.
 */
QString CoordinateConversionOptions::coordinateTypeToString(CoordinateType type) const
{
  switch (type)
  {
  case CoordinateType::CoordinateTypeGars:
    return s_gars;
  case CoordinateType::CoordinateTypeGeoRef:
    return s_georef;
  case CoordinateType::CoordinateTypeLatLon:
    return s_latlon;
  case CoordinateType::CoordinateTypeMgrs:
    return s_mgrs;
  case CoordinateType::CoordinateTypeUsng:
    return s_usng;
  case CoordinateType::CoordinateTypeUtm:
    return s_utm;
  default: {}
  }

  return QString();
}

/*!
  \property CoordinateConversionOptions::coordinateTypeNames
  \brief A list of strings of the supported coordinate types.
 */
QStringList CoordinateConversionOptions::coordinateTypeNames() const
{
  return QStringList() << s_gars
                       << s_georef
                       << s_latlon
                       << s_mgrs
                       << s_usng
                       << s_utm;
}


// enums

/*!
  \enum CoordinateConversionOptions::CoordinateType
  \brief Enumeration of notation types supported for conversion.

  \value CoordinateTypeGars
         Global Area Reference System (GARS)

  \value CoordinateTypeGeoRef
         World Geographic Reference System (GEOREF)

  \value CoordinateTypeLatLon
         Latitude-longitude in degrees

  \value CoordinateTypeMgrs
         Military Grid Reference System (MGRS)

  \value CoordinateTypeUsng
         United States National Grid (USNG)

  \value CoordinateTypeUtm
         Universal Transverse Mercator (UTM)
 */

/*!
  \enum CoordinateConversionOptions::GarsConversionMode
  \brief Enumerates possible locations of a point relative to a GARS cell.

  \value GarsConversionModeLowerLeft
         Represents a GARS cell by the coordinate of its southwest corner.

  \value GarsConversionModeCenter
         Represents a GARS cell by the coordinates of its center.
 */

/*!
  \enum CoordinateConversionOptions::MgrsConversionMode
  \brief Enumerates the lettering scheme and treatment of coordinates at
         180 degrees longitude when converting MGRS.

  \value MgrsConversionModeAutomatic
         The choice of MGRS lettering scheme is based on the datum and ellipsoid
         of the spatial reference provided. Spatial references with new datums
         (e.g. WGS 84) assume new lettering scheme (AA scheme). This is
         equivalent to MgrsConversionMode::New180InZone60. Spatial references
         with older datums (e.g. Clarke 1866, Bessel 1841, Clarke 1880) assume
         old lettering scheme (AL scheme). This is equivalent to
         MgrsConversionMode::Old180InZone60. When converted, points with
         longitude of exactly 180 degrees are placed in zone 60.

  \value MgrsConversionModeNew180InZone01
         The MGRS notation uses the new lettering scheme (AA scheme) and, when
         converted, places points with longitude of 180 degrees in zone 01.

  \value MgrsConversionModeNew180InZone60
         The MGRS notation uses the new lettering scheme (AA scheme) and, when
         converted, places points with longitude of 180 degrees in zone 60.

  \value MgrsConversionModeOld180InZone01
         The MGRS notation uses the old lettering scheme (AL scheme) and, when
         converted, places points with longitude of 180 degrees in zone 01.

  \value MgrsConversionModeOld180InZone60
         The MGRS notation uses the old lettering scheme (AL scheme) and, when
         converted, places points with longitude of 180 degrees in zone 60.
 */

/*!
  \enum CoordinateConversionOptions::UtmConversionMode
  \brief Enumerates types of latitude designation in UTM notation.

  \value UtmConversionModeLatitudeBandIndicators
         The letter after the UTM zone number represents a latitudinal band
        (\c C through \c X, omitting \c I and \c O).

  \value UtmConversionModeNorthSouthIndicators
         The letter after the UTM zone number represents a hemisphere
         (\c N or \c S).
 */

/*!
  \enum CoordinateConversionOptions::LatitudeLongitudeFormat
  \brief Enumerates supported formats for representing latitude-longitude
  geographical coordinates as a string.

  \value LatitudeLongitudeFormatDecimalDegrees
         The geographical coordinates are represented in decimal degrees.

  \value LatitudeLongitudeFormatDegreesDecimalMinutes
         The geographical coordinates are represented in degrees and decimal
         minutes.

  \value LatitudeLongitudeFormatDegreesMinutesSeconds
         The geographical coordinates are represented in degrees and minutes
         and decimal seconds.
 */


} // Toolkit
} // ArcGISRuntime
} // Esri
