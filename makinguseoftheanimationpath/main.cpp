#include <osg/AnimationPath>
#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>


#include <osgEarth/Map>
#include <osgEarth/MapNode>
#include <osgEarthDrivers/tms/TMSOptions>
#include <osgEarthDrivers/gdal/GDALOptions>
using namespace osgEarth;
using namespace osgEarth::Drivers;

osg::AnimationPath* createAnimationPath( float radius, float time)
{
osg::ref_ptr<osg::AnimationPath> path = new
osg::AnimationPath;
path->setLoopMode( osg::AnimationPath::LOOP );
unsigned int numSamples = 32;
float delta_yaw = 2.0f * osg::PI / ((float)numSamples - 1.0f);
float delta_time = time / (float)numSamples;
for ( unsigned int i=0; i<numSamples; ++i )
{
float yaw = delta_yaw * (float)i;
osg::Vec3 pos( sinf(yaw)*radius, cosf(yaw)*radius, 0.0f );
osg::Quat rot( -yaw, osg::Z_AXIS );
path->insert( delta_time * (float)i,osg::AnimationPath::ControlPoint(pos, rot));
}
return path.release();
}

int main(int argc, char **argv) {
    osg::ref_ptr<osg::Node> model =
    osgDB::readNodeFile( "/home/diennv2/Desktop/DataOSG_3.0/cessna.osg.0,0,90.rot" );
    osg::ref_ptr<osg::MatrixTransform> root = new
    osg::MatrixTransform;
    root->addChild( model.get() );

    osg::ref_ptr<osg::AnimationPathCallback> apcb = new
    osg::AnimationPathCallback;
    apcb->setAnimationPath( createAnimationPath(50.0f, 6.0f) );
    root->setUpdateCallback( apcb.get() );



    ///
    /// \brief viewer
    ///
    // Load the map
    osg::Node* loadedModel = osgDB::readNodeFile("/home/diennv2/Desktop/osgearth/tests/vertical_scale.earth");


    root->addChild( loadedModel );




    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    return viewer.run();
}

