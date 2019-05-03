#include <osgEarth/Map>
#include <osgEarth/MapNode>
#include <osgEarthDrivers/tms/TMSOptions>
#include <osgEarthDrivers/gdal/GDALOptions>
#include <osg/ref_ptr>
#include <osg/Referenced>
#include <iostream>
#include <osgViewer/Viewer>

using namespace osgEarth;
using namespace osgEarth::Drivers;

int main(int argc, char** argv) {
    osg::ref_ptr<osg::Node> root = osgDB::readNodeFile("/home/diennv2/Desktop/DataOSG_3.0/cessna.osg/cessna.osg");
    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();
}
