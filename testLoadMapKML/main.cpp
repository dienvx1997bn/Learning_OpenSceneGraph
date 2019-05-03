#include <osgDB/ReadFile>
#include <osgViewer/Viewer>


int main(int argc, char *argv[])
{
    osg::ref_ptr<osg::Group> root = new osg::Group;

//    osg::Node* kml = osgDB::readNodeFile("/home/diennv2/Downloads/doc.kml");
    osg::Node* kml = osgDB::readNodeFile("/home/diennv2/Desktop/DataOSG_3.0/cessna.osg");

    if ( kml ) {
        root->addChild( kml );
    }
    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();
}

