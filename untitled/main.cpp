#include <osg/AnimationPath>
#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>


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
osg::Vec3 pos( sinf(yaw)*radius, cosf(yaw)*radius, 400.0f );
osg::Quat rot( -yaw, osg::Z_AXIS );
path->insert( delta_time * (float)i,osg::AnimationPath::ControlPoint(pos, rot));
}
return path.release();
}

int main(int argc, char *argv[])
{
    osg::ref_ptr<osg::Node> model = osgDB::readNodeFile("/home/dien/Desktop/DataOSG_3.0/lz.osg");
    osg::ref_ptr<osg::Node> hud_model = osgDB::readNodeFile("/home/dien/Desktop/DataOSG_3.0/cessna.osg" );

    osg::ref_ptr<osg::MatrixTransform> transform1 = new osg::MatrixTransform;
    transform1->setMatrix( osg::Matrix::translate(
    0.0f, 0.0f, 400.0f) );
    transform1->addChild( hud_model.get() );

    osg::ref_ptr<osg::AnimationPathCallback> apcb = new osg::AnimationPathCallback;
    apcb->setAnimationPath( createAnimationPath(50.0f, 6.0f) );
    transform1->setUpdateCallback( apcb.get() );

    osg::ref_ptr<osg::Group> root = new osg::Group;
    root->addChild( model.get() );
//    root->addChild(transform1.get());

    osgViewer::Viewer viewer;
    viewer.setSceneData( root.get() );
    viewer.setCameraManipulator( new osgGA::TrackballManipulator );
    return viewer.run();
}


