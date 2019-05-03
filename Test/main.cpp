#include <osg/AnimationPath>
#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osgGA/OrbitManipulator>

const float MAPSIZE = 540.0f;

#include <osg/Camera>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/TrackballManipulator>
#include <osgGA/NodeTrackerManipulator>

class FollowUpdater : public osgGA::GUIEventHandler
{
public:
FollowUpdater( osg::Node* node ) : _target(node) {}
virtual bool handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa ) {
    osgViewer::View* view = static_cast<osgViewer::View*>(&aa);
    if ( !view || !_target ||
    ea.getEventType()!=osgGA::GUIEventAdapter::FRAME ) return false;
    osgGA::OrbitManipulator* orbit =
    dynamic_cast<osgGA::OrbitManipulator*>( view->
    getCameraManipulator() );
    if ( orbit )
    {
    osg::Matrix matrix = computeTargetToWorldMatrix(
    _target.get() );

    osg::Vec3d targetCenter = _target->getBound().center() *
    matrix;
    orbit->setCenter( targetCenter );
    }
    return false;
}

osg::Matrix computeTargetToWorldMatrix( osg::Node* node ) const
{
osg::Matrix l2w;
if ( node && node->getNumParents()>0 )
{
osg::Group* parent = node->getParent(0);
l2w = osg::computeLocalToWorld( parent->
getParentalNodePaths()[0] );
}
return l2w;
}
protected:
osg::observer_ptr<osg::Node> _target;
};



osg::AnimationPath* createAnimationPath( float radius, float time, float x, float y)
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
        osg::Vec3 pos( x + sinf(yaw)*radius, y + cosf(yaw)*radius, 0.0f );
        osg::Quat rot( -yaw, osg::Z_AXIS );
        path->insert( delta_time * (float)i,osg::AnimationPath::ControlPoint(pos, rot));
    }
    return path.release();
}

int main(int argc, char **argv)
{

    osg::ref_ptr<osg::Node> var[1000];
    osg::ref_ptr<osg::Node> var2[1000];

    osg::ref_ptr<osg::MatrixTransform> transform[1000];
    osg::ref_ptr<osg::MatrixTransform> transform2[1000];
    osg::ref_ptr<osg::AnimationPathCallback> apcb[1000];

    osg::ref_ptr<osg::Group> root = new osg::Group;

    int i, j;
    int n = atoi(argv[1]);
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            //add map
            var[i] = osgDB::readNodeFile("/home/dien/Desktop/DataOSG_3.0/lz.osg");

            transform[i] = new osg::MatrixTransform;
            transform[i]->setMatrix( osg::Matrix::translate(i*MAPSIZE, j*MAPSIZE, -200.0f) );
            transform[i]->addChild( var[i].get() );
            root->addChild(transform[i].get());

            //add object
//            var2[i] = osgDB::readNodeFile("/home/dien/Desktop/DataOSG_3.0/cessna.osg" );
            var2[i] = osgDB::readNodeFile("/home/dien/Desktop/DataOSG_3.0/cessna.osg.0,0,90.rot" );

            transform2[i] = new osg::MatrixTransform;

            apcb[i] = new osg::AnimationPathCallback;
                apcb[i]->setAnimationPath( createAnimationPath(50.0f, 6.0f, i*MAPSIZE, j*MAPSIZE) );
                transform2[i]->setUpdateCallback( apcb[i].get() );

            transform2[i]->addChild( var2[i].get() );
            root->addChild(transform2[i].get());
        }

    }


    /*follow models
    osg::ref_ptr<osgGA::NodeTrackerManipulator> nodeTracker = new
    osgGA::NodeTrackerManipulator;
    nodeTracker->setHomePosition( osg::Vec3(0, 20.0, 0.0),
    osg::Vec3(), osg::Z_AXIS );
    nodeTracker->setTrackerMode( osgGA::NodeTrackerManipulator::NODE_CENTER_AND_ROTATION );
    nodeTracker->setRotationMode(
    osgGA::NodeTrackerManipulator::TRACKBALL );
    nodeTracker->setTrackNode( var2[4] );

    osg::ref_ptr<osgGA::KeySwitchMatrixManipulator> keySwitch = new
    osgGA::KeySwitchMatrixManipulator;
    keySwitch->addMatrixManipulator( '1', "Trackball", new
    osgGA::TrackballManipulator );
    keySwitch->addMatrixManipulator( '2', "NodeTracker",
    nodeTracker.get() );
    */



    osgViewer::Viewer viewer;

    //follow models
    //viewer.setCameraManipulator( keySwitch.get() );
    viewer.setSceneData( root.get() );
    return viewer.run();
}

