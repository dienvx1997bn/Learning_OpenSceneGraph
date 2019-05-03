#include <osg/Switch>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

int main(int argc, char *argv[])
{
    osg::ref_ptr<osg::Node> model1= osgDB::readNodeFile("/home/diennv2/Desktop/DataOSG_3.0/cessna.osg");
    osg::ref_ptr<osg::Node> model2= osgDB::readNodeFile("/home/diennv2/Desktop/DataOSG_3.0/cessnafire.osg");

    osg::ref_ptr<osg::Switch> root = new osg::Switch;
    root->addChild( model1.get(), false );
    root->addChild( model2.get(), true );

    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();


}

